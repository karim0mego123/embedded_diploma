/*
 * GccApplication3.c
 *
 * Created: 11/26/2022 5:30:31 PM
 * Author : karim
 */ 

#include "Utils/Memory_Map.h"
#define F_CPU	8000000UL
#include "util\delay.h"

int main(void)
{
	DDRC_BASE =0XFF;
	 DDRD_BASE = 0b11110000 ;	
    /* Replace with your application code */
    while (1) 
    {
		for ( uint8_t i = 0 ; i<10 ; i++ )
 		{
 			for ( uint8_t j = 0 ; j<10 ; j++ )
 			{
 				PORTC_BASE = 0b1011 | (i<<4);
 				_delay_ms(500);
 				PORTC_BASE = 0b0111 | (j<<4) ;
 				_delay_ms(500);
 			}
 		}
  }
}

