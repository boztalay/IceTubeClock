#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
	// Set up the system clock
	// First, tell it we want to change the prescaler
	CLKPR = 0x80;
	// Then, set the prescaler to 1 (should give us 8MHz)
	CLKPR = 0x00;

	PORTD=0x00;
	DDRD=0x40;  //We use PORTB.6 as output, for OC0A, see the atmega8 reference manual

	// Mode: Phase correct PWM top=0xFF
	// OC2A output: Non-Inverted PWM
	TCCR0A=0x81;
	// Set the speed here, it will depend on your clock rate.
	TCCR0B=0x01;

	OCR0A = 130; //50.9% duty cycle

	while(1) { }
}
