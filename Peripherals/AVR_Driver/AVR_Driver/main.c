/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 
#include "DIO.h"
#include "LCD.h"
#include "EXTI.h"
#include "GIE.h"
#include "LM35_Sensor.h"


int main()
{	
	uint16_t Loc_Read = 0 ;
	uint8_t Channel_id = 0 ; 
	
	LCD_Init();
	LM35_Init(Channel_id);
	
	while(1)
	{
		LM35_Read(&Loc_Read);
		LCD_Write_Number(Loc_Read);
		_delay_ms(1000);
		LCD_Clear_Screen();
	}
	return 0 ; 
}










