/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "string.h"
int main ()
{
	int n ;
	char a[1000] ;
	char *p = a ;
	gets(a) ;
	n = strlen(a) ;
	for ( char *i = (a+n)-1 ; i>=p ; --i )
	{
		printf("%c   ",*i) ;
	}
	return 0 ;
}

