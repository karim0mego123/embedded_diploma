/*
 * LCD_KeyPad_Driver.c
 *
 * Created: 12/16/2022 9:49:51 PM
 * Author : karim
 */ 
#include "Lcd.h"
extern uint8_t Key_index;

void LCD_Enanle()
{
	SET_BIT(LCD_CTRL,En);
	_delay_ms(50);
	CLEAR_BIT(LCD_CTRL,En);
}
void LCD_CLEAR_screen()
{
	LCD_Write_Cmd(LCD_CLEAR_SCREEN);
}

void LCD_Init()
{
	_delay_ms(20);
	// set RS RW EN AS OUTPUT
	LCD_CTRL_DIR=0x07;
	// 	SET_BIT(LCD_CTRL_DIR,Rs);
	// 	SET_BIT(LCD_CTRL_DIR,RW);
	// 	SET_BIT(LCD_CTRL_DIR,En);

	//  CLEAR BITS RS RW EN
	LCD_CTRL&=~(0x07);
	// 	CLEAR_BIT(LCD_CTRL,RW);
	// 	CLEAR_BIT(LCD_CTRL,Rs);
	// 	CLEAR_BIT(LCD_CTRL,En);
	
	// set PORT DATA DIRCATION AS OUTPUT
	SET_REG(LCD_PORT_DIR);
	_delay_ms(15);
	LCD_Write_Cmd(LCD_CLEAR_SCREEN);
	#ifdef Eight_Bit_Mode
	LCD_Write_Cmd(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef Four_Bit_Mode
	//LCD_Write_Cmd(0x02);		/* send for 4 bit initialization of LCD  */
	//LCD_Write_Cmd(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_Write_Cmd(0x0c);              /* Display on cursor off*/
	//LCD_Write_Cmd(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_Write_Cmd(0x01);
	LCD_Write_Cmd(0x02);
	LCD_Write_Cmd(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_Write_Cmd(LCD_ENTRY_MODE);
	LCD_Write_Cmd(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Write_Cmd(LCD_DISP_ON_CURSOR_BLINK);
	
}

void LCD_Write_Cmd(uint8_t Cmd)
{

	#ifdef Four_Bit_Mode
	// To Send instratoin
	CLEAR_BIT(LCD_CTRL,Rs);
	CLEAR_BIT(LCD_CTRL,RW);
	LCD_PORT = (LCD_PORT&0x0F)|(Cmd&0xF0); // Git Least 4 Bits
	LCD_Enanle(); // Read data From 4 Bits in port
	
	// Delay 1s Between Send 4 by 4 Bits
	_delay_ms(1);
	
	CLEAR_BIT(LCD_CTRL,Rs);
	CLEAR_BIT(LCD_CTRL,RW);
	LCD_PORT = (LCD_PORT&0xF0)|(Cmd&0c0F);
	LCD_Enanle();
	#endif
	
	#ifdef Eight_Bit_Mode
	// To Send instruction
	CLEAR_BIT(LCD_CTRL,Rs);
	CLEAR_BIT(LCD_CTRL,RW);
	LCD_PORT=Cmd; // Git 8 bits from Cmd INSTRACTION and put them in portData
	LCD_Enanle(); // Read data From 8 Bits in port
	#endif
	
	_delay_ms(2);
}

void LCD_Write_Data(uint8_t Data)
{
	#ifdef Eight_Bit_Mode
	// MOVE DATA FROM DATA TO PORT DATA
	if(Key_index==16)
	{
		LCD_Go_TO_Index(1,0);
	}
	LCD_PORT=Data;
	// MODE WRITE DATA
	CLEAR_BIT(LCD_CTRL,RW);
	SET_BIT(LCD_CTRL,Rs);
	_delay_ms(1); 
	// LCD READ DATA FROM PORT
	LCD_Enanle();
	#endif
	
	#ifdef Four_Bit_Mode
	
	LCD_PORT = (LCD_PORT&0x0F)|Data&0xF0);
	CLEAR_BIT(LCD_CTRL,RW);
	SET_BIT(LCD_CTRL,Rs);
	LCD_Enanle();
	
	_delay_ms(1);
	
	LCD_PORT = (LCD_PORT&0xF0)|Data&0xF0);
	CLEAR_BIT(LCD_CTRL,RW);
	SET_BIT(LCD_CTRL,Rs);
	LCD_Enanle();
	
	_delay_ms(1);
	
#endif
}
void LCD_Write_String(uint8_t* String,uint8_t Row,uint8_t Col)
{

	uint8_t index = 0 ;
	uint8_t Line = 0 ;
	LCD_Go_TO_Index(Row,Col);
	if (Row==1)
	{
		Line=Row;
	}
	while((String[index]!='\0')&&((Row*16)+(index+Col)<=32))
	{
		if ((Row*16)+(index+Col)==32) // complete string in Row0
		{
			LCD_Go_TO_Index(0,0);
			Col=0;
			Row=0;
			index++;
		}
		if (((Row*16)+(index+Col))<16) // Write data in Row0
		{
			LCD_Write_Data(String[index]);
			index++ ;
		}
		else if (((Row*16)+(index+Col)==16)&&(Line==0)) // to move to Row 1
		{
			LCD_Go_TO_Index(1,0);
			Line++;	
		}
		else if (((Row*16)+(index+Col)<32)&&(Line==1)) // to Write Data in Row 1 
		{
			LCD_Write_Data(String[index]);
			index++ ;
		}
	
	}
}
void LCD_Go_TO_Index(uint8_t Row,uint8_t Col)
{
	uint8_t Address ; 
	if (Row<2&&Col<16)
	{
		Address =(Row*0x40)+(Col);  // 0Á40 start address of Row2  
		SET_BIT(Address,7);
		LCD_Write_Cmd(Address);
	}

}