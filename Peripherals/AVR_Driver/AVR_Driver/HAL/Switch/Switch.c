/*
 * Switch.c
 *
 * Created: 3/5/2023 4:41:30 PM
 *  Author: karim
 */ 

#include "Switch_init.h"


void Switch_Init(SW_t* Copy_Switch , uint8_t SW_Num ) 
{
	uint8_t LOC_Counter = 0 ; 
	for (LOC_Counter=0 ; LOC_Counter<SW_Num ; LOC_Counter++)
	{
		if (Copy_Switch[LOC_Counter].SW_Status==PULL_UP)
		{
			DIO_Write_Pin_Dir(Copy_Switch[LOC_Counter].SW_PORT_ID,Copy_Switch[LOC_Counter].SW_PIN_ID,LOW);
			DIO_Write_Pin(Copy_Switch[LOC_Counter].SW_PORT_ID,Copy_Switch[LOC_Counter].SW_PIN_ID,Copy_Switch[LOC_Counter].SW_Status);
		}
		else
		{
			DIO_Write_Pin_Dir(Copy_Switch[LOC_Counter].SW_PORT_ID,Copy_Switch[LOC_Counter].SW_PIN_ID,LOW);
		}

	}	
}

uint8_t Switch_Get_State(SW_t* Copy_Switch  )
{
	uint8_t CopyStatus ; 
	DIO_Read(Copy_Switch->SW_PORT_ID,Copy_Switch->SW_PIN_ID,&CopyStatus);
	return CopyStatus ; 
}
void Debouncing(uint8_t PIN , uint8_t PIN_Number ) 
{
	while(((PINA>>PIN_Number)&1)==0);
}