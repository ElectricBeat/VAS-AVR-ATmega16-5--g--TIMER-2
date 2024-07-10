/*
 * TIMER2.c
 *
 * Created: 10-07-2024 15:15:24
 * Author : SRIDHAR
 */ 

#include <avr/io.h>

void T2delay();

int main(void)
{
	DDRB	=	0xFF;				/* PORTB as output */
	PORTB	=	0x00;

	while(1)  						/* Repeat forever */
	{
		PORTB	=	~PORTB;
		T2delay();
	}
}

void T2delay()
{
	TCCR2 = (1<<CS22) | (1<<CS21) | (1<<CS20);	/* Timer2, normal mode, /1024 prescalar */
	TCNT2 = 0XF6;					/* Load TCNT2, count for 10ms */
	while((TIFR&0x40)==0);			/* Wait for TOV2 to roll over */
	TCCR2 = 0;
	TIFR = 0x40;					/* Clear TOV2 flag */
}