/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "LCD.h"
#include "Keypad.h"


#define ZERO		0xC0
#define ONE			0xF9
#define TWO			0xA4
#define THREE		0xB0
#define FOUR		0x99
#define FIVE		0x92
#define SIX			0x82
#define SEVEN		0xF8
#define EIGHT		0x80
#define NINE		0x90
#define	DOT			0x80


void Clock_Init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}
void Main_GPIO_init()
{
	GPIO_PinCongif_t PinConFig;

	PinConFig.GPIO_PinNumber=GPIO_PIN_9 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_10 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_11;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_12 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_13 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_14 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;

	PinConFig.GPIO_PinNumber=GPIO_PIN_15 ;
	PinConFig.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
	PinConFig.GPIO_OutPut_Speed=GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinConFig) ;
}
int main(void)
{
	Clock_Init();
	LCD_Init();

	LCD_Write_String((uint8_t*)"Hello", 0, 0) ;
	_delay_ms(100) ;
	LCD_Clear_Screen();

	Main_GPIO_init();
	uint8_t LCD_DISPLAY [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	uint8_t SEG[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	for ( uint8_t i =0 ; i < 11 ; i++ )
	{
		Lcd_Write_Char(LCD_DISPLAY[i]) ;
		MCAL_GPIO_Write_PORT(GPIOB, SEG[i]<<9);
		_delay_ms(100);
	}
	LCD_Clear_Screen();
	uint8_t KeyPressed ;
	KeYPad_Init();
	LCD_Write_String((uint8_t*)"Keypad is ready",0,0);
	_delay_ms(100);
	LCD_Clear_Screen();
	while(1)
	{

		KeyPressed = KeyPAd_Scan() ;
		switch(KeyPressed)
		{
		case 'a' :
			break ;
		default :
			Lcd_Write_Char(KeyPressed);
		}
	}

}

