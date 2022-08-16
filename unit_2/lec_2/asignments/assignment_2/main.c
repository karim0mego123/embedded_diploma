/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("you have entered %d",x) ;
	return 0 ;
}
