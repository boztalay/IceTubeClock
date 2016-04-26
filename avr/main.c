#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// NOTE: Programming command is of the form
//  avrdude -p m168 -P /dev/cu.usbmodem14111 -c avrisp -b 19200 -U flash:w:main.hex

// Patterns for each number on the tubes

uint8_t numberPatterns[10][8] = {
  // A  B  C  D  E  F  G  H
    {1, 1, 1, 0, 1, 1, 0, 1}, // 0
    {0, 0, 0, 0, 0, 1, 0, 1}, // 1
    {1, 1, 0, 1, 1, 1, 0, 0}, // 2
    {1, 0, 0, 1, 1, 1, 0, 1}, // 3
    {0, 0, 1, 1, 0, 1, 0, 1}, // 4
    {1, 0, 1, 1, 1, 0, 0, 1}, // 5
    {1, 1, 1, 1, 1, 0, 0, 1}, // 6
    {0, 0, 0, 0, 1, 1, 0, 1}, // 7
    {1, 1, 1, 1, 1, 1, 0, 1}, // 8
    {1, 0, 1, 1, 1, 1, 0, 1}, // 9
};

// Globals for keeping track of the current time

int8_t hours;
int8_t minutes;

// Global to keep track of how many seconds
// have passed

uint8_t secondsPassed;

// Struct and globals to keep track of the state
// of the hour and minute knobs

typedef enum {
    NONE,
    INCREMENT,
    DECREMENT
} KnobMovement;

typedef enum {
    NO_EDGE,
    RISING,
    FALLING
} KnobChannelEdge;

typedef struct {
    uint8_t lastChannelA;
    uint8_t channelA;
    KnobChannelEdge channelAEdge;

    uint8_t lastChannelB;
    uint8_t channelB;
    KnobChannelEdge channelBEdge;
} KnobState;

KnobState hourKnobState;
KnobState minuteKnobState;

// Function declarations

void setUpSystemClock(void);

void setUpKnobInterface(void);
void readKnobs(void);
void checkKnobs(void);
void checkKnobStateForEdges(KnobState*);
KnobMovement checkKnobStateForMovement(KnobState*);

void setUpRealTimeClock(void);
void updateTime(void);
void incrementTime(void);
uint8_t incrementMinutes(void);
uint8_t incrementHours(void);
uint8_t decrementMinutes(void);
uint8_t decrementHours(void);


void setUpTubeDriverInterface(void);
void waitForTubeWarmup(void);
void updateTubes(void);
void sendBitsToTubeDriversToDisplayNumber(int8_t, uint8_t);
void sendBitToTubeDrivers(uint8_t);
void latchTubeDrivers(void);

// Main

int main(void) {
	setUpSystemClock();
    setUpKnobInterface();
	setUpTubeDriverInterface();

	waitForTubeWarmup();

    hours = 12;
    minutes = 0;

    setUpRealTimeClock();

    updateTubes();

	while(1) {
        _delay_ms(3); // Quick and dirty debounce on the knobs
        checkKnobs();
	}
}

// Initialization

void setUpSystemClock() {
	// Notify it that we want to change the prescaler
	CLKPR = _BV(CLKPCE);

	// Set the prescaler to 1 (should give us 8MHz)
	CLKPR = 0x00;
}

// Interfacing with the hour and minute adjustment knobs

void setUpKnobInterface() {
    // Pins
    // PORTC.0  Hour Knob A
    // PORTC.1  Hour Knob B
    // PORTC.2  Minute Knob A
    // PORTC.3  Minute Knob B

    // Set up all of the interface pins as inputs with no pull-up resistors
    DDRC = 0x00;
    PORTC = 0x00;

    // Take an initial reading of the knobs
    readKnobs();
}

