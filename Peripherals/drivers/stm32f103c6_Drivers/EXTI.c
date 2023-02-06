/*
 * EXTI.c
 *
 *  Created on: Feb 3, 2023
 *      Author: karim
 */
#include "EXTI.h"
/*
 * ======================================================================
 *                                          Generic variables
 *======================================================================
 */
void (*GP_IRQ_CallBack[15])(void);

/*
 * ======================================================================
 *                                          Generic Macros
 *======================================================================
 */

#define AFIO_GPIO_EXTI_Mapping(x)       (	(x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0    )

/*
 * ======================================================================
 *                                          Generic Functions
 *======================================================================
 */
void NVIC_Enable(uint16_t IRQ)
{
	switch(IRQ)
	{
	case EXTI0 :
		NVIC_IRQ6_EXTI0_Enable  ;
		break ;
	case EXTI1 :
		NVIC_IRQ7_EXTI1_Enable ;
		break ;
	case EXTI2 :
		NVIC_IRQ8_EXTI2_Enable ;
		break ;
	case EXTI3 :
		NVIC_IRQ9_EXTI3_Enable ;
		break ;
	case EXTI4 :
		NVIC_IRQ10_EXTI4_Enable ;
		break ;
	case EXTI5 :
	case EXTI6 :
	case EXTI7 :
	case EXTI8 :
	case EXTI9 :
		NVIC_IRQ23_EXTI5_9_Enable ;
		break ;
	case EXTI10 :
	case EXTI11 :
	case EXTI12 :
	case EXTI13 :
	case EXTI14 :
	case EXTI15 :
		NVIC_IRQ40_EXTI10_15_Enable  ;
		break ;
	}
}

void NVIC_Disable(uint16_t IRQ)
{
	switch(IRQ)
	{
	case EXTI0 :
		NVIC_IRQ6_EXTI0_Disable  ;
		break ;
	case EXTI1 :
		NVIC_IRQ7_EXTI1_Disable ;
		break ;
	case EXTI2 :
		NVIC_IRQ8_EXTI2_Disable ;
		break ;
	case EXTI3 :
		NVIC_IRQ9_EXTI3_Disable ;
		break ;
	case EXTI4 :
		NVIC_IRQ10_EXTI4_Disable ;
		break ;
	case EXTI5 :
	case EXTI6 :
	case EXTI7 :
	case EXTI8 :
	case EXTI9 :
		NVIC_IRQ23_EXTI5_9_Disable ;
		break ;
	case EXTI10 :
	case EXTI11 :
	case EXTI12 :
	case EXTI13 :
	case EXTI14 :
	case EXTI15 :
		NVIC_IRQ40_EXTI10_15_Disable  ;
		break ;
	}
}
/*******************************************************************************************************************
 * 			@Fn							-Update_EXTI																										*
 * 			@brief 						-EXTI_Config EXTI set @ref EXTI_Define @ref EXTI_Trigger																										*
 * 			@retval						- None																																									*
 * 			Note						-NONE																																	*
 ********************************************************************************************************************/
