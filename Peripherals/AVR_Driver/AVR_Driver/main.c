/*
 * AVR_Driver.c
 *
 * Created: 1/29/2023 12:30:53 AM
 * Author : karim
 */ 

#include "LCD.h"
#include "USART.h"
 #include "string.h"
 Error_Status_t Compare_String(uint8_t* Buffer1 , uint8_t* Buffer2);
int main(void)
{
	uint8_t Buffer[30] ;
	DIO_Write_Pin_Dir(PORT_D,GPIO_PIN_0,IN);
	DIO_Write_Pin_Dir(PORT_D,GPIO_PIN_1,OUT);
	LCD_Init();
	USART_Init();
	while(1)
	{
		USAERT_Recieve_STRING(Buffer);
		LCD_Write_String(Buffer,0,0);
		LCD_Clear_Screen();
	}
}
// 	USAERT_Send_STRING((uint8_t*)"Enter 1 to LED ON Led1\r\n");
// 	USAERT_Send_STRING((uint8_t*)"Enter 2 to LED ON Buzzer\r\n");
// 	USAERT_Recieve_STRING(Buffer);
// 	Error_Status_t Status =  Compare_String(Buffer,(uint8_t*)"LED ON") ;
// 	 if (Status==NO_Error)
// 	 {
// 		 DIO_Write_Pin(PORT_D,GPIO_PIN_5,HIGH);
// 	 }
// 	 else
// 	 {
// 		 DIO_Write_Pin(PORT_D,GPIO_PIN_4,HIGH);
// 	 }
// 	return NO_Error ;		
// }
// Error_Status_t Compare_String(uint8_t* Buffer1 , uint8_t* Buffer2)
// {
// 	uint8_t i = 0 ; 
// 	Error_Status_t Compare_Status = Error ; 
// 	for (; Buffer1[i] != 0 && Buffer2[i] != 0 ; i++ )
// 	{
// 		if (*Buffer1 != *Buffer1)
// 		{
// 			break;
// 		}
// 	}
// 	if (Buffer1[i] == Buffer2[i])
// 	{
// 		Compare_Status = NO_Error ; 
// 	}
// 	return Compare_Status ; 
// }
// 
