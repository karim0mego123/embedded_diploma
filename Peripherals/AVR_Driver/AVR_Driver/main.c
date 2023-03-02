/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 
#define F_CPU	1000000U
#include "DIO.h"
#include "SPI.h"

#define MASTER	
//2#define SLAVE

int main()
{
	#ifdef MASTER
	MCAL_SPI_Set_Pins_Master();
	#endif

	#ifdef SLAVE
	MCAL_SPI_Set_Pins_SLAVE();
	#endif
		
	DDRA = 0xFF ; 
	MCAL_SPI_Init();
	while(1)
	{
		#ifdef MASTER
		uint8_t DataSend1 ; 
		for (DataSend1 = 0 ; DataSend1<=7 ; DataSend1++)
		{
			_delay_ms(1000);
			PORTA = MCAL_SPI_Send_Data((1<<DataSend1));
		}
		#endif
		
		#ifdef SLAVE
		uint8_t DataSend2 ;
		for (DataSend2= 0 ; DataSend2<=7 ; DataSend2++)
		{
			_delay_ms(1000);
			PORTA = MCAL_SPI_Recieve_Data((1<<DataSend2));
		}
		#endif
		
	}
	
	return 0 ;  
}












