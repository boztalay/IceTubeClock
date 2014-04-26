#include <avr/io.h>

#define BOOST_DEFAULT_DUTY 130 //About 50.9%
#define BOOST_TARGET 935 //Should be regulating it to about 56 volts
#define BOOST_LIMIT 10

void setUpSystemClock(void);

void setUpBoostSupplyPWM(void);
void setBoostSupplyDutyCycle(uint8_t);
void setUpBoostSupplyVoltageMonitor(void);
void process_boostSupplyVoltageMonitor(void);
uint16_t getBoostSupplyVoltage(void);

int main(void) {
	setUpSystemClock();

	setUpBoostSupplyPWM();
	setUpBoostSupplyVoltageMonitor();

	while(1) {
		process_boostSupplyVoltageMonitor();
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

void process_boostSupplyVoltageMonitor() {
	static uint16_t callsSinceLastCheck = 0; //Remember static variables only get initialized once
	static uint8_t currentDutyCycle = BOOST_DEFAULT_DUTY;

	callsSinceLastCheck++;
	if(callsSinceLastCheck > 1000) {
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
