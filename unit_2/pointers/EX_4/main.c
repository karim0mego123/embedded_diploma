/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: karim
 */
#include "stdio.h"
int i = 0 ;
int main ()
{
	int x[1000] , y , *p=x ;
	printf("enter size of an array = " ) ;
	fflush(stdin)  ; fflush(stdout) ;
	scanf("%d",&y) ;
	for (  ; i < y ; i++ )
	{
		printf("value[%d] = ",i+1) ;
		fflush(stdin)  ; fflush(stdout) ;
		scanf("%d",&x[i]) ;
	}
	for ( p = x + y - 1  ; p >= x  ; --p)
	{
			printf("value[%d] = %d\n",i++,*p) ;
	}
	return 0 ;
}

