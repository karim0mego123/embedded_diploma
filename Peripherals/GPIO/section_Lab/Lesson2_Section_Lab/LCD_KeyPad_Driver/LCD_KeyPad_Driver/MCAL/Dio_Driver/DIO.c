/*
 * DIO.c
 *
 * Created: 12/13/2022 11:58:48 AM
 *  Author: karim
 */ 

#include "DIO.h"

void DIO_Init( uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction )
{
	switch( PortNumber )
	{
		case PORT_A :
		if ( Direction == OUT )
		{
			DDRA |= (1<<PinNumber) ;
		}
		else if ( Direction == IN )
		{
			DDRA &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_B :
		if ( Direction == OUT )
		{
			DDRB |= (1<<PinNumber) ;
		}
		else if ( Direction == IN )
		{
			DDRB &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_C :
		if ( Direction == OUT )
		{
			DDRC |= (1<<PinNumber) ;
		}
		else if ( Direction == IN )
		{
			DDRC &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_D :
		if ( Direction == OUT )
		{
			DDRD |= (1<<PinNumber) ;
		}
		else if ( Direction == IN )
		{
			DDRD &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
	}
}
void DIO_Write( uint8_t PortNumber , uint8_t PinNumber , uint8_t value  )
{
	switch( PortNumber )
	{
		case PORT_A :
		if ( value == HIGH )
		{
			PORTA |= (1<<PinNumber) ;
		}
		else if ( value == LOW )
		{
			PORTA &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_B :
		if ( value == HIGH )
		{
			PORTB |= (1<<PinNumber) ;
		}
		else if ( value == LOW )
		{
			PORTB &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_C :
		if ( value == HIGH )
		{
			PORTC |= (1<<PinNumber) ;
		}
		else if ( value == LOW )
		{
			PORTC &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
		case PORT_D :
		if ( value == HIGH )
		{
			PORTD |= (1<<PinNumber) ;
		}
		else if ( value == LOW )
		{
			PORTD &= ~(1<<PinNumber) ;
		}
		else
		{
			//	Error Handling
		}
		break ;
	}
}
void DIO_Read( uint8_t PortNumber , uint8_t PinNumber , uint8_t* value  )
{
	switch(PortNumber)
	{
		case PORT_A :
		*(value) = (PINA &(1<<PinNumber))>>PinNumber ;
		break ;
		case PORT_B :
		*(value) = (PINB &(1<<PinNumber))>>PinNumber ;
		break;
		case PORT_C :
		*(value) = (PINC &(1<<PinNumber))>>PinNumber ;
		break;
		case PORT_D :
		*(value) = (PIND &(1<<PinNumber))>>PinNumber ;
		break;
		
	}
}
void DIO_Toggle( uint8_t PortNumber , uint8_t PinNumber  )
{
	switch(PortNumber)
	{
		case PORT_A :
		PORTA ^= (1<<PinNumber);
		break ;
		case PORT_B :
		PORTB ^= (1<<PinNumber);
		break ;
		case PORT_C :
		PORTC ^= (1<<PinNumber);
		break ;
		case PORT_D :
		PORTD ^= (1<<PinNumber);
		break ;
	}   
}