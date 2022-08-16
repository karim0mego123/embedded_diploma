#include "stdio.h"
#include "stdint.h"
typedef volatile uint8_t vuint8_t ;
typedef union {
	vuint8_t all_ports  ;
	struct bytes {
		vuint8_t port1 : 1 ;
		vuint8_t port2 : 1 ;
		vuint8_t port3 : 1 ;
		vuint8_t port4 : 1 ;
		vuint8_t port5 : 1 ;
		vuint8_t port6 : 1 ;
		vuint8_t port7 : 1 ;
		vuint8_t port8 : 1 ;

	} access_byte_by_byte ;
} access_all_ports  ;
int main ()
{
	volatile access_all_ports  *ptr = ( volatile access_all_ports *) 0x306100 ;
	ptr->all_ports = 0xff ;
	ptr->access_byte_by_byte.port1= 1 ;
	ptr->access_byte_by_byte.port2= 0 ;
	ptr->access_byte_by_byte.port3= 0 ;
	ptr->access_byte_by_byte.port4= 0 ;
	ptr->access_byte_by_byte.port5= 1 ;
	ptr->access_byte_by_byte.port6= 1 ;
	ptr->access_byte_by_byte.port7= 1 ;
	ptr->access_byte_by_byte.port8= 0 ;
	return 0 ;
}
