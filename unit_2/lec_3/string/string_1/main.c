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
	char x[1000] , y ;
	puts("enter any string") ;
	fflush(stdin) ; fflush(stdout) ;
	gets (x) ;
	printf("enter any char to now frequency = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%c",&y) ;
	for ( int i = 0 ; x[i] != 0 ; i++ )
	{
		if (x[i] == y)
			sum+=1;
	}
	printf("%d",sum) ;

}


