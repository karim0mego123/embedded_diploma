/*
 * STM32_GPIO.c
 *
 *  Created on: Jan 21, 2023
 *      Author: karim
 */

#include "STM32_GPIO.h"

/*******************************************************************************************************************
 * 			@Fn								-Get_CRLH_Position																									*
 * 			@brief 						-get position of specific startbit in pin																		*
 * 			@param [in]				-pinNumber of specific GPIO PORT																	   	*
 * 			@retval						-NONE																														*
 * 			Note							-NONE																														*
 ********************************************************************************************************************/
static uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	uint16_t Loc_Pin_Number = 0 ;
	switch(PinNumber)
	{
	case GPIO_PIN_0 :
		Loc_Pin_Number = 0 ;
		break ;
	case GPIO_PIN_1 :
		Loc_Pin_Number = 4 ;
		break ;
	case GPIO_PIN_2 :
		Loc_Pin_Number = 8 ;
		break ;
	case GPIO_PIN_3 :
		Loc_Pin_Number = 12 ;
		break ;
	case GPIO_PIN_4 :
		Loc_Pin_Number = 16 ;
		break ;
	case GPIO_PIN_5 :
		Loc_Pin_Number = 20 ;
		break ;
	case GPIO_PIN_6 :
		Loc_Pin_Number = 24 ;
		break ;
	case GPIO_PIN_7 :
		Loc_Pin_Number = 28 ;
		break ;
	case GPIO_PIN_8 :
		Loc_Pin_Number = 0 ;
		break ;
	case GPIO_PIN_9 :
		Loc_Pin_Number = 4 ;
		break ;
	case GPIO_PIN_10 :
		Loc_Pin_Number = 8 ;
		break ;
	case GPIO_PIN_11 :
		Loc_Pin_Number = 12 ;
		break ;
	case GPIO_PIN_12 :
		Loc_Pin_Number = 16 ;
		break ;
	case GPIO_PIN_13 :
		Loc_Pin_Number = 20 ;
		break ;
	case GPIO_PIN_14 :
		Loc_Pin_Number = 24 ;
		break ;
	case GPIO_PIN_15 :
		Loc_Pin_Number = 28 ;
		break ;
	}
	return Loc_Pin_Number ;
}


/*******************************************************************************************************************
 * 			@Fn								-MCAL_GPIO_INIT																									*
 * 			@brief 						-GPIO INIT Congigration of specific pin 																	*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used
 * 			@param [in]				-PIN_config	pointer to a GPIO_PINCONFIG_t structure														   	*
 * 												-contain the configratoiin of GPIO PIN
 * 			@retval						-NONE																														*
 * 			Note							--stm32f103c6 has GPIO A : E BUT LQFP48 has A ,B 	,part of c , d pins																														*
 ********************************************************************************************************************/
void MCAL_GPIO_INIT(GPIO_Typedef * GPIOX,GPIO_PinCongif_t* pinconfig)
{
	volatile uint32_t* Loc_Config_Regester = NULL ;
	uint8_t	 Loc_Pin_Congif	=	0 ;
	Loc_Config_Regester = (pinconfig->GPIO_PinNumber<GPIO_PIN_8)? 	&GPIOX->CRL	:	&GPIOX->CRH 	 ;
	*(Loc_Config_Regester) &=~(0x0f<<(Get_CRLH_Position(pinconfig->GPIO_PinNumber)));
	if (pinconfig->GPIO_MODE==GPIO_Mode_OUTPUT_OD || pinconfig->GPIO_MODE==GPIO_Mode_OUTPUT_PP||\
		pinconfig->GPIO_MODE==GPIO_Mode_OUTPUT_AF_OD ||pinconfig->GPIO_MODE==GPIO_Mode_OUTPUT_AF_PP)
	{
		Loc_Pin_Congif = ((((pinconfig->GPIO_MODE-4)<<2) | (pinconfig->GPIO_OutPut_Speed))&0x0f) ;
	}
	else
	{
		if((pinconfig->GPIO_MODE==GPIO_Mode_INPUT_FLO)||(pinconfig->GPIO_MODE==GPIO_Mode_Analog))
		{
			Loc_Pin_Congif = ((((pinconfig->GPIO_MODE)<<2) |0x0)&0x0f) ;
		}
		else if (pinconfig->GPIO_MODE==GPIO_Mode_AF_INPUT)
		{
			Loc_Pin_Congif = (((GPIO_Mode_INPUT_FLO<<2) |0x0)&0x0f) ;
		}
		else
		{
			Loc_Pin_Congif =(( (pinconfig->GPIO_MODE<< 2) |0x0)&0x0F) ;
			if (pinconfig->GPIO_MODE == GPIO_Mode_INPUT_PU)
			{
				GPIOX->ODR |= pinconfig->GPIO_PinNumber ;
			}
			else
			{
				GPIOX->ODR &=~ (pinconfig->GPIO_PinNumber) ;
			}
		}
	}
	(*Loc_Config_Regester) |= ((Loc_Pin_Congif)<<Get_CRLH_Position(pinconfig->GPIO_PinNumber)) ;

}

