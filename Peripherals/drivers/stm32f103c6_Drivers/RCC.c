/*
 * RCC.c
 *
 *  Created on: Feb 16, 2023
 *      Author: karim
 */
#include "RCC.h"

// PPRE1[2:0]: APB Low-speed prescaler (APB1)
// 0xx: HCLK not divided
// 100: HCLK divided by 2
// 101: HCLK divided by 4
// 110: HCLK divided by 8
// 111: HCLK divided by 16
const uint8_t APBprescTablep[8U] ={0, 0, 0, 0, 1, 2, 3, 4}; //Shift 1 right == Divide the value by 2

// Bits 7:4 HPRE[3:0]: AHB prescaler
// Set and cleared by software to control AHB clock division factor.
// 0xxx: SYSCLK not divided
// 1000: SYSCLK divided by 2
// 1001: SYSCLK divided by 4
// 1010: SYSCLK divided by 8
// 1011: SYSCLK divided by 16
// 1100: SYSCLK divided by 64
// 1101: SYSCLK divided by 128
// 1110: SYSCLK divided by 256
// 1111: SYSCLK divided by 512
const uint8_t AHBprescTablep[16U] ={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

uint32_t MCAL_RCC_GetSYSCLK()
{
	switch((RCC->CFGR>>2)&0b11)
	{
	case 0 :
		return HSI_CLK ;
		break ;
	case 1 :
		return HSE_CLK ;
		break ;
	case 2 :
		return 16000000 ;
		break ;
	}
}
uint32_t MCAL_RCC_GetHCLK()
{
	/* Get SYSCLK source and Compute HCLK frequency ---------------------------*/
	return (MCAL_RCC_GetSYSCLK() >>AHBprescTablep[(RCC->CFGR>>4)&0xF]) ;	//the first shift is Dividing

}
uint32_t MCAL_RCC_GetPCLK1()
{
	/* Get HCLK source and Compute PCLK1 frequency ---------------------------*/
	return (MCAL_RCC_GetHCLK() >>APBprescTablep[(RCC->CFGR>>8)&0b111]) ;	//the first shift is Dividing
}
uint32_t MCAL_RCC_GetPCLK2()
{
	/* Get HCLK source and Compute PCLK2 frequency ---------------------------*/
	return (MCAL_RCC_GetHCLK() >>APBprescTablep[(RCC->CFGR>>11)&0b111]) ;		//the first shift is Dividing
}
