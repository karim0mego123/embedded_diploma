/*
 * LCD.h
 *
 * Created: 1/24/2023 2:12:14 PM
 *  Author: karim
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STM32F103XX.h"
#include "GPIO.h"


//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_DATA			GPIOA
#define LCD_CTRL			GPIOA

#define LCD_PIN0	GPIO_PIN_0
#define LCD_PIN1	GPIO_PIN_1
#define LCD_PIN2	GPIO_PIN_2
#define LCD_PIN3	GPIO_PIN_3
#define LCD_PIN4	GPIO_PIN_4
#define LCD_PIN5	GPIO_PIN_5
#define LCD_PIN6	GPIO_PIN_6
#define LCD_PIN7	GPIO_PIN_7

#define RS_SWITCH	GPIO_PIN_0
#define RW_SWITCH	GPIO_PIN_1
#define EN_SWITCH	GPIO_PIN_2

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
#define Second_Row_Address							(0x40)

void LCD_Init();
void LCD_Enable ();
void LCD_Clear_Screen();
void LCD_Wirte_Cmd (uint8_t Cmd);
void Lcd_Write_Char(uint8_t Char) ;
void LCD_Write_String( uint8_t* STRING , uint8_t ROW , uint8_t COL);
void LCD_GO_TO_INDEX(uint8_t ROW , uint8_t COL);
void LCD_Store_Customer_Char(uint8_t* pattern , uint8_t CGram_index );
void LCD_Display_Customer_Char(uint8_t CGRAM_Index , uint8_t ROW , uint8_t Col ) ;
void LCD_Write_Number(uint16_t Number) ;
void _delay_ms(int Delay);

#endif /* LCD_H_ */
