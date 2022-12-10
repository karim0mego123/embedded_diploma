/*
 * GccApplication2.c
 *
 * Created: 11/26/2022 1:39:16 PM
 * Author : karim
 */ 

#include "Utils/Memory_Map.h"
#define F_CPU	8000000UL
#include <util/delay.h>



int main(void)
{
	uint8_t Loc_Count = 0 ;
	SET_REG(DDRA_BASE);
	CLEAR_BIT(DDRC_BASE,PIN0);
	SET_BIT(PORTC_BASE,PIN0);
    /* Replace with your application code */
    while (1) 
    {
		if(READ_BIT(PINC_BASE,PIN0)==0)
		{
			if ( Loc_Count > 7 )
				Loc_Count=0;
			TOOGLE_BIT(PORTA_BASE,Loc_Count);
			Loc_Count++;
			_delay_ms(500);			
		}
    }
}

