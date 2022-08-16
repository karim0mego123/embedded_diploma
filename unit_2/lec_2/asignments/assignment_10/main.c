/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */

#include "stdio.h"

int main ()
{
	int x , y , z ;
	printf("enter three numbers = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d %d %d",&x,&y,&z) ;
	int max = (x>y)? ( x>z ? x :z ): (y>z) ? y : z ;
	printf("%d",max) ;
	return 0 ;
}
