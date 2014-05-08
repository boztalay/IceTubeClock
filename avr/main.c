#include <avr/io.h>
#include <util/delay.h>

#define BOOST_DEFAULT_DUTY 180 //About 70.6%
#define BOOST_TARGET 935 //Should be regulating it to about 56 volts
#define BOOST_LIMIT 10

void setUpSystemClock(void);

void setUpBoostSupplyPWM(void);
void setBoostSupplyDutyCycle(uint8_t);
void setUpBoostSupplyVoltageMonitor(void);
void setUpTubeDriverInterface(void);

void waitForTubeWarmup(void);

void process_boostSupplyVoltageMonitor(void);
uint16_t getBoostSupplyVoltage(void);

void sendBitToTubeDrivers(uint8_t);
void latchTubeDrivers(void);

int main(void) {
	setUpSystemClock();

	setUpBoostSupplyPWM();
	setUpBoostSupplyVoltageMonitor();
	setUpTubeDriverInterface();

	waitForTubeWarmup();

	//Drivers are connected to the tubes like so:
	//OUT0	NC
	//OUT1	Tube 0 A
	//OUT2	Tube 0 B
	//OUT3	Tube 0 C
	//OUT4	Tube 0 D
	//OUT5	Tube 0 E
	//OUT6	Tube 0 F
	//OUT7	Tube 0 G
	//OUT8	Tube 0 H
	//OUT9	Tube 0 GRID
	//OUT10	Tube 1 A
	//OUT11	Tube 1 B
	//OUT12	Tube 1 C
	//OUT13	Tube 1 D
	//OUT14	Tube 1 E
	//OUT15	Tube 1 F
	//OUT16	Tube 1 G
	//OUT17	Tube 1 H
	//OUT18	Tube 1 GRID
	//OUT19	NC
	//OUT0	NC
	//OUT1	Tube 2 A
	//OUT2	Tube 2 B
	//OUT3	Tube 2 C
	//OUT4	Tube 2 D
	//OUT5	Tube 2 E
	//OUT6	Tube 2 F
	//OUT7	Tube 2 G
	//OUT8	Tube 2 H
	//OUT9	Tube 2 GRID
	//OUT10	Tube 3 A
	//OUT11	Tube 3 B
	//OUT12	Tube 3 C
	//OUT13	Tube 3 D
	//OUT14	Tube 3 E
	//OUT15	Tube 3 F
	//OUT16	Tube 3 G
	//OUT17	Tube 3 H
	//OUT18	Tube 3 GRID
	//OUT19	NC

	sendBitToTubeDrivers(1);	//Tube 3 GRID
	sendBitToTubeDrivers(1);	//Tube 3 H
	sendBitToTubeDrivers(0);	//Tube 3 G
	sendBitToTubeDrivers(1);	//Tube 3 F
	sendBitToTubeDrivers(0);	//Tube 3 E
	sendBitToTubeDrivers(1);	//Tube 3 D
	sendBitToTubeDrivers(1);	//Tube 3 C
	sendBitToTubeDrivers(0);	//Tube 3 B
	sendBitToTubeDrivers(0);	//Tube 3 A
	sendBitToTubeDrivers(1);	//Tube 2 GRID
	sendBitToTubeDrivers(0);	//Tube 2 H
	sendBitToTubeDrivers(0);	//Tube 2 G
	sendBitToTubeDrivers(1);	//Tube 2 F
	sendBitToTubeDrivers(1);	//Tube 2 E
	sendBitToTubeDrivers(1);	//Tube 2 D
	sendBitToTubeDrivers(0);	//Tube 2 C
	sendBitToTubeDrivers(1);	//Tube 2 B
	sendBitToTubeDrivers(1);	//Tube 2 A
	sendBitToTubeDrivers(0);	//NC
	sendBitToTubeDrivers(0);	//NC
	sendBitToTubeDrivers(1);	//Tube 1 GRID
	sendBitToTubeDrivers(0);	//Tube 1 H
	sendBitToTubeDrivers(0);	//Tube 1 G
	sendBitToTubeDrivers(1);	//Tube 1 F
	sendBitToTubeDrivers(1);	//Tube 1 E
	sendBitToTubeDrivers(1);	//Tube 1 D
	sendBitToTubeDrivers(0);	//Tube 1 C
	sendBitToTubeDrivers(1);	//Tube 1 B
	sendBitToTubeDrivers(1);	//Tube 1 A
	sendBitToTubeDrivers(1);	//Tube 0 GRID
	sendBitToTubeDrivers(1);	//Tube 0 H
	sendBitToTubeDrivers(0);	//Tube 0 G
	sendBitToTubeDrivers(1);	//Tube 0 F
	sendBitToTubeDrivers(0);	//Tube 0 E
	sendBitToTubeDrivers(1);	//Tube 0 D
	sendBitToTubeDrivers(1);	//Tube 0 C
	sendBitToTubeDrivers(0);	//Tube 0 B
	sendBitToTubeDrivers(0);	//Tube 0 A
	sendBitToTubeDrivers(0);	//NC, need it to push everything up
	latchTubeDrivers();

	while(1) {
//		process_boostSupplyVoltageMonitor();
	}
}

