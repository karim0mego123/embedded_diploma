/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: karim
 */
#include "stdio.h"

void main ()
{
	int sum = 0 ;
	char x[1000] ;
	puts("enter any string") ;
	fflush(stdin) ; fflush(stdout) ;
	gets (x) ;
	for ( int i = 0 ; x[i] != 0 ; i++ )
	{
		sum+=1;
	}
	printf("%d",sum) ;

}


