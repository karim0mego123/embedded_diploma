/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	(x>0)? printf("number is positave") : (x==0)? printf("num is zero") :
			printf("number is nagitave") ;
	return 0 ;
}

