#include "UART.h"
#include "SPI.h"
uint16_t Buffer;
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#define Master_Mode

void Clock_Enable()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}
void RecieveString(void)
{
#ifdef Master_Mode
	MCAL_USART_RecieveData(USART1,&Buffer,Disable) ;
	MCAL_USART_SendData(USART1,&Buffer,Enable) ;
	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_4, LOW);
	MCAL_SPI_TX_RX(SPI1, &Buffer, Enable);
	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_4, HIGH);
#endif
}

int main ()
{
	GPIO_PinCongif_t PinConfig ;
	USART_Conig_t Usart_Config ;
	SPI_ConFig_t Spi_ConFig ;

	Clock_Enable();

	Usart_Config.BaudRate       = 	 USART_BaudRate_9600 ;
	Usart_Config.HWFlowCtl 		=    USART_HWFlowCtl_NONE ;
	Usart_Config.IRQ_Enable	    =	 USART_IRQ_Enable_RXNEIE;
	Usart_Config.P_IRQ_CallBack =	 RecieveString ;
	Usart_Config.Parity 		=	 USART_Parity_NONE ;
	Usart_Config.PayLoad_Length =    USART_PayLoad_Length8B ;
	Usart_Config.StopBits 		=	 USART_StopBits_One ;
	Usart_Config.USART_MODE 	=	 USART_MODE_TX_RX ;
	MCAL_USART_Init(USART1,&Usart_Config) ;
	MCAL_USART_GPIO_Set_Pins(USART1);

	Spi_ConFig.CLKPhase = SPI_CLKPhase_2ndEDGE_first_data_capture_edge ;
	Spi_ConFig.CLKPolarity = SPI_CLKPolarity_High_when_idle ;
	Spi_ConFig.Data_Size = SPI_Data_Size_8BIT ;
	Spi_ConFig.Communication_Mode = SPI_Communication_Mode_2LINES ;
	Spi_ConFig.SPI_BAUDRATEPrescaler = SPI_BAUDRATEPrescaler_8 ;
	Spi_ConFig.frame_format = SPI_frame_format_MSB_transmitted_first ;

#ifdef	Master_Mode
	Spi_ConFig.Device_Mode = SPI_Device_Mode_Master ;
	Spi_ConFig.IRQ_Enable = SPI_IRQ_Enable_NONE ;
	Spi_ConFig.NSS = SPI_NSS_Soft_NSSInternalSoft_set ;
	Spi_ConFig.P_IRQ_CallBack = NULL ;

	PinConfig.GPIO_PinNumber = GPIO_PIN_4 ;
	PinConfig.GPIO_MODE = GPIO_Mode_OUTPUT_PP ;
	PinConfig.GPIO_OutPut_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOA, &PinConfig);
	MCAL_GPIO_Write_PIN(GPIOA,GPIO_PIN_4, HIGH);
#endif

	MCAL_SPI_INIT(SPI1, &Spi_ConFig);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	while(1)
	{
	}
	return 0 ;
}