/*******************************************************************************************************************
 * 			@Fn								-MCAL_GPIO_DeINIT																											*
 * 			@brief 						-iReset All GPIO Regester																										*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@retval						-NONE																																	*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
void MCAL_GPIO_DeINIT(GPIO_Typedef * GPIOX)
{
	if (GPIOX==GPIOA)
		{
				RCC->APB2RSTR |= (1<<2);
				RCC->APB2RSTR &= ~(1<<2);
		}else if (GPIOX == GPIOB)
		{
				RCC->APB2RSTR |= (1<<3);
				RCC->APB2RSTR &= ~(1<<3);
		}else if (GPIOX == GPIOC)
		{
				RCC->APB2RSTR |= (1<<4);
				RCC->APB2RSTR &= ~(1<<4);
		}else if (GPIOX == GPIOD)
		{
				RCC->APB2RSTR |= (1<<5);
				RCC->APB2RSTR &= ~(1<<5);
		}else if ( GPIOX == GPIOE)
		{
				RCC->APB2RSTR |= (1<<6);
				RCC->APB2RSTR &= ~(1<<6);
		}else
		{
			//  Error Handler
		}
	// another way to reset port
	//GPIOX->BRR 	= 	0x00000000;
	//GPIOX->BSRR 	= 	0x00000000;
	//GPIOX->CRH 	= 	0x44444444;
	//GPIOX->CRL 	= 	0x44444444;
	//GPIOX->IDR 	=  ;  Read only
	//GPIOX->LCKR 	= 	0x00000000 ;
	//GPIOX->ODR 	= 	0x00000000 ;
}
/*******************************************************************************************************************
 * 			@Fn							-MCAL_GPIO_READ_PIN																										*
 * 			@brief 						-Read speific pin 																													*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@param [in]				-PIN_Number : set pin number according GPIO_PINS_DEFINE 											*
 * 			@retval					- The input pin value  two values (HIGH _ LOW)																	*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number)
{
	uint8_t Loc_Bit_Status ;
	if ((GPIOX->IDR& (uint16_t)Pin_Number) != (uint32_t)LOW)
	{
		Loc_Bit_Status = HIGH ;
	}else
	{
		Loc_Bit_Status = LOW ;
	}
	return Loc_Bit_Status ;
}
/*******************************************************************************************************************
 * 			@Fn							-MCAL_GPIO_READ_PORT																									*
 * 			@brief 						-Read speific port 																												*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@retval					- PORT_VALUE																														*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef * GPIOX )
{
	uint16_t Loc_Port_Value ;
	Loc_Port_Value = (uint16_t)(GPIOX->IDR);
	return Loc_Port_Value ;
}
/*******************************************************************************************************************
 * 			@Fn							-MCAL_GPIO_Write_PIN																										*
 * 			@brief 						-write value on specific pin 																									*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@param [in]				-Pin_Number : specific pin to write on 																				*
 * 			@param [in]				-value : PIN VALUE																												*
 * 			@retval					- NONE																																*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
void MCAL_GPIO_Write_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number,uint8_t value)
{
	if (value!=LOW)
	{
	//GPIOX->ODR |= (uint32_t)Pin_Number ;
		GPIOX->BSRR = (uint32_t)Pin_Number ;
	}else
	{
	//	GPIOX->ODR &= ~((uint32_t)Pin_Number) ;
		GPIOX->BRR = (uint32_t)Pin_Number ;
	}
}
/*******************************************************************************************************************
 * 			@Fn							-MCAL_GPIO_Write_PORT																									*
 * 			@brief 						-Read speific port 																												*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@param [in]				-value : PIN VALUE																												*
 * 			@retval					- NONE																																*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
void MCAL_GPIO_Write_PORT(GPIO_Typedef * GPIOX,uint8_t value)
{
	GPIOX->ODR = (uint32_t)value ;
}
/*****************************************************************************
 * **************************************
 * 			@Fn							-MCAL_GPIO_TOGGLE_PIN																									*
 * 			@brief 						-toggle value of specific pin 																								*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@param [in]				-Pin_Number : specific pin to write on 																				*
 * 			@retval					- NONE																																*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number)
{
	GPIOX->ODR ^= Pin_Number ;
}
/*******************************************************************************************************************
 * 			@Fn							-MCAL_GPIO_LOCKPIN																											*
 * 			@brief 						-Lock Specific pin 																												*
 * 			@param [in]				-GPIOX : x can be  A:E depending on device used																*
 * 			@param [in]				-Pin_Number : specific pin to write on 																				*
 * 			@retval					- LOCK_ENABLE if pin locked or LOCK_ERROR if not																																*																									*
 * 			Note							-NONE																																	*
 ********************************************************************************************************************/
uint8_t MCAL_GPIO_LOCKPIN(GPIO_Typedef * GPIOX,uint16_t Pin_Number)
{
	volatile uint32_t temp = 1<<16 ;
	temp |= Pin_Number ;
	GPIOX->LCKR = temp ;
	GPIOX->LCKR = Pin_Number ;
	GPIOX->LCKR = temp ;
	temp = GPIOX->LCKR ;
	if ((uint32_t)GPIOX->LCKR &(1<<16) )
	{
		return LOCK_ENABLE ;
	}else
	{
		return LOCK_ERROR ;
	}
}






