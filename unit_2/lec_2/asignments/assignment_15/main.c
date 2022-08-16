/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	float x , y  ;
	char a ;
	printf("enter operator either + or - or * or / : ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%c",&a) ;
	printf("enter first number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&x) ;
	printf("enter second number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&y) ;
	switch (a)
	{
	case '+' :
		printf("%f + %f = %.2f",x,y,x+y) ;
		break ;
	case '-' :
		printf("%f - %f = %.2f",x,y,x-y) ;
		break ;
	case '*' :
		printf("%f * %f = %.2f",x,y,x*y) ;
		break ;
	case '/' :
		printf("%f + %f = %.2f",x,y,x/y) ;
		break ;
	default :
		printf("false operator") ;
		break ;
	}
	return 0 ;
}

