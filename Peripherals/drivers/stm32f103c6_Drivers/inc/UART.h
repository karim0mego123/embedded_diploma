/*
 * UART.h
 *
 *  Created on: Feb 16, 2023
 *      Author: karim
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f103xx.h"
#include "GPIO.h"
#include "RCC.h"

// Configurtion Structure
typedef struct
{
	uint8_t				USART_MODE 		; 			//  Specifiy Tx Rx Enable Disable
													//  This Parameter must be set based on @res USART_MODE_define

	uint32_t			BaudRate		;			//  Specifiy BaudRate
													//  This Parameter must be set based on @res USART_BaudRate_define

	uint8_t  			PayLoad_Length 	;			//  Specifiy Word Length
													//  This Parameter must be set based on @res USART_PayLoad_Length_define

	uint8_t 			Parity 			;			//  Specifiy Parity
													//  This Parameter must be set based on @res USART_Parity_define

	uint8_t				StopBits		; 			//  Specifiy number of StopBits
													//  This Parameter must be set based on @res StopBits_define

	uint8_t     		HWFlowCtl		;			//  Specifiy number of HWFlowCtl
													//  This Parameter must be set based on @res HWFlowCtl_define

	uint8_t 			IRQ_Enable		;			//  Specifiy IRQ_Enablel
													//  This Parameter must be set based on @res IRQ_Enable_define

	void (*P_IRQ_CallBack)(void)		;			// Set The C Function() With be called once the IRQ Happen

}USART_Conig_t;

//			 								Reference Macros

//@res USART_MODE_define
#define	USART_MODE_TX		(uint32_t)(1<<3)	// Bit 3 TE: Transmitter enable
#define USART_MODE_RX		(uint32_t)(1<<2)	// Bit 2 RE: Receiver enable
#define USART_MODE_TX_RX	(uint32_t)(1<<3 | 1<<2)

// @res USART_BaudRate_define
// from Table 192. Error calculation for programmed baud rates
#define USART_BaudRate_2400					2400
#define USART_BaudRate_9600					9600
#define USART_BaudRate_19200				19200
#define USART_BaudRate_57600				57600
#define USART_BaudRate_115200				115200
#define USART_BaudRate_230400				230400
#define USART_BaudRate_460800				460800
#define USART_BaudRate_921600				921600
#define USART_BaudRate_2250000				2250000
#define USART_BaudRate_4500000				4500000

// @res USART_PayLoad_Length_define
// Bit 12 M: Word length
// This bit determines the word length. It is set or cleared by software.
// 0: 1 Start bit, 8 Data bits, n Stop bit
// 1: 1 Start bit, 9 Data bits, n Stop bit
#define USART_PayLoad_Length8B				(uint32_t)(0)
#define USART_PayLoad_Length9B				(uint32_t)(1<<12)

// @res USART_Parity_define
#define USART_Parity_NONE					(uint32_t)(0)
#define USART_Parity_EVEN					(uint32_t)(1<<10)
#define USART_Parity_ODD					(uint32_t)( 1<<10 | 1<<9 )

// @res StopBits_define
#define USART_StopBits_Half					(uint32_t)(1<<12)
#define USART_StopBits_One					(uint32_t)(0)
#define USART_StopBits_1_Half				(uint32_t)(3<<12)
#define USART_StopBits_Two					(uint32_t)(2<<12)

// @res HWFlowCtl_define
#define USART_HWFlowCtl_NONE				(uint32_t)(0)
#define USART_HWFlowCtl_RTS					(uint32_t)(1<<8)
#define USART_HWFlowCtl_CTS					(uint32_t)(1<<9)
#define USART_HWFlowCtl_RTS_CTS				(uint32_t)(1<<8|1<<9)


// @res IRQ_Enable_define
#define USART_IRQ_Enable_NONE				(uint32_t)(0)
#define USART_IRQ_Enable_TXE				(uint32_t)(1<<7)
#define USART_IRQ_Enable_TC					(uint32_t)(1<<6)
#define USART_IRQ_Enable_RXNEIE				(uint32_t)(1<<5)
#define USART_IRQ_Enable_PE					(uint32_t)(1<<8)

//Baudrate calculation
//USARTDIV = fclk /(16*Baudrate)
//USARTDIV_Mul100  = (uint32)(100*fclk)/(16*Baudrate)
//USARTDIV_Mul100  = (uint32)(25*fclk)/(4*Baudrate)
//DIV_Mantissa_MUL100 = Integar part (USARTDIV) *100
//DIV_Mantissa = Integar part (USARTDIV)
//DIV_Fraction = ((USARTDIV_Mul100 - DIV_Mantissa_MUL100 ) * 16 )/100)

#define USARTDIV(_PCLK_,_BAUD_)          		 (uint32_t)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_Mul100(_PCLK_,_BAUD_)           (uint32_t)((25 * _PCLK_)/(4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)           (uint32_t) (USARTDIV(_PCLK_,_BAUD_) * 100)
#define Mantissa(_PCLK_,_BAUD_)                	 (uint32_t) (USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_)            	 (uint32_t) (( USARTDIV_Mul100(_PCLK_,_BAUD_)  - Mantissa_MUL100(_PCLK_,_BAUD_)) * 16 )
#define USART_BRR_Register(_PCLK_,_BAUD_)        ( (Mantissa(_PCLK_,_BAUD_)) <<4 ) | ( (DIV_Fraction(_PCLK_,_BAUD_)) & 0xF)

typedef enum
{
	Enable ,
	Disable
}Polling_Mechanism_t;
//               				APIS

void MCAL_USART_Init(USART_Typedef* USARTX , USART_Conig_t* USART_Config);
void MCAL_USART_DeInit(USART_Typedef* USARTX );
void MCAL_USART_GPIO_Set_Pins(USART_Typedef* USARTX );
void MCAL_USART_SendData(USART_Typedef* USARTX , uint16_t *PtxBuffer ,Polling_Mechanism_t PollingEn );
void MCAL_USART_RecieveData(USART_Typedef* USARTX , uint16_t *PtxBuffer ,Polling_Mechanism_t PollingEn );
void MCAL_USART_Send_String(USART_Typedef* USARTX , uint8_t *PtxBuffer ,Polling_Mechanism_t PollingEn);


#endif /* INC_UART_H_ */



