/*
 * STM32_GPIO.h
 *
 *  Created on: Jan 21, 2023
 *      Author: karim
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_

#include "stm32f103xx.h"

typedef struct {
	uint16_t	GPIO_PinNumber	;
	uint8_t		GPIO_MODE	;
	uint8_t		GPIO_OutPut_Speed ;
}GPIO_PinCongif_t;


#define GPIO_PIN_0				((uint16_t)0x0001)
#define GPIO_PIN_1				((uint16_t)0x0002)
#define GPIO_PIN_2				((uint16_t)0x0004)
#define GPIO_PIN_3				((uint16_t)0x0008)
#define GPIO_PIN_4				((uint16_t)0x0010)
#define GPIO_PIN_5				((uint16_t)0x0020)
#define GPIO_PIN_6				((uint16_t)0x0040)
#define GPIO_PIN_7				((uint16_t)0x0080)
#define GPIO_PIN_8				((uint16_t)0x0100)
#define GPIO_PIN_9				((uint16_t)0x0200)
#define GPIO_PIN_10				((uint16_t)0x0400)
#define GPIO_PIN_11 			((uint16_t)0x0800)
#define GPIO_PIN_12				((uint16_t)0x1000)
#define GPIO_PIN_13				((uint16_t)0x2000)
#define GPIO_PIN_14				((uint16_t)0x4000)
#define GPIO_PIN_15				((uint16_t)0x8000)
#define GPIO_PIN_ALL		    ((uint16_t)0xFFFF)

#define 		HIGH					1
#define 		LOW						0

#define LOCK_ENABLE			1
#define LOCK_ERROR			0

//  GPIO_MODE_Define
// 	 0 			Analog Mode
//  1			Floating Input (Reset State)
//  2 			Input Pull UP
//  3 			input Pull Down
//  4 			General Purpose output push_pull
//  5    		General Purpose output open_drain
//  6 			ALternate function output push_pull
//  7			ALternate function output open_drain
// 8 			Alternate function Input

#define GPIO_Mode_Analog							0x00000000U 					// 	Analog Mode
#define GPIO_Mode_INPUT_FLO						0x00000001U 					// 	FLoating input
#define GPIO_Mode_INPUT_PU						0x00000002U 					// 	input pull up
#define GPIO_Mode_INPUT_PD						0x00000003U 					// 	input pull down
#define GPIO_Mode_OUTPUT_PP					0x00000004U 					// 	output push pull
#define GPIO_Mode_OUTPUT_OD					0x00000005U 					// 	 output open_drain
#define GPIO_Mode_OUTPUT_AF_PP				0x00000006U 					// 	alternate output push pull
#define GPIO_Mode_OUTPUT_AF_OD			0x00000007U 					// 	alternate output open_drain
#define GPIO_Mode_AF_INPUT						0x00000008U 					// 	alternate function input

#define GPIO_SPEED_10M				0x00000001U 		//    outputmode , max speed 10 MHZ  .
#define GPIO_SPEED_2M				0x00000002U 		//	outputmode , max speed 2  MHZ      .
#define GPIO_SPEED_50M				0x00000003U 		//	outputmode , max speed 50 MHZ     .


/****************************************************************************************
 *																																	          *
 *													APIS Supported by "MCAL GPIO DRIVER"						  *
 *																																	  		  *
 *****************************************************************************************/
void MCAL_GPIO_INIT(GPIO_Typedef * GPIOX,GPIO_PinCongif_t* pinconfig);
void MCAL_GPIO_DeINIT(GPIO_Typedef * GPIOX);
uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number);
uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef * GPIOX );
void MCAL_GPIO_Write_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number,uint8_t value);
void MCAL_GPIO_Write_PORT(GPIO_Typedef * GPIOX,uint8_t value);
void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number);
uint8_t MCAL_GPIO_LOCKPIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number);






#endif /* INC_STM32_GPIO_H_ */
