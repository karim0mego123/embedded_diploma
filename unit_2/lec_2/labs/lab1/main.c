/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int  main ()
{
	float radius , area , Circumference ;
	char choice ;
	printf("entet a to calc area (or) enter c to calc Circumference : ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%c",&choice) ;
	printf("enter radius of circle = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&radius) ;
	switch (choice)
	{
	case 'a' :
	case 'A' :
		printf("area = %.3f",3.14*(float)radius*radius) ;
		break ;
	case 'c' :
	case 'C' :
		printf("Circumference = %.3f",2*3.14*(float)radius) ;
		break ;
	default :
		printf("you have entered wrong choice ") ;
		break ;
		return 0 ;
	}

}

