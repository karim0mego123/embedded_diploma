/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 
#include "DIO.h"
#include "Switch_init.h"
#include "LED.h"

#define SW_Num		2

int main()
{	
	SW_t Switch[SW_Num] = { {PORT_A,GPIO_PIN_0,PULL_UP} ,
							{PORT_A,GPIO_PIN_1,PULL_UP}  } ;

	LED_t LED[2] = {	{PORT_B,GPIO_PIN_0,Source_Current} ,
						{PORT_B,GPIO_PIN_1,Sink_Current} } ;
	
	LED_Init_State(&LED[0],OFF);
	LED_Init_State(&LED[1],OFF);
					  
	Switch_Init(Switch,SW_Num);
	while(1)
	{
		if (Switch_Get_State(&Switch[0])==0)
		{
			LED_ON(&LED[0]);
			Debouncing(PINA,GPIO_PIN_0);
			LED_OFF(&LED[0]);
		}
		if (Switch_Get_State(&Switch[1])==0)
		{
			LED_ON(&LED[1]);		
			Debouncing(PINA,GPIO_PIN_1);
			LED_OFF(&LED[1]);
		}
	}
	return 0 ; 
}












