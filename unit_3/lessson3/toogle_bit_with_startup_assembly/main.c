#include "stdio.h"
#include "stdint.h"
typedef volatile uint32_t vuint32_t  ;
#define RCC_base_address  0x40021000
#define GPIO_Port_A_base_address 0x40010800
#define RCC_APB2ENR   *(vuint32_t *) ( RCC_base_address + 0x18 )
#define GPIOA_CRH       *(vuint32_t *) ( GPIO_Port_A_base_address + 0x04 )
#define GPIOA_ODR      *(vuint32_t *) ( GPIO_Port_A_base_address + 0x0c )

int main()
{
	uint32_t i = 0 ; 
	RCC_APB2ENR  |= 1<<2 ;
	GPIOA_CRH     &=  0xFF0FFFFF  ;
	GPIOA_CRH     |=    0x00200000  ;
	while (1)
	{
		GPIOA_ODR  |= 1<<13 ;
		for (  i = 0  ;  i < 50000  ;  i++  )  ;
		GPIOA_ODR  &= ~(1<<13) ;
		for (  i = 0  ;  i < 50000  ;  i++  )   ;
	}
	return 0 ;
}