void setUpSystemClock() {
	//Notify it that we want to change the prescaler
	CLKPR = _BV(CLKPCE);

	//Set the prescaler to 1 (should give us 8MHz)
	CLKPR = 0x00;
}

void setUpBoostSupplyPWM() {
	//Set up PORTD.6 as our PWM output, which is for OC0A
	PORTD = 0x00;
	DDRD = _BV(DDD6);

	//Set up Timer0 OC0A for Phase-Correct Non-Inverted PWM
	TCCR0A = _BV(COM0A1) | _BV(WGM00);

	//Set the clk_io prescaler to 1, so we should get about 16KHz
	TCCR0B = _BV(CS00);

	//Set the boost supply to the default duty cycle
	setBoostSupplyDutyCycle(BOOST_DEFAULT_DUTY);
}

void setBoostSupplyDutyCycle(uint8_t dutyCycle) {
	//Set the PWM output compare register to the duty cycle value
	//Actual duty cycle should be dutyCycle / 255
	OCR0A = dutyCycle;
}

void setUpBoostSupplyVoltageMonitor() {
	//Enable the ADC and set its clock prescaler to 128
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
}

void setUpTubeDriverInterface() {
	//Pins
	//PORTB.4	DIN
	//PORTB.3	LOAD
	//PORTB.2	CLK
	//PORTB.1	BLANK
	
	//Driver is connected to the tube like so:
	//OUT0	NC
	//OUT1	Tube 0 A
	//OUT2	Tube 0 B
	//OUT3	Tube 0 C
	//OUT4	Tube 0 D
	//OUT5	Tube 0 E
	//OUT6	Tube 0 F
	//OUT7	Tube 0 G
	//OUT8	Tube 0 H
	//OUT9	Tube 0 GRID
	//OUT10	Tube 1 A
	//OUT11	Tube 1 B
	//OUT12	Tube 1 C
	//OUT13	Tube 1 D
	//OUT14	Tube 1 E
	//OUT15	Tube 1 F
	//OUT16	Tube 1 G
	//OUT17	Tube 1 H
	//OUT18	Tube 1 GRID
	//OUT19	NC
	
	//Set up all of the interface pins as output, outputs to 0
	PORTB = 0x00;
	DDRB = _BV(DDB4) | _BV(DDB3) | _BV(DDB2) | _BV(DDB1);
}

void waitForTubeWarmup() {
	_delay_ms(500);
}

void process_boostSupplyVoltageMonitor() {
	static uint16_t callsSinceLastCheck = 0; //Remember static variables only get initialized once
	static uint8_t currentDutyCycle = BOOST_DEFAULT_DUTY;

	callsSinceLastCheck++;
	if(callsSinceLastCheck > 25000) {
		uint16_t boostVoltage = getBoostSupplyVoltage();
		
		if(boostVoltage > BOOST_TARGET + BOOST_LIMIT) {
			currentDutyCycle--;
		} else if(boostVoltage < BOOST_TARGET - BOOST_LIMIT) {
			currentDutyCycle++;
		}

		setBoostSupplyDutyCycle(currentDutyCycle);
		callsSinceLastCheck = 0;
	}
}

uint16_t getBoostSupplyVoltage() {
	//Select channel 0 to read from
	ADMUX = (ADMUX & 0xF0);

	//Start the conversion
	ADCSRA |= _BV(ADSC);

	//Wait for the conversion to finish
	while(!bit_is_set(ADCSRA, ADIF)) { }

	//Clear ADIF
	ADCSRA |= _BV(ADIF);

	//ADC holds our value
	return ADC;
}

void sendBitToTubeDrivers(uint8_t bit) {
	//Set DIN according to the bit
	if(bit == 0) {
		//Set DIN to 0
		PORTB &= ~_BV(PINB4);
	} else {
		//Set DIN to 1
		PORTB |= _BV(PINB4);
	}

	//Toggle the clock, 1 then 0
	PORTB |= _BV(PINB2);
	PORTB &= ~_BV(PINB2);
}

void latchTubeDrivers() {
	//Toggle LATCH, 1 then 0
	PORTB |= _BV(PINB3);
	PORTB &= ~_BV(PINB3);
}
