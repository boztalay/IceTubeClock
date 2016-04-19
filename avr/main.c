#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

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
    {0, 0, 1, 1, 1, 1, 0, 1}, // 9
};

// Globals for what each tube is displaying

int8_t tube0Number;
int8_t tube1Number;
int8_t tube2Number;
int8_t tube3Number;

// Function declarations

void setUpSystemClock(void);

void setUpTubeDriverInterface(void);
void waitForTubeWarmup(void);

void updateTubes(void);
void sendBitsToTubeDriversToDisplayNumber(int8_t);
void sendBitToTubeDrivers(uint8_t);
void latchTubeDrivers(void);

// Main

int main(void) {
	setUpSystemClock();
	setUpTubeDriverInterface();

	waitForTubeWarmup();

    tube0Number = 0;
    tube1Number = 0;
    tube2Number = 0;
    tube3Number = 0;

	while(1) {
        _delay_ms(500);

        tube0Number++;
        tube1Number++;
        tube2Number++;
        tube3Number++;

        if(tube0Number > 10) {
            tube0Number = 0;
            tube1Number = 0;
            tube2Number = 0;
            tube3Number = 0;
        }

        updateTubes();
	}
}

void setUpSystemClock() {
	// Notify it that we want to change the prescaler
	CLKPR = _BV(CLKPCE);

	// Set the prescaler to 1 (should give us 8MHz)
	CLKPR = 0x00;
}

void setUpTubeDriverInterface() {
	// Pins
	// PORTB.4	DIN
	// PORTB.3	LOAD
	// PORTB.2	CLK
	// PORTB.1	BLANK
	
	// Set up all of the interface pins as output, outputs to 0
	PORTB = 0x00;
	DDRB = _BV(DDB4) | _BV(DDB3) | _BV(DDB2) | _BV(DDB1);
}

void waitForTubeWarmup() {
	_delay_ms(1000);
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

