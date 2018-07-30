#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00; 
	
	while(1)
	{
		unsigned char outputD = 0x00;
		unsigned int totalWeight = 0x00;
		
		unsigned char weightA = PINA;
		unsigned char weightB = PINB;
		unsigned char weightC = PINC;
		
		totalWeight = weightA + weightB + weightC;
		
		if(weightA > weightC)
			if(weightA - weightC > 80)
				outputD = (outputD | 0x02);
			else
				outputD = (outputD & 0xFD);
				
		else if(weightA < weightC)
			if(weightC - weightA > 80)
				outputD = (outputD | 0x02);
			else
				outputD = (outputD & 0xFD);
				
		else
			outputD = (outputD & 0xFD);
				
		if(totalWeight > 140)
			outputD = (outputD | 0x01);
		else
			outputD = (outputD & 0xFE);
			
		outputD = ((totalWeight >> 3) << 3) | outputD;
		
		PORTD = outputD;
	}
	return 0;
}