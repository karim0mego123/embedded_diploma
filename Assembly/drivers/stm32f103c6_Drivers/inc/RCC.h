/*
 * RCC.h
 *
 *  Created on: Feb 16, 2023
 *      Author: karim
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_


//-----------------------------
//Includes
//-----------------------------
#include "stm32f103xx.h"
#include "GPIO.h"



#define HSE_CLK (uint32_t)16000000
#define HSI_RC_CLK (uint32_t)8000000

//-----------------------------
//User type definitions (structures)
//config structure
//-----------------------------

//-----------------------------
//Macros Configuration References
//-----------------------------

/*
 * @ref Module_REF_NAME_define
 */

/*
 * ====================================================================================================
 *                          APIs Supported by "MCAL RCC DRIVER"
 *====================================================================================================
 * */

uint32_t MCAL_RCC_GetSYSCLK1Freq(void) ;
uint32_t MCAL_RCC_GetHCLKFreq(void) ;
uint32_t MCAL_RCC_GetPCLK1Freq(void) ;
uint32_t MCAL_RCC_GetPCLK2Freq(void) ;



#endif /* INC_RCC_H_ */
