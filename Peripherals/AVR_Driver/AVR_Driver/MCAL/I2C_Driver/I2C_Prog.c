/*
 * I2C.c
 *
 * Created: 4/19/2023 2:43:03 PM
 *  Author: karim
 */ 
#include "I2C_int.h"

ES_t IIC_INIT() 
{
	ES_t Local_StateError = NO_Error ; 
	
	#if IIC_MODE == IIC_MASTER
		TWBR = (uint8_t)BITRATE(IIC_CLOCK_SPEED) ; 
	#if IIC_PRES == 1UL
		TWSR &=~ (3<<0) ; 
		#endif
	#elif IIC_MODE == IIC_SLAVE
	
	#endif
	
	
	return Local_StateError ; 
}

ES_t IIC_StartCondition() 
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
	
}

ES_t IIC_ReapeatedStartCondition()
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
	
}

ES_t IIC_StopCondition()
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
	
}

ES_t IIC_WriteSlaveAddress( uint8_t Copy_SlaveAddress , uint8_t Copy_Operation ) 
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
	
}

ES_t IIC_WriteData(uint8_t Copy_Data) 
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
	
}

ES_t IIC_CheckMyAddress() 
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
}

ES_t II2_ReadData(uint8_t * Copy_Data) 
{
	ES_t Local_StateError = NO_Error ;
	
	
	
	return Local_StateError ;
}
