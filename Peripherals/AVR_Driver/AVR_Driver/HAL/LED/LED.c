/*
 * LED.h
 *
 * Created: 3/5/2023 11:23:13 PM
 *  Author: karim
 */ 
#include "LED.h"

void LED_Init_State(LED_t* LED , uint8_t LED_State)
{
	if (LED_State==OFF)
	{
		LED_OFF(LED);	
	}
	else
	{
		LED_ON(LED);
	}
}
void LED_ON (LED_t* LED ) 
{
	DIO_Write_Pin_Dir(LED->PORT_ID,LED->PIN_ID,OUT);

	if (LED->Connection==Source_Current)
	{
		DIO_Write_Pin(LED->PORT_ID,LED->PIN_ID,HIGH);
	}
	else if (LED->Connection==Sink_Current)
	{
		DIO_Write_Pin(LED->PORT_ID,LED->PIN_ID,LOW);
	}
}
void LED_OFF(LED_t* LED ) 
{
	DIO_Write_Pin_Dir(LED->PORT_ID,LED->PIN_ID,OUT);
	
	if (LED->Connection==Source_Current)
	{
		DIO_Write_Pin(LED->PORT_ID,LED->PIN_ID,LOW);
	}
	else if (LED->Connection==Sink_Current)
	{
		DIO_Write_Pin(LED->PORT_ID,LED->PIN_ID,HIGH);
	}
}