void readKnobs() {
    // Copy the current states over into the last states
    hourKnobState.lastChannelA = hourKnobState.channelA;
    hourKnobState.lastChannelB = hourKnobState.channelB;
    minuteKnobState.lastChannelA = minuteKnobState.channelA;
    minuteKnobState.lastChannelB = minuteKnobState.channelB;

    // Read the current states
    hourKnobState.channelA = (PINC & _BV(PINC0)) ? 1 : 0;
    hourKnobState.channelB = (PINC & _BV(PINC1)) ? 1 : 0;
    minuteKnobState.channelA = (PINC & _BV(PINC2)) ? 1 : 0;
    minuteKnobState.channelB = (PINC & _BV(PINC3)) ? 1 : 0;
}

void checkKnobs() {
    // First read the current state of the knob pins
    readKnobs();

    // Check if any of the knob pins have changed state
    checkKnobStateForEdges(&hourKnobState);
    checkKnobStateForEdges(&minuteKnobState);

    // Check if either of the knobs have registered movement
    KnobMovement hourKnobMovement = checkKnobStateForMovement(&hourKnobState);
    KnobMovement minuteKnobMovement = checkKnobStateForMovement(&minuteKnobState);

    // Handle increments and decrements accordingly
    // This is gross, needs to be redone

    if(hourKnobMovement == INCREMENT) {
        incrementHours();
        updateTubes();
    } else if(hourKnobMovement == DECREMENT) {
        decrementHours();
        updateTubes();
    }

    if(minuteKnobMovement == INCREMENT) {
        incrementMinutes();
        updateTubes();
    } else if(minuteKnobMovement == DECREMENT) {
        decrementMinutes();
        updateTubes();
    }
}

void checkKnobStateForEdges(KnobState* knobState) {
    if(knobState->lastChannelA != knobState->channelA) {
        knobState->channelAEdge = (knobState->channelA == 1) ? RISING : FALLING;
    } else {
        knobState->channelAEdge = NO_EDGE;
    }

    if(knobState->lastChannelB != knobState->channelB) {
        knobState->channelBEdge = (knobState->channelB == 1) ? RISING : FALLING;
    } else {
        knobState->channelBEdge = NO_EDGE;
    }
}

KnobMovement checkKnobStateForMovement(KnobState* knobState) {
    // Not doing classic quadrature decoding so that I can tune
    // the feel of the knobs for incrementing and decrementing.
    // Different parts of the quadrature cycle match the detents
    // on the knobs for incrementing or decrementing.

    if(knobState->channelAEdge == RISING && knobState->channelB == 1) {
        return DECREMENT;
    }
    if(knobState->channelBEdge == RISING && knobState->channelA == 1) {
        return INCREMENT;
    }

    return NONE;
}

// Keeping track of time

void setUpRealTimeClock() {
    // Set up Timer 2 to use an external clock source
    // and a prescaler of 128, which gives 1 overflow
    // interrupt per second
    TCCR2A = 0x00;
    TCCR2B = 0x05;

    // Clear Timer 2's counter
    TCNT2 = 0;

    // Enable the overflow interrupt
    TIMSK2 |= 0x01;

    // Enable asynchronous mode for the timer
    ASSR = 0x20;

    // Reset the seconds counter
    secondsPassed = 0;

    // Enable global interrupts
    sei();
}

ISR(TIMER2_OVF_vect) {
    // Happens once per second
    secondsPassed++;

    if(secondsPassed >= 60) {
        secondsPassed = 0;
        updateTime();
    }
}

void updateTime() {
    incrementTime();
    updateTubes();
}

void incrementTime() {
    uint8_t minutesOverflow = incrementMinutes();
    if(minutesOverflow == 1) {
        incrementHours();
    }
}

uint8_t incrementMinutes() {
    minutes++;

    if(minutes > 59) {
        minutes = 0;
        return 1;
    } else {
        return 0;
    }
}

uint8_t incrementHours() {
    hours++;

    if(hours > 12) {
        hours = 1;
        return 1;
    } else {
        return 0;
    }
}

uint8_t decrementMinutes() {
    minutes--;

    if(minutes < 0) {
        minutes = 59;
        return 1;
    } else {
        return 0;
    }
}

uint8_t decrementHours() {
    hours--;

    if(hours < 1) {
         hours = 12;
         return 1;
    } else {
         return 0;
    }
}

