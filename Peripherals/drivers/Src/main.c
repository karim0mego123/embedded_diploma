#include "UART.h"
#include "SPI.h"
#include "LCD.h"
#include "I2C.h"

void Clock_Enable()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

#include "UART.h"


//Global Variable
uint16_t ch ;


int main(void)
{
	USART_Conig_t config ;
	Clock_Enable() ;
	config.BaudRate = USART_BaudRate_9600;
	config.HWFlowCtl = USART_HWFlowCtl_NONE;
	config.IRQ_Enable = USART_IRQ_Enable_NONE;
	config.P_IRQ_CallBack = NULL ;
	config.Parity = USART_Parity_NONE;
	config.PayLoad_Length = USART_PayLoad_Length8B ;
	config.StopBits = USART_StopBits_One ;
	config.USART_MODE = USART_MODE_TX_RX;

	MCAL_USART_Init(USART1 , &config);
	MCAL_USART_GPIO_Set_Pins(USART1);
	while (1)
	{
		MCAL_USART_RecieveData(USART1, &ch , Enable );
		MCAL_USART_SendData(USART1  , &ch , Enable );
	}


}

