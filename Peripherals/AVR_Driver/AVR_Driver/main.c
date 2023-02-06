/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
void LCD()
{
	LCD_Write_String((uint8_t*)"Karim El Meligy",0,0) ;
	_delay_ms(2000) ;
	LCD_Clear_Screen();
}

int main(void)
{
	LCD_Init(); 
	LCD_Write_String((uint8_t*)"Karim El Meligy",0,0) ;
}


