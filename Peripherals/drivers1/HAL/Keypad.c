/*
 * Keypad.c
 *
 * Created: 1/29/2023 12:07:54 AM
 *  Author: karim
 */ 
#include "Keypad.h"
uint16_t ROWS[]={R0,R1,R2,R3};
uint16_t COL[] ={C0,C1,C2,C3};
void KeYPad_Init()
{
	GPIO_PinCongif_t PinCongif ;
	for(uint8_t i = 0 ; i < 4 ; i++ )
	{
		PinCongif.GPIO_PinNumber = ROWS[i] ;
		PinCongif.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
		PinCongif.GPIO_OutPut_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_INIT(KeyPAd_PORT_Data,&PinCongif);
	}
	for(uint8_t i = 0 ; i < 4 ; i++ )
	{
		PinCongif.GPIO_PinNumber = COL[i] ;
		PinCongif.GPIO_MODE=GPIO_Mode_OUTPUT_PP ;
		PinCongif.GPIO_OutPut_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_INIT(KeyPAd_PORT_Data,&PinCongif);
	}
	MCAL_GPIO_Write_PORT(KeyPAd_PORT_Data, 0xFF);
}
char KeyPAd_Scan()
{
	uint16_t i,j,Result='a';
	for(i = 0 ; i < 4 ; i++)
	{
		MCAL_GPIO_Write_PIN(KeyPAd_PORT_Data, COL[0], HIGH);
		MCAL_GPIO_Write_PIN(KeyPAd_PORT_Data, COL[1], HIGH);
		MCAL_GPIO_Write_PIN(KeyPAd_PORT_Data, COL[2], HIGH);
		MCAL_GPIO_Write_PIN(KeyPAd_PORT_Data, COL[3], HIGH);

		MCAL_GPIO_Write_PIN(KeyPAd_PORT_Data, COL[i], LOW);
		for(j=0 ; j<4 ; j++)
		{
			if(!(MCAL_GPIO_READ_PIN(KeyPAd_PORT_Data, ROWS[j])))
			{
				while(!(MCAL_GPIO_READ_PIN(KeyPAd_PORT_Data, ROWS[j])));
				switch(i)
				{
					case 0 :
					switch(j)
					{
						case 0:Result='7';break;
						case 1:Result='4';break;
						case 2:Result='1';break;
						case 3:Result='?';break;
					}
					break;
					case 1:
					switch(j)
					{
						case 0:Result='8';break;
						case 1:Result='5';break;
						case 2:Result='2';break;
						case 3:Result='0';break;
					}
					break;
					case 2 :
					switch(j)
					{
						case 0:Result='9';break;
						case 1:Result='6';break;
						case 2:Result='3';break;
						case 3:Result='=';break;
					}
					break;
					case 3 :
					switch(j)
					{
						case 0:Result='/';break;
						case 1:Result='*';break;
						case 2:Result='-';break;
						case 3:Result='+';break;
					}
					break;
				}
				return Result ;
			}
		}
	}
	return Result ;
}

