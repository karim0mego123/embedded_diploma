/*
 * GccApplication1.c
 *
 * Created: 11/26/2022 12:01:10 PM
 * Author : karim
 */ 

#include "Utils/Memory_Map.h"
#define F_CPU	8000000UL
#include <util\delay.h>

int main(void)
{
	SET_REG(DDRA_BASE);
    /* Replace with your application code */
    while (1) 
    {
		SET_BIT(PORTA_BASE,PIN0);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN1);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN2);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN3);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN4);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN5);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN6);
		_delay_ms(500);
		SET_BIT(PORTA_BASE,PIN7);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN7);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN6);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN5);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN4);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN3);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN2);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN1);
		_delay_ms(500);
		CLEAR_BIT(PORTA_BASE,PIN0);
		_delay_ms(500);
    }
}

