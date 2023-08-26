/*
 * UART.c
 *
 *  Created on: Feb 16, 2023
 *      Author: karim
 */
#include "UART.h"
/*
 * =============================================================
 * 							GENEREIC VARIABLES
 * =============================================================
 */
USART_Conig_t* Global_Usart_ConFig = NULL ;		//need to update cancel this global and pass the uart config to all functions

/*******************************************************************************************************************
 * 	@Fn               -MCAL_UART_INIT
 * 	@brief            -Initialize UART (Asynchronous Only)
 *	param[in]         -USARTX :where x can be 1,2,3 depending on device used
 *	param[in]          -USART_Config :all the uart configuration
 * 	@retval           -none
 * 	Note              -support for now ASynch mode and clock 8 HZ
 ********************************************************************************************************************/
void MCAL_USART_Init(USART_Typedef* USARTX , USART_Conig_t* USART_Config)
{
	uint32_t PCLK , BRR ;
	Global_Usart_ConFig = USART_Config ;

	//enable the clock for given USART Peripheral
	if (USARTX == USART1)
	{
		RCC_USART1_CLK_EN();
	}
	else if (USARTX == USART2)
	{
		RCC_USART2_CLK_EN();
	}
	else if (USARTX == USART3)
	{
		RCC_USART3_CLK_EN();
	}

	USARTX->CR1 |= (1<<13) ;							//Enable USART Module	USART_CR1  Bit 13 UE: USART enable
	USARTX->CR1 |= USART_Config->USART_MODE ;			//Enable USART Tx and Rx engines according to the USART_Mode configuration item
	//	USART_CR1 Bit 3 TE: Transmitter enable & Bit 2 RE: Receiver enable

	USARTX->CR1 |= USART_Config->PayLoad_Length ;		// enable Payload width 	USARTx->CR1  Bit 12 M: Word length

	USARTX->CR1 |= USART_Config->Parity ;				//Configuration of parity control bit fields
	// USARTx->CR1 	Bit 10 PCE: Parity control enable     Bit 9 PS: Parity selection

	USARTX->CR2 |= USART_Config->StopBits ;				//configure stop bits	USART_CR2  Bits 13:12 STOP: STOP bits
	USARTX->CR3 |= USART_Config->HWFlowCtl ;			//USART hardware flow control	USART_CR3  Bit 9 CTSE: CTS enable   Bit 8 RTSE: RTS enable

	//Configure baud rate
	//PCLK2 For USART1
	//PCLK1 for USART2 ,3
	if(USARTX == USART1)
	{
		PCLK = MCAL_RCC_GetPCLK2Freq();
	}
	else
	{
		PCLK = MCAL_RCC_GetPCLK1Freq();
	}
	BRR = USART_BRR_Register(PCLK,USART_Config->BaudRate);
	USARTX->BRR = BRR ;

	if (USART_Config->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		USARTX->CR1 |= USART_Config->IRQ_Enable ;
		//enable NVIC for USART IRQ
		if (USARTX == USART1)
		{
			NVIC_IRQ37_USART1_Enable ;
		}
		else if (USARTX == USART2)
		{
			NVIC_IRQ38_USART2_Enable ;
		}
		else if (USARTX == USART3)
		{
			NVIC_IRQ39_USART3_Enable ;
		}
	}
}
/**================================================================
 * @Fn               -MCAL_UART_DeINIT
 * @brief            -DeInitialize UART (Asynchronous Only)
 *param[in]         -USARTx :where x can be 1,2,3 depending on device used
 * @retval           -none
 * Note              -Reset the model by RCC
 */
/*******************************************************************************************************************
 * 		@Fn               -MCAL_UART_DeINIT
 * 		@brief            -DeInitialize UART (Asynchronous Only)
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 * 		@retval           -none
 * 		Note              -Reset the model by RCC																													*
 ********************************************************************************************************************/
void MCAL_USART_DeInit(USART_Typedef* USARTX )
{
	if (USARTX == USART1)
	{
		RCC_USART1_Reset();
		NVIC_IRQ37_USART1_Disable ;
	}
	else if (USARTX == USART2)
	{
		RCC_USART2_Reset();
		NVIC_IRQ38_USART2_Disable ;
	}
	else if (USARTX == USART3)
	{
		RCC_USART3_Reset();
		NVIC_IRQ39_USART3_Disable ;
	}

}



/*******************************************************************************************************************
 * 		@Fn               - MCAL_UART_SendData
 * 		@brief            -send buffer on UART
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 *		param[in]         -PtxBuffer: the buffer that will be transmitted
 *		param[in]          -PollingEn enable or disable the polling
 * 		@retval           -none
 * 		Note              -Should initialize UART First
 * 							When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
 *							the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
 *							because it is replaced by the parity.
 *  						When receiving with the parity enabled, the value read in the MSB bit is the received parity
 *
 ********************************************************************************************************************/
void MCAL_USART_SendData(USART_Typedef* USARTX , uint16_t *PtxBuffer ,Polling_mechanism_t PollingEn )
{
	//wait until TXE is set
	if(PollingEn==Enable)
		while(!(USARTX->SR &(1<<7)));

	if (Global_Usart_ConFig->PayLoad_Length == USART_PayLoad_Length9B)

	{
		USARTX->DR = (*PtxBuffer&(uint16_t)0x01FF);
	}
	else
	{
		USARTX->DR = (*PtxBuffer&(uint8_t)0xFF);
	}

}
void MCAL_USART_Send_String(USART_Typedef* USARTX , uint8_t *PtxBuffer ,Polling_mechanism_t PollingEn)
{
	uint8_t Loc_Count = 0 ;
	//wait until TXE is set
	if(PollingEn==Enable)
		while(!(USARTX->SR &(1<<7)));
	while(PtxBuffer[Loc_Count] != 0 )
	{
		MCAL_USART_SendData(USART1, &PtxBuffer[Loc_Count], Enable);
		Loc_Count++;
	}
}
/*******************************************************************************************************************
 * 		@Fn               - MCAL_USAET_RecieveData
 * 		@brief            -receive buffer from UART
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 *		param[in]         -PtxBuffer: the recieved buffer
 *		param[in]          -PollingEn enable or disable the polling
 * 		@retval           -none
 * 		Note              -none																										*
 ********************************************************************************************************************/
