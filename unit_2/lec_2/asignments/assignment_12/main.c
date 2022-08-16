/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	char x ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%c",&x) ;
	if ( ( x >= 'A' && x <= 'Z' ) ||( x >= 'a' && x <= 'z' ) )
		printf("x is a alphbet");
	else
		printf("x is not an alphbet") ;
	return 0 ;
}

