#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Drivers are connected to the tubes like so:
// OUT0	NC
// OUT1     Tube 0 A
// OUT2     Tube 0 B
// OUT3     Tube 0 C
// OUT4     Tube 0 D
// OUT5     Tube 0 E
// OUT6     Tube 0 F
// OUT7     Tube 0 G
// OUT8     Tube 0 H
// OUT9     Tube 0 GRID
// OUT10    Tube 1 A
// OUT11    Tube 1 B
// OUT12    Tube 1 C
// OUT13    Tube 1 D
// OUT14    Tube 1 E
// OUT15    Tube 1 F
// OUT16    Tube 1 G
// OUT17    Tube 1 H
// OUT18    Tube 1 GRID
// OUT19    NC
// OUT0     NC
// OUT1     Tube 2 A
// OUT2     Tube 2 B
// OUT3     Tube 2 C
// OUT4     Tube 2 D
// OUT5     Tube 2 E
// OUT6     Tube 2 F
// OUT7     Tube 2 G
// OUT8     Tube 2 H
// OUT9     Tube 2 GRID
// OUT10    Tube 3 A
// OUT11    Tube 3 B
// OUT12    Tube 3 C
// OUT13    Tube 3 D
// OUT14    Tube 3 E
// OUT15    Tube 3 F
// OUT16    Tube 3 G
// OUT17    Tube 3 H
// OUT18    Tube 3 GRID
// OUT19    NC

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

// Globals for what each tube is displaying

int8_t tube0Number;
int8_t tube1Number;
int8_t tube2Number;
int8_t tube3Number;

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

void setUpTubeDriverInterface(void);
void waitForTubeWarmup(void);

void setUpRealTimeClock(void);
void updateTime(void);

void updateTubes(void);
void sendBitsToTubeDriversToDisplayNumber(int8_t);
void sendBitToTubeDrivers(uint8_t);
void latchTubeDrivers(void);

// Main

int main(void) {
	setUpSystemClock();
    setUpKnobInterface();
	setUpTubeDriverInterface();

	waitForTubeWarmup();

    tube0Number = -1;
    tube1Number = 0;
    tube2Number = 0;
    tube3Number = 0;

    setUpRealTimeClock();

    updateTubes();

	while(1) {
        checkKnobs();
	}
}

void setUpSystemClock() {
	// Notify it that we want to change the prescaler
	CLKPR = _BV(CLKPCE);

	// Set the prescaler to 1 (should give us 8MHz)
	CLKPR = 0x00;
}

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
        tube1Number++;

        if(tube0Number == 1) {
            if(tube1Number > 2) {
                tube1Number = 0;
                tube0Number = -1; // Blank
            }
        } else {
            if(tube1Number > 9) {
                tube1Number = 0;
                tube0Number = 1;
            }
        }
    } else if(hourKnobMovement == DECREMENT) {
        tube1Number--;

        if(tube1Number < 0) {
            if(tube0Number == -1) {
                tube0Number = 1;
                tube1Number = 2;
            } else {
                tube0Number = -1;
                tube1Number = 9;
            }
        }
    }

    if(minuteKnobMovement == INCREMENT) {
        tube3Number++;

        if(tube3Number > 9) {
            tube3Number = 0;
            tube2Number++;

            if(tube2Number > 5) {
                tube2Number = 0;
            }
        }
    } else if(minuteKnobMovement == DECREMENT) {
        tube3Number--;

        if(tube3Number < 0) {
            tube3Number = 9;
            tube2Number--;

            if(tube2Number < 0) {
                tube2Number = 5;
            }
        }
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
    if(knobState->channelAEdge == RISING) {
        return (knobState->channelB == 1) ? INCREMENT : DECREMENT;
    } else if(knobState->channelAEdge == FALLING) {
        return (knobState->channelB == 0) ? INCREMENT : DECREMENT;
    }

    if(knobState->channelBEdge == RISING) {
        return (knobState->channelA == 0) ? INCREMENT : DECREMENT;
    } else if(knobState->channelBEdge == FALLING) {
        return (knobState->channelA == 1) ? INCREMENT : DECREMENT;
    }

    return NONE;
}

void setUpTubeDriverInterface() {
	// Pins
	// PORTB.4	DIN
	// PORTB.3	LOAD
	// PORTB.2	CLK
	// PORTB.1	BLANK

	// Set up all of the interface pins as output, outputs to 0
	DDRB = _BV(DDB4) | _BV(DDB3) | _BV(DDB2) | _BV(DDB1);
	PORTB = 0x00;
}

void waitForTubeWarmup() {
	_delay_ms(1000);
}

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
        /*updateTime();*/
    }
    updateTime();
}

void updateTime() {
    tube3Number++;

    if(tube3Number > 9) {
        tube3Number = 0;
        tube2Number++;

        if(tube2Number > 5) {
            tube2Number = 0;
            tube1Number++;

            if(tube0Number == 1) {
                if(tube1Number > 2) {
                    tube1Number = 0;
                    tube0Number = -1; // Blank
                }
            } else {
                if(tube1Number > 9) {
                    tube1Number = 0;
                    tube0Number = 1;
                }
            }
        }
    }

    updateTubes();
}

void updateTubes() {
	sendBitToTubeDrivers(1);	// Tube 3 GRID

    sendBitsToTubeDriversToDisplayNumber(tube3Number);

	sendBitToTubeDrivers(1);	// Tube 2 GRID

    sendBitsToTubeDriversToDisplayNumber(tube2Number);

	sendBitToTubeDrivers(0);	// NC
	sendBitToTubeDrivers(0);	// NC

	sendBitToTubeDrivers(1);	// Tube 1 GRID

    sendBitsToTubeDriversToDisplayNumber(tube1Number);

	sendBitToTubeDrivers(1);	// Tube 0 GRID

    sendBitsToTubeDriversToDisplayNumber(tube0Number);

	sendBitToTubeDrivers(0);	// NC, need it to push everything up

	latchTubeDrivers();
}

void sendBitsToTubeDriversToDisplayNumber(int8_t number) {
    if(number < 0 || number > 9) {
        for(uint8_t i = 0; i < 8; i++) {
            sendBitToTubeDrivers(0);
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
		PORTB &= ~_BV(PINB4);
	} else {
		// Set DIN to 1
		PORTB |= _BV(PINB4);
	}

	// Toggle the clock, 1 then 0
	PORTB |= _BV(PINB2);
	PORTB &= ~_BV(PINB2);
}

void latchTubeDrivers() {
	// Toggle LATCH, 1 then 0
	PORTB |= _BV(PINB3);
	PORTB &= ~_BV(PINB3);
}