void MCAL_USART_RecieveData(USART_Typedef* USARTX , uint16_t *PtxBuffer ,Polling_mechanism_t PollingEn )
{
	//wait until RXNE is set
	if (PollingEn == Enable)
	{
		while(!(USARTX->SR&(1<<5)));
	}
	if(Global_Usart_ConFig->PayLoad_Length == USART_PayLoad_Length9B)
	{
		if(Global_Usart_ConFig->Parity == USART_Parity_NONE)
		{
			//no parity so all 9bits are data
			*((uint16_t*)PtxBuffer) = USARTX->DR ;
		}
		else
		{
			//if parity is used so 8bit is data and the last one is parity
			*((uint16_t*)PtxBuffer) =( USARTX->DR & (uint8_t)0xFF);
		}
	}
	else //8 bit data
	{
		if(Global_Usart_ConFig->Parity == USART_Parity_NONE)
		{
			//no parity so all 9bits are data
			*((uint16_t*)PtxBuffer) = (USARTX->DR   & (uint8_t)0xFF);

		}else{
			//if parity is used so 8bit is data and the last one is parity
			*((uint16_t*)PtxBuffer) =( USARTX->DR & (uint8_t)0x7F);
		}
	}
}
void MCAL_USART_Wait_Tc (USART_Typedef* USARTX)
{
	while(!(USARTX->SR&1<<6));
}
/*******************************************************************************************************************
 * 		@Fn               - MCAL_USART_GPIO_Set_Pins
 * 		@brief            -set the Gpio pins
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 * 		@retval           -none
 * 		Note              -should enable the corresponding ALT &GPIO in RCC CLOCK AND called after MCAL_UART_INIT()																													*
 ********************************************************************************************************************/
void MCAL_USART_GPIO_Set_Pins(USART_Typedef* USARTX )
{
	GPIO_PinCongif_t pincfg;
	if(USARTX == USART1)
	{
		//from alternative pin table for LQF and see recommended gpio pins configuration table
		//PA9 TX
		//PA10 RX
		//PA11 CTS
		//PA12 RTS

		//PA9 TX
		pincfg.GPIO_PinNumber = GPIO_PIN_9 ;
		pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
		pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOA, &pincfg) ;

		//PA10 RX
		pincfg.GPIO_PinNumber = GPIO_PIN_10   ;
		pincfg.GPIO_MODE = GPIO_Mode_AF_INPUT ;
		MCAL_GPIO_INIT(GPIOA, &pincfg) ;

		//PA11 CTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_CTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_11 ;
			pincfg.GPIO_MODE = GPIO_Mode_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA, &pincfg) ;
		}

		//PA12 RTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_12 ;
			pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
			pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pincfg) ;
		}

	}

	else if(USARTX == USART2)
	{
		//from alternative pin table for LQF and see recommended gpio pins configuration table
		//PA2 TX
		//PA3 RX
		//PA0 CTS
		//PA1 RTS

		//PA2 TX
		pincfg.GPIO_PinNumber = GPIO_PIN_2 ;
		pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
		pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOA, &pincfg) ;

		//PA3 RX
		pincfg.GPIO_PinNumber = GPIO_PIN_3 ;
		pincfg.GPIO_MODE = GPIO_Mode_AF_INPUT;
		MCAL_GPIO_INIT(GPIOA, &pincfg) ;

		//PA0 CTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_CTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_0 ;
			pincfg.GPIO_MODE = GPIO_Mode_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA, &pincfg) ;
		}
		//PA1 RTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_1 ;
			pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
			pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pincfg) ;

		}

	}

	else if(USARTX == USART3)
	{
		//from alternative pin table for LQF and see recommended gpio pins configuration table
		//PB10 TX
		//PB11 RX
		//PB13 CTS
		//PA14 RTS

		//PB10 TX
		pincfg.GPIO_PinNumber = GPIO_PIN_10 ;
		pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
		pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOB, &pincfg) ;

		//PB11 RX
		pincfg.GPIO_PinNumber = GPIO_PIN_11 ;
		pincfg.GPIO_MODE = GPIO_Mode_AF_INPUT;
		MCAL_GPIO_INIT(GPIOB, &pincfg) ;

		//PA13 CTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_CTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_13 ;
			pincfg.GPIO_MODE = GPIO_Mode_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOB, &pincfg) ;
		}
		//PA12 RTS
		if(Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS || Global_Usart_ConFig->HWFlowCtl == USART_HWFlowCtl_RTS_CTS)
		{
			pincfg.GPIO_PinNumber = GPIO_PIN_14 ;
			pincfg.GPIO_MODE = GPIO_Mode_OUTPUT_AF_PP;
			pincfg.GPIO_OutPut_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA, &pincfg) ;
		}

	}
}



//ISR
void USART1_IRQHandler(void)
{
	Global_Usart_ConFig->P_IRQ_CallBack();
}

void USART2_IRQHandler(void)
{
	Global_Usart_ConFig->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
	Global_Usart_ConFig->P_IRQ_CallBack();
}



