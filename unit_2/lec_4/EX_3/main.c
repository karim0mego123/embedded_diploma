/*
 * main.c
 *
 *  Created on: Jul 22, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "string.h"
void reverse_string ( char x[]) ;

int main ()
{
	char x[100] ;
	printf("enter any string = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf ( "%s",x) ;
	printf("this is without recursion : %s" , x);
	printf("this is after recursion : ");
	reverse_string ( x ) ;
	return 0 ;
}

void reverse_string ( char  x[] )
{
	if ( *x == 0 )
	{
	    return ;
	}
	reverse_string(x+1);
	printf("%c " ,*x);
}



