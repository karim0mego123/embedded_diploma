/*
 * LM35_Sensor.c
 *
 * Created: 4/29/2023 2:57:07 AM
 *  Author: karim
 */ 
#include "LM35_Sensor.h"

ES_t LM35_Init(uint8_t Channel_id) 
{
	ES_t Loc_Error_State = NO_Error ;
	
	ADC_INIT();
	ADC_Enable();
	ADC_Select_Channel(Channel_id);
	DIO_Write_Pin_Dir(PORT_A,Channel_id,LOW);
	
	return Loc_Error_State ; 
}
ES_t LM35_Read(uint16_t* value)
{
	ES_t Loc_Error_State = NO_Error ;
	
	ADC_Start();
	ADC_PollingSystem();
	ADC_ReadHighValue(value);
	*value = ((( *value )* 0.0048828 )/0.01);
	
	return Loc_Error_State ; 
}
