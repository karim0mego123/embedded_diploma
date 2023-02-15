/*
 * USART.c
 *
 * Created: 2/10/2023 5:01:04 PM
 *  Author: karim
 */ 
#include "USART.h"



Error_Status_t USART_Init()
{
	Error_Status_t Loc_Init_Status = NO_Error ;
	

	#if Speed_Mode == Normal_Speed
	UCSRA |=(1<<U2X) ; 
	#endif

	#if	UART_MODE == Transciever
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
	#endif
	
	uint8_t Loc_u8UCSRC = 0 ; // UCSRC can not use bit access so i made variable to bit access intreed of register
	
	#if UART_Clock == Asynchronous
	Loc_u8UCSRC &=~ (1<<6) ; 
	#endif

	#if Data_Len == Eight
	Loc_u8UCSRC |= (3<<1);
	#endif

	#if Parity_State == NO_parity 
	Loc_u8UCSRC &=~ (3<<4);
	#endif
	
	#ifdef STOP_State == One_Bit
	Loc_u8UCSRC &=~ (1<<3);
	#endif

	Loc_u8UCSRC |= (1<<7) ;  	// Select Regester UCsrc by write one in bit 7 or UBRRH 0 
	UCSRC = Loc_u8UCSRC ; 

	uint16_t Loc_u16UBRR = MYUBRR(BAUD);

	Loc_u16UBRR &=~ (1<<15);	// Select Regester UCsrc by write one in bit 7 or UBRRH 0 
	UBRRL = (uint8_t) Loc_u16UBRR ;
	UBRRH |= (uint8_t) (Loc_u16UBRR>>8) ; 

	return Loc_Init_Status ; 
}

Error_Status_t USART_TX_Char(uint8_t Data )
{
	Error_Status_t Loc_TX_Status = NO_Error ;
		while(!( (UCSRA>>5) & 1) );
		UDR = Data ; 
	return Loc_TX_Status ; 
}
Error_Status_t USART_RX_Char( uint8_t* Data )
{
	Error_Status_t Loc_RX_Status = NO_Error ;
	if(Data==NULLPTR)
	{
		Loc_RX_Status = Error ; 
	}
	else
	{
		while(!( (UCSRA>>7) & 1) );
		*Data = UDR ; 
	}
	return Loc_RX_Status ; 
}
Error_Status_t USAERT_TX_STRING(uint8_t* String)
{
	Error_Status_t Loc_TX_String_Status = NO_Error ;
	if(String==NULLPTR)
	{
		Loc_TX_String_Status = Error ; 
	}
	else
	{
		while (*String != '\r')
		{
			USART_RX(String);
			String++ ;
		}
	}
	return Loc_TX_String_Status ; 
}
Error_Status_t USAERT_RX_STRING(uint8_t* String)
{
	uint8_t Loc_Data ; 
	Error_Status_t Loc_RX_STRING_Status = NO_Error ;
	if(String==NULLPTR)
	{
		Loc_RX_STRING_Status = Error ; 
	}
	while (1)
	{
		USART_RX_Char(String);
		if(*string == '\r' || *string == '\n' )
		{
			*string = '\0' ; 
			break;
		}
	}
	return Loc_RX_STRING_Status ; 
}































/*

void USART_Init()
{
		//Buadrate
// 	UBRRL = (uint8_t) (MYUBRR) ; 
// 		UBRRH = (uint8_t) (MYUBRR>>8)&(0x0F) ;
	UBRRL = 51 ; 
	//enable
	
	//frame
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,USBS);
	SET_BIT(UCSRC,UCSZ0);
	
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}
void USART_TX(uint8_t Data )
{
	while(!( (UCSRA>>5) & 1) );
	UDR = Data ;
}

uint8_t USART_RX()
{
	while(!( (UCSRA>>7) & 1) );
	return UDR ;
}
void USAERT_TX_STRING(uint8_t* String)
{
	uint8_t i = 0 ; 
	while( String[i] != 0 )
	{
		USART_TX(String[i]) ; 
		i++ ;
	}
}

uint8_t USAERT_RX_STRING()
{
	
}