/*
 * Calculator.c
 *
 * Created: 12/17/2022 7:47:11 PM
 *  Author: karim
 */ 
#include "Calculator.h"
#include "Kepad.h"
#include "Lcd.h"

void Calculator_Init()
{
	
	LCD_Init();
	//Display on Cursor off 0x0C
	LCD_Write_Cmd(0x0C);
	Key_Init();
}
void Calculator_Start()
{
	uint64_t  Result =0 ;
	uint8_t First_Num =0 , Second_Num=0 , String[10] , CH , check = 0 , count ,operation ;
	LCD_Write_String((uint8_t*)"Enter FirstNum = ",0,0);
	while(1)
	{
		CH=KeyPad_Scan();
		switch(CH)
		{
			case 'a':break;
			default:
				First_Num=CH;
				LCD_Write_Data(First_Num);
				_delay_ms(250);
				LCD_Write_Cmd(LCD_CLEAR_SCREEN);
				check++;
				break;
		}
		if (check!=0)
		{
			break;
		}
	}
	LCD_Write_String((uint8_t*)"Enter operation= ",0,0);
	check=0;
	while(1)
	{
		CH=KeyPad_Scan();
		switch(CH)
		{
			case 'a':break;
			default:
			operation=CH;
			LCD_Write_Data(operation);
			_delay_ms(250);
			LCD_Write_Cmd(LCD_CLEAR_SCREEN);
			check++;
			break;
		}
		if (check!=0)
		{
			break;
		}
	}	
	check=0;
	LCD_Write_String((uint8_t*)"Enter SecondNum = ",0,0);
	while(1)
	{	
		CH=KeyPad_Scan();
		switch(CH)
		{
			case 'a':break;
			default:
			{
				Second_Num=CH;
				LCD_Write_Data(Second_Num);
				_delay_ms(250);
				LCD_Write_Cmd(LCD_CLEAR_SCREEN);
				check++;
				break;
			}
		}
		if (check!=0)
		{
			break;
		}
	}
	switch(operation)
	{
		case '*':Result = (First_Num-48) * (Second_Num-48) ;break;
		case '/':Result = (First_Num-48) / (Second_Num-48) ;break;
		case '-':Result = (First_Num-48) - (Second_Num-48) ;break;
		case '+':Result = (First_Num-48) + (Second_Num-48) ;break;
		default:LCD_Write_String((uint8_t*)"Error",0,0);
	}
	count=0;
	while(Result!=0)
	{
		String[count]=Result%10;
		count++;
		Result/=10;		
	}
	LCD_Write_String((uint8_t*)"Result = ",0,0) ;
	while(count--)
	{
		LCD_Write_Data((String[count])+48);
	}
}
