/*
 * lab1_part1.c
 *
 * Created: 30/07/2018 1:28:54 PM
 * Author : wuhangqi25
 */ 

#include <avr/io.h>


int main(void)
{
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

