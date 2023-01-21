/*
 * STM32F103XX.h
 *
 *  Created on: Jan 21, 2023
 *      Author: karim
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
/****************************************************************************************
*					    	 																								  		*
*														Includes													 	  		*
*																															  		*
*****************************************************************************************/

#include "stdint.h"
#include "stdlib.h"

/****************************************************************************************
*																																	  *
*													Base addresses for Memories								  *
*																																	  *
*****************************************************************************************/

#define FLASH_Memory_Base											0x08000000UL
#define System_Memory_Base											0x1FFFF000UL
#define SRAM_Memory_Base											0x20000000UL
#define Peripherals_Base													0x40000000UL
#define CORTEXM3_Internal_Peripherals_Base					0xE0000000UL


/****************************************************************************************
 *																																	   *
 *													Base addresses for AHB_Peripherals						   *
 *																																	   *
 *****************************************************************************************/

#define RCC_BASE						0x40021000UL

/******************************************************************************************
 *																																       *
 *													Base addresses for APP2_Peripherals					 	   *
 *																																	   *
 *****************************************************************************************/

#define GPIOA_BASE					0x40010800UL
#define GPIOB_BASE					0x40010C00UL
#define GPIOC_BASE					0x40011000UL
#define GPIOD_BASE					0x40011400UL
#define GPIOE_BASE					0x40011800UL
#define AFIO_BASE					0x40010000UL
#define EXTI_BASE						0x40010400UL

/****************************************************************************************
*																																	  *
*													Peripheral register:													  *
*																																	  *
*****************************************************************************************/

// Peripheral register : GPIO

typedef struct {
	volatile uint32_t	CRL ;
	volatile uint32_t	CRH;
	volatile uint32_t	IDR ;
	volatile uint32_t	ODR;
	volatile uint32_t	BSRR ;
	volatile uint32_t	BRR ;
	volatile uint32_t LCKR ;
}GPIO_Typedef ;

// Peripheral register : AFIO

typedef struct {
	volatile uint32_t	EVCR ;
	volatile uint32_t	MAPR;
	volatile uint32_t	EXTICR1 ;
	volatile uint32_t	EXTICR2;
	volatile uint32_t	EXTICR3 ;
	volatile uint32_t	EXTICR4 ;
	volatile uint32_t	RESERVED0 ;
	volatile uint32_t MAPR2 ;
}AFIO_Typedef ;

// Peripheral register : RCC

typedef struct {
	volatile uint32_t		CR ;
	volatile uint32_t		CFGR;
	volatile uint32_t		CIR	 ;
	volatile uint32_t		APB2RSTR;
	volatile uint32_t		APB1RSTR ;
	volatile uint32_t		AHBENR ;
	volatile uint32_t 		APB2ENR ;
	volatile uint32_t 		APB1ENR ;
	volatile uint32_t 		BDCR ;
	volatile uint32_t 		CSR ;
	volatile uint32_t 		AHBSTR ;
	volatile uint32_t 		CFGR2 ;
}RCC_Typedef ;

// Peripheral register : EXTR

typedef struct {
	volatile uint16_t	IMR ;
	volatile uint16_t	EMR;
	volatile uint16_t	RTSR ;
	volatile uint16_t	FTSR;
	volatile uint16_t	SWIER ;
	volatile uint16_t	PR ;
}EXTI_Typedef ;

//Peripheral Instants:

#define GPIOA							((GPIO_Typedef		*)GPIOA_BASE)
#define GPIOB							((GPIO_Typedef		*)GPIOB_BASE)
#define GPIOC							((GPIO_Typedef		*)GPIOC_BASE)
#define GPIOD							((GPIO_Typedef		*)GPIOD_BASE)
#define GPIOE							((GPIO_Typedef		*)GPIOE_BASE)

#define RCC								((RCC_Typedef	*)RCC_BASE)
#define EXTI								((EXTR_Typedef	*)EXTI_BASE)
#define AFIO								((AFIO_Typedef	*)AFIO_BASE)



/****************************************************************************************
*																																	*
*													clock enable Macros:												*
*																														       		*
*****************************************************************************************/

#define RCC_GPIOA_CLK_EN()			(RCC->APB2ENR |= (1<<2)) ;
#define RCC_GPIOB_CLK_EN()			(RCC->APB2ENR |= (1<<3)) ;
#define RCC_GPIOC_CLK_EN()			(RCC->APB2ENR |= (1<<4)) ;
#define RCC_GPIOD_CLK_EN()			(RCC->APB2ENR |= (1<<5)) ;
#define RCC_GPIOE_CLK_EN()			(RCC->APB2ENR |= (1<<6)) ;
#define RCC_AFIO_CLK_EN()				(RCC->APB2ENR |= (1<<0)) ;






#endif /* INC_STM32F103XX_H_ */
