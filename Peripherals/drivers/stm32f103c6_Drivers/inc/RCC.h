/*
 * RCC.h
 *
 *  Created on: Feb 16, 2023
 *      Author: karim
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f103xx.h"
#include "GPIO.h"

#define HSI_CLK	((uint32_t)8000000)
#define HSE_CLK	((uint32_t)16000000)

uint32_t MCAL_RCC_GetSYSCLK();
uint32_t MCAL_RCC_GetHCLK();
uint32_t MCAL_RCC_GetPCLK1();
uint32_t MCAL_RCC_GetPCLK2();

#endif /* INC_RCC_H_ */
