/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "string.h"
void main ()
{
	int sum = 0 ;
	char x[1000] ;
	puts("enter any string") ;
	fflush(stdin) ; fflush(stdout) ;
	gets (x) ;
	for ( int i = strlen(x)-1 ; i>=0 ; i-- )
	{
		printf("%c",x[i]) ;
	}

}


