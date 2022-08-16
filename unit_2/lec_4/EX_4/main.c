/*
 * main.c
 *
 *  Created on: Jul 22, 2022
 *      Author: karim
 */

#include "stdio.h"
#include "string.h"
int i = 1  ;
int power_num ( int x , int y ) ;
int main ()
{
	int x , y ;
	printf("enter any number to git power = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("enter power you want to take = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	printf("%d",power_num(x,y) ) ;
	return 0 ;
}
int power_num ( int x , int y )
{
	if ( y <= 0 )
	{
	     return 1;
	}

	return x *  power_num(x,--y) ;
}


