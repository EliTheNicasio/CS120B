/* Partner(s) Name & E-mail: Hangqi Wu(hwu110@ucr.edu), Elijah Nicasio (enica001@ucr.edu)
 * Lab Section: B21
 * Assignment: Lab 1 Exercise 2
 * Exercise Description: lab 1 exercise 2
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs,
	// initialize to 0s
	
	while(1)
	{
		unsigned char count = 0x00;
		
		if(PINA & 0x01)
			count++;
		if(PINA & 0x02)
			count++;
		if(PINA & 0x04)
			count++;
		if(PINA & 0x08)
			count++;
			
		PORTC = 4 - count;
	}
	return 0;
}

