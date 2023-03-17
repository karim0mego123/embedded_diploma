/*
 * Switch_init.h
 *
 * Created: 3/5/2023 4:42:06 PM
 *  Author: karim
 */ 


#ifndef SWITCH_INIT_H_
#define SWITCH_INIT_H_

#include "DIO.h"

typedef struct{
	uint8_t SW_PORT_ID ;
	uint8_t SW_PIN_ID ;
	PIN_Status_n SW_Status ;
}SW_t ;


void Switch_Init(SW_t* Copy_Switch , uint8_t SW_Num ) ; 

uint8_t Switch_Get_State(SW_t* Copy_Switch  ) ;

void Debouncing( uint8_t PIN , uint8_t PIN_Number ) ;

#endif /* SWITCH_INIT_H_ */