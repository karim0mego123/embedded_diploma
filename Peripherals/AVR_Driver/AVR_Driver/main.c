#include "DIO.h"
#include "LCD.h"


int main()
{		
	LCD_Init();
	
	LCD_Write_Number((uint16_t)12);

	while(1)
	{
	}
}

