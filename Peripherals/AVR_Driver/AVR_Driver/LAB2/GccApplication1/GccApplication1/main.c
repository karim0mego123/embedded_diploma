/*
 * GccApplication1.c
 *
 * Created: 3/2/2023 7:33:42 PM
 * Author : karim
 */ 
#define F_CPU	1000000U
#include <avr/io.h>

#include "util/delay.h"

#define MOSI	5
#define SCK		7
#define SS		4
typedef unsigned char uint8_t ; 
void Execute(uint8_t Data , uint8_t Cmd)  
{
	PORTB &=~ (1<<SS) ; 
	SPDR = Cmd ; 
	while(!(SPSR&(1<<SPIF)));
	SPDR = Data ; 
	while(!(SPSR&(1<<SPIF)));
	PORTB |= (1<<SS) ; 	
	
}

int main(void)
{
    uint8_t Loc_Counter = 0 , Index_Dispaly = 1 ; 
	DDRB = (1<<MOSI)| (1<<SCK) | (1<<SS) ; 
	SPSR = (1<<SPE) | (1<<MSTR) | (1<<SPR0) ; 
	Execute(0xFF,0x09) ; 
	Execute(0x07,0x0B) ;
	Execute(0x0F,0x0A) ;
	Execute(0x01,0x0C) ;
	while(1)
	{
		for (Index_Dispaly = 1 ; Index_Dispaly<9 ; Index_Dispaly++)
		{
			Execute(Index_Dispaly,Loc_Counter++) ; 
		}
			_delay_ms(1000) ;
	}
	return 0 ; 
}

