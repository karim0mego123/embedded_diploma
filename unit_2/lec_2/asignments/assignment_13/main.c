/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x , sum = 0  ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	for (int i = 1 ; i<=x ; i++ )
		sum += i ;
	printf("sum = %d",sum) ;
	return 0 ;
}

