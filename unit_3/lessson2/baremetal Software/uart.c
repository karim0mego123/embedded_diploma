#include "uart.h"
#include  "stdint.h"
 
typedef volatile uint32_t vuint32_t ;
#define UAER_ODE *((vuint32_t *)((uint32_t *)0x101f1000))

void print_string ( unsigned char *ptr ) 
{
	while ( *ptr != '\0' ) 
	{
		UAER_ODE = (uint32_t) (*ptr) ;
		ptr++ ; 
	}
}
