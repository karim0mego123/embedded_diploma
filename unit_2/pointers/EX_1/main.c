/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: karim
 */
#include "stdio.h"
int main ()
{
	int m = 29 ;
	printf("Addsress of m = 0x%x\n",&m) ;
	printf("Value of m = %d\n" ,m ) ;
	int *p = &m ;
	printf("Addsress of pointer = 0x%x\n",p) ;
	printf("Value of pointer = %d\n" ,*p) ;
	m = 34 ;
	printf("Addsress of pointer = 0x%x\n",p) ;
	printf("Value of pointer = %d\n" ,*p) ;
	*p = 7 ;
	printf("Addsress of pointer = 0x%x\n",p) ;
	printf("Value of pointer = %d\n" ,*p) ;
	return 0 ;
}

