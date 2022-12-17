/*
 * LCD_KeyPad_Driver.c
 *
 * Created: 12/16/2022 9:49:51 PM
 * Author : karim
 */ 
#include "DIO.h"


#define Eight_Bit_Mode
// #define Four_Bit_Mode
#define LCD_PORT		PORTA
#define LCD_PORT_DIR	DDRA
#define LCD_CTRL		PORTB
#define LCD_CTRL_DIR	DDRB
#define Rs	0
#define RW	1
#define En	2


#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

void LCD_Init();
void LCD_Enanle();
void LCD_CLEAR_screen();
void LCD_Write_Data(uint8_t Data);
void LCD_Write_String(uint8_t* String,uint8_t Row,uint8_t Col);
void LCD_Write_Cmd(uint8_t Cmd);
void LCD_Go_TO_Index(uint8_t Row , uint8_t Col );