void Update_EXTI (EXTI_PinConfig_t* EXTI_Config)
{
	// 1- configure GPiO TO be AFIO Input -> Floating input
	GPIO_PinCongif_t PinConfig ;
	PinConfig.GPIO_PinNumber=EXTI_Config->EXTI_PIN.GPIO_PIN ;
	PinConfig.GPIO_MODE = GPIO_Mode_INPUT_FLO ;
	MCAL_GPIO_INIT((GPIO_Typedef *)EXTI_Config->EXTI_PIN.GPIO_PORT, &PinConfig);

	// ==================================================

	// Update AFiO to Route Between EXTI Line With PORT A , B , C , D

	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber/4 ; // Git AFIO_EXTI[x] : x = 0 1 2 3
	uint8_t	AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber%4)*4;
	// clear four bits
	//	These bits are written by software to select the source input for EXTIx external interrupt.
	//	0000: PA[x] pin
	//	0001: PB[x] pin
	//	0010: PC[x] pin
	//	0011: PD[x] pin
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF<<AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping((GPIO_Typedef	*)EXTI_Config->EXTI_PIN.GPIO_PORT)&0xf)<<AFIO_EXTICR_Position);

	//==================================================

	// Update Resing and Falling Edge
	//clear the corresponding bit

	EXTI->RTSR &=~ (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &=~ (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if (EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAnd_Falling)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	// Set Callbak
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBak ;

	if(EXTI_Config->IRQ_EN==EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		NVIC_Enable(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &=~ (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		NVIC_Disable(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

}
/*
 * ====================================================================================================
 *                          APIs Functions Definitions
 * ====================================================================================================
 */

/**================================================================
 * @Fn               -MCAL_EXTI_GPIO_INIT
 * @brief            -Initialize EXTI from specific GPIO PIN and specify MASK/trigger condition and IRQ Callback
 *param[in]           -EXTI config set by @ref EXTI_define ,@ref EXTI_Trigger_define and @ref EXTI_IRQ_define
 * @retval           -none
 * Note              -it is Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 * =================================================================
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn               -MCAL_EXTI_GPIO_DeINIT
 * @brief            -Reset EXTI Registers and NVIC Corresponding IRQ Mask
 * @retval           -none
 * Note              -none
 * =================================================================
 */
void MCAL_EXTI_GPIO_Deinit(void)
{
	EXTI->IMR = 	0x00000000;
	EXTI->EMR = 	0x00000000;

	EXTI->RTSR =	0x00000000 ;

	EXTI->FTSR = 	0x00000000;
	EXTI->SWIER =	0x00000000;

	EXTI->PR  	=  	0xFFFFFFFF; // clear by write one

	// Disable EXTi and NVIC
	NVIC_IRQ6_EXTI0_Disable ;
	NVIC_IRQ7_EXTI1_Disable ;
	NVIC_IRQ8_EXTI2_Disable ;
	NVIC_IRQ9_EXTI3_Disable ;
	NVIC_IRQ10_EXTI4_Disable ;
	NVIC_IRQ23_EXTI5_9_Disable ;
	NVIC_IRQ40_EXTI10_15_Disable ;

}
/**================================================================
 * @Fn               -MCAL_EXTI_GPIO_Update
 * @brief            -Initialize EXTI from specific GPIO PIN and specify MASK/trigger condition and IRQ Callback
 *param[in]           -EXTI config set by @ref EXTI_define ,@ref EXTI_Trigger_define and @ref EXTI_IRQ_define
 * @retval           -none
 * Note              -it is Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 * =================================================================
 */
void MCAL_EXTI_GPIO_Updare(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
////**==========================================================================
////**==========================================================================
////**=====================     ISR FUNCTIONS      =============================
////**==========================================================================
////**==========================================================================

void EXTI0_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	EXTI->PR |= (1<<EXTI0);
	GP_IRQ_CallBack[EXTI0]();
}

void EXTI1_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	EXTI->PR |= (1<<EXTI1);
	GP_IRQ_CallBack[EXTI1]();

}

void EXTI2_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	EXTI->PR |= (1<<EXTI2);
	GP_IRQ_CallBack[EXTI2]();
}

void EXTI3_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	EXTI->PR |= (1<<EXTI3);
	GP_IRQ_CallBack[EXTI13]();
}

void EXTI4_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	EXTI->PR |= (1<<EXTI4);
	GP_IRQ_CallBack[EXTI4]();
}
void EXTI9_5_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	if (EXTI->PR & 1<<EXTI5){EXTI->PR |= 1<<EXTI5;GP_IRQ_CallBack[EXTI5]();}
	if (EXTI->PR & 1<<EXTI6){EXTI->PR |= 1<<EXTI6;GP_IRQ_CallBack[EXTI6]();}
	if (EXTI->PR & 1<<EXTI7){EXTI->PR |= 1<<EXTI7;GP_IRQ_CallBack[EXTI7]();}
	if (EXTI->PR & 1<<EXTI8){EXTI->PR |= 1<<EXTI8;GP_IRQ_CallBack[EXTI8]();}
	if (EXTI->PR & 1<<EXTI9){EXTI->PR |= 1<<EXTI9;GP_IRQ_CallBack[EXTI9]();}
}
void EXTI15_10_IRQHandler(void)
{
	// must clear PR By Writing one on Bit
	if (EXTI->PR & 1<<EXTI10){EXTI->PR |= 1<<EXTI10;GP_IRQ_CallBack[EXTI10]();}
	if (EXTI->PR & 1<<EXTI11){EXTI->PR |= 1<<EXTI11;GP_IRQ_CallBack[EXTI11]();}
	if (EXTI->PR & 1<<EXTI12){EXTI->PR |= 1<<EXTI12;GP_IRQ_CallBack[EXTI12]();}
	if (EXTI->PR & 1<<EXTI13){EXTI->PR |= 1<<EXTI13;GP_IRQ_CallBack[EXTI13]();}
	if (EXTI->PR & 1<<EXTI14){EXTI->PR |= 1<<EXTI14;GP_IRQ_CallBack[EXTI14]();}
	if (EXTI->PR & 1<<EXTI15){EXTI->PR |= 1<<EXTI15;GP_IRQ_CallBack[EXTI15]();}

}
