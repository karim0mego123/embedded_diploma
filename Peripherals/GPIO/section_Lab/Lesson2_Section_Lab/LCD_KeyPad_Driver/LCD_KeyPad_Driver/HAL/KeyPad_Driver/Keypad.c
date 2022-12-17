#include "Kepad.h"
#include "Lcd.h"
uint8_t Rows[]={R0,R1,R2,R3};
uint8_t Key_index = -1 ; 
void Key_Init()
{
	KeyPad_PORT_DIR=0xF0;
	KeyPad_PORT=0xFF;
}
char KeyPad_Scan()
{
	uint8_t i,j,Result='a';
	for(i = 0 ; i < 4 ; i++)
	{
		KeyPad_PORT |=((1<<4)|(1<<5)|(1<<6)|(1<<7));
		CLEAR_BIT(KeyPad_PORT,(i+4));
		for(j=0 ; j<4 ; j++)
		{
			if(!(PIND&(1<<Rows[j])))
			{
				while(!(PIND&(1<<Rows[j])));
				Key_index++;
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
