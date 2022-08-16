/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: karim
 */
#include "stdio.h"

void prime ( int x , int y ) ;
int main ()
{
	int x , y ;
	printf("enter first number = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("enter second number = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	prime(x,y) ;
	return 0 ;
}
void prime ( int x , int y )

{
	int i = 0 , j = 0  ;
	for ( i = x ; i <= y ; i++ )
	{
		int n = 0 ;
		for ( j = 1 ; j<=i ; j++ )
		{
			if ( i%j == 0 )
				n++ ;
		}
		if ( n == 2 )
			printf("%d  ",i) ;
	}
}
