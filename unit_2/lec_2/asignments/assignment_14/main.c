/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x , fact = 1  ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	if (x<0)
		printf("fact does not exist") ;
	else
	{
		for ( int i = 1 ; i<=x && x>=0 ; i++ )
			fact *= i ;
		printf("fact = %d",fact) ;
	}
	return 0 ;
}

