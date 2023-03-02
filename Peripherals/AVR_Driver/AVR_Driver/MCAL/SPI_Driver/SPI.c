/*
 * SPI.c
 *
 * Created: 2/27/2023 4:00:03 PM
 *  Author: karim
 */ 
#include "SPI.h"
#include "ErrorState.h"
#include "SPI_Private.h"
#include "SPI_ConFig.h"

ES_t MCAL_SPI_Init()
{

    ES_t Init_Status = NO_Error ; 
	
    #if SPI_MODE == MASTER_MODE
    {
       SPCR |= (1<<MSTR) ; 
        // MAX BaudRate
        SPCR |= (1<<SPR0);
  //    SPCR &= ~(1<<SPR1);
       Init_Status = NO_Error ; 
    }
    #elif SPI_MODE == SLAVE_MODE
    {
        SPCR &=~ (1<<MSTR) ;
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if DATA_ORDER == MSB_FIRST
    {
        SPCR &=~ (1<<DORD);
        Init_Status = NO_Error ; 
    }    
    #elif DATA_ORDER == LSB_FIRST 
    {
        SPCR |= (1<<DORD);
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if SAMPLING_MODE == 0
    {
        SPCR &=~(1<<CPOL);
        SPCR &=~(1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 1
    {
        SPCR &=~(1<<CPOL);
        SPCR |= (1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 2
    {
        SPCR |= (1<<CPOL);
        SPCR &=~(1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 3
    {
        SPCR |= (1<<CPOL);
        SPCR |= (1<<CPHA);
         Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if SPEED_MODE == NORMAL_SPEED
    {
	    SPCR &=~ (1<<SPI2X);
        Init_Status = NO_Error ; 
    }
    #elif  SPEED_MODE == DOUBLE_SPEED 
    {
	    SPSR |= (1<<SPI2X);
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif
	
    SPCR |= (1<<SPE) ; //  SPI Enable
    return Init_Status ;
}
uint8_t MCAL_SPI_Send_Data(uint8_t DataSend )
{
	SPDR = DataSend ; 
	while(!(SPSR&(1<<SPIF)));
	return SPDR ;
}
uint8_t MCAL_SPI_Recieve_Data(uint8_t DataSend )
{
	SPDR = DataSend ;
	while(!(SPSR&(1<<SPIF)));
	return SPDR ;
}
ES_t MCAL_SPI_TX_RX(uint8_t DataSend , uint8_t* DataRecieve)
{
	 ES_t Init_Status = NO_Error ;
	SPDR = DataSend ;
	while(!(SPSR&(1<<SPIF)));
	*DataRecieve = SPDR ;
	return Init_Status ;
}
void MCAL_SPI_Set_Pins_Master(void)
{
	DIO_Write_Pin_Dir(PORT_B,SS,HIGH);
	DIO_Write_Pin_Dir(PORT_B,MOSI,HIGH);
	DIO_Write_Pin_Dir(PORT_B,MISO,LOW);	
	DIO_Write_Pin_Dir(PORT_B,SCK,HIGH);
}
void MCAL_SPI_Set_Pins_SLAVE(void)
{
	DIO_Write_Pin_Dir(PORT_B,SS,LOW);
	DIO_Write_Pin_Dir(PORT_B,MOSI,LOW);
	DIO_Write_Pin_Dir(PORT_B,MISO,HIGH);
	DIO_Write_Pin_Dir(PORT_B,SCK,LOW);
}