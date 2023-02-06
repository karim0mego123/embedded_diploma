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




#define NVIC_BASE		(0xE000E100UL)

#define NVIC_ISER0		*(volatile uint32_t *)(NVIC_BASE + 0x00)
#define NVIC_ISER1		*(volatile uint32_t *)(NVIC_BASE + 0x04)
#define NVIC_ISER2		*(volatile uint32_t *)(NVIC_BASE + 0x08)
#define NVIC_ICER0		*(volatile uint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1		*(volatile uint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2		*(volatile uint32_t *)(NVIC_BASE + 0x88)
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
#define EXTI_BASE					0x40010400UL

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
	volatile uint32_t	EXTICR[4] ;
			 uint32_t	RESERVED0 ;
	volatile uint32_t	MAPR2 ;
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
	volatile uint32_t	IMR ;
	volatile uint32_t	EMR;
	volatile uint32_t	RTSR ;
	volatile uint32_t	FTSR;
	volatile uint32_t	SWIER ;
	volatile uint32_t	PR ;
}EXTI_Typedef ;

//Peripheral Instants:

#define GPIOA							((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB							((GPIO_Typedef *)GPIOB_BASE)
#define GPIOC							((GPIO_Typedef *)GPIOC_BASE)
#define GPIOD							((GPIO_Typedef *)GPIOD_BASE)
#define GPIOE							((GPIO_Typedef *)GPIOE_BASE)

#define RCC								((RCC_Typedef	*)RCC_BASE)
#define EXTI							((EXTI_Typedef	*)EXTI_BASE)
#define AFIO							((AFIO_Typedef	*)AFIO_BASE)


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

// EXTI
#define EXTI0						0
#define EXTI1						1
#define EXTI2						2
#define EXTI3						3
#define EXTI4						4
#define EXTI5						5
#define EXTI6						6
#define EXTI7						7
#define EXTI8						8
#define EXTI9						9
#define EXTI10						10
#define EXTI11						11
#define EXTI12						12
#define EXTI13						13
#define EXTI14						14
#define EXTI15						15

//********************************************
//IVT :
//********************************************
#define EXTI0_IRQ						6
#define EXTI1_IRQ						7
#define EXTI2_IRQ						8
#define EXTI3_IRQ						9
#define EXTI4_IRQ						10
#define EXTI5_IRQ						23
#define EXTI6_IRQ						23
#define EXTI7_IRQ						23
#define EXTI8_IRQ						23
#define EXTI9_IRQ						23
#define EXTI10_IRQ						40
#define EXTI11_IRQ						40
#define EXTI12_IRQ						40
#define EXTI13_IRQ						40
#define EXTI14_IRQ						40
#define EXTI15_IRQ						40

/*********************************************
 *  NVIC IRQ Enable Disable Macros			 *
 *********************************************/

//ْEXTI0 will send signal on line 6 in NVIC So i Want to Enable Line 6 in NVIC

#define NVIC_IRQ6_EXTI0_Enable				(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable 				(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable 				(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable 				(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable 			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable 			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable 		(NVIC_ISER1 |= 1<<8)

#define NVIC_IRQ6_EXTI0_Disable 			(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable 			(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable 			(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable 			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable 			(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable 			(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable 		(NVIC_ICER1 |= 1<<8)




#endif /* INC_STM32F103XX_H_ */
