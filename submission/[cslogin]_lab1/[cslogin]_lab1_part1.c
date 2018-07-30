/* Partner(s) Name & E-mail: Hangqi Wu(hwu110@ucr.edu), Elijah Nicasio (enica001@ucr.edu)
 * Lab Section: B21
 * Assignment: Lab 1 Exercise 1
 * Exercise Description: lab 1 exercise 1
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */


#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xff;
	DDRB = 0xff; PORTB = 0x00;
	
    unsigned char doorSensor = 0x00;
	unsigned char lightSensor = 0x00;
	unsigned char led = 0x00;
	
	while (1) 
    {
		doorSensor = PINA & 0x01;
		lightSensor = (PINA & 0x02) >> 1;
		led = doorSensor & ~lightSensor;
		PORTB = led;
	}
	return 0;
}

