/*
 * DIO.h
 *
 * Created: 12/13/2022 11:58:39 AM
 *  Author: karim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Regesters.h"
#include "util\delay.h"
#include "..\utilities\Types.h"
#include "..\utilities\utils.h"

// All Driver Macros
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

//** PORT states **//
#define LOW 0
#define HIGH 1

//** GPIO PINS **//

#define GPIO_PIN_0							0
#define GPIO_PIN_1							1
#define GPIO_PIN_2							2
#define GPIO_PIN_3							3
#define GPIO_PIN_4							4
#define GPIO_PIN_5							5
#define GPIO_PIN_6							6
#define GPIO_PIN_7							7


//** PORT directions **//
#define IN 0
#define OUT 1

// DIO_PrortoTypes
void DIO_Write_Pin_Dir( uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction ) ;
void DIO_Write_Port_Dir( uint8_t PortNumber , uint8_t Direction ) ;
void DIO_Write_Pin( uint8_t PortNumber , uint8_t PinNumber , uint8_t value  ) ;
void DIO_Write_Port( uint8_t PortNumber , uint8_t value  ) ;
void DIO_Read( uint8_t PortNumber , uint8_t PinNumber , uint8_t* value  );
void DIO_Toggle_Pin( uint8_t PortNumber , uint8_t PinNumber  );
void DIO_Toggle_Port( uint8_t PortNumber   );



#endif /* DIO_H_ */