/*
 * main.c
 *
 *  Created on: Oct 15, 2022
 *      Author: karim
 */
#include "c_a.h"
void setup ()
{
	PTR_STATUS = status(CA_waiting) ;
}
int main ()
{
	volatile int i = 0 ;
	setup() ;
	while (1)
	{
		PTR_STATUS() ;
		for ( i = 0 ; i < 1000 ; i++ ) ;
	}
	return 0 ;
}