// Interfacing with the tube drivers

// Drivers are connected to the tubes like so:
// OUT0     Tube 0 A
// OUT1     Tube 0 B
// OUT2     Tube 0 C
// OUT3     Tube 0 D
// OUT4     Tube 0 E
// OUT5     Tube 0 F
// OUT6     Tube 0 G
// OUT7     Tube 0 H
// OUT8     Tube 1 A
// OUT9     Tube 1 B
// OUT10    Tube 1 C
// OUT11    Tube 1 D
// OUT12    Tube 1 E
// OUT13    Tube 1 F
// OUT14    Tube 1 G
// OUT15    Tube 1 H
// OUT16    NC
// OUT17    NC
// OUT18    NC
// OUT19    NC
// OUT0     Tube 3 H
// OUT1     Tube 3 G
// OUT2     Tube 3 F
// OUT3     Tube 3 E
// OUT4     Tube 3 D
// OUT5     Tube 3 C
// OUT6     Tube 3 B
// OUT7     Tube 3 A
// OUT8     Tube 2 H
// OUT9     Tube 2 G
// OUT10    Tube 2 F
// OUT11    Tube 2 E
// OUT12    Tube 2 D
// OUT13    Tube 2 C
// OUT14    Tube 2 B
// OUT15    Tube 2 A
// OUT16    NC
// OUT17    NC
// OUT18    NC
// OUT19    NC

void setUpTubeDriverInterface() {
	// Pins     PCB         Breadboard
	// PORTB.4	CLK         (DIN)
	// PORTB.3	DIN         (LOAD)
	// PORTB.2	LOAD        (CLK)
	// PORTB.1	BLANK       (BLANK)

	// Set up all of the interface pins as output, outputs to 0
	DDRB = _BV(DDB4) | _BV(DDB3) | _BV(DDB2) | _BV(DDB1);
	PORTB = 0x00;
}

void waitForTubeWarmup() {
	_delay_ms(1000);
}

void updateTubes() {
    int8_t hoursTensDigit = hours / 10;
    int8_t hoursOnesDigit = hours - (hoursTensDigit * 10);
    int8_t minutesTensDigit = minutes / 10;
    int8_t minutesOnesDigit = minutes - (minutesTensDigit * 10);

    if(hoursTensDigit == 0) {
        // Blank the hours tens digit if it's 0
        hoursTensDigit = -1;
    }

	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC

    sendBitsToTubeDriversToDisplayNumber(minutesTensDigit, 0);
    sendBitsToTubeDriversToDisplayNumber(minutesOnesDigit, 0);

	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC

    sendBitsToTubeDriversToDisplayNumber(hoursOnesDigit, 1);
    sendBitsToTubeDriversToDisplayNumber(hoursTensDigit, 1);

	latchTubeDrivers();
}

void sendBitsToTubeDriversToDisplayNumber(int8_t number, uint8_t direction) {
    if(number < 0 || number > 9) {
        for(uint8_t i = 0; i < 8; i++) {
            sendBitToTubeDrivers(0);
        }
    } else if(direction == 0) {
        for(int8_t i = 0; i < 8; i++) {
            sendBitToTubeDrivers(numberPatterns[number][i]);
        }
    } else {
        for(int8_t i = 7; i >= 0; i--) {
            sendBitToTubeDrivers(numberPatterns[number][i]);
        }
    }
}

void sendBitToTubeDrivers(uint8_t bit) {
	// Set DIN according to the bit
	if(bit == 0) {
		// Set DIN to 0
		PORTB &= ~_BV(PINB3);
	} else {
		// Set DIN to 1
		PORTB |= _BV(PINB3);
	}

	// Toggle the clock, 1 then 0
	PORTB |= _BV(PINB4);
	PORTB &= ~_BV(PINB4);
}

void latchTubeDrivers() {
	// Toggle LATCH, 1 then 0
	PORTB |= _BV(PINB2);
	PORTB &= ~_BV(PINB2);
}

