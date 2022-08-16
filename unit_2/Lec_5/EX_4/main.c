/*
 * main.c
 *
 *  Created on: Jul 28, 2022
 *      Author: karim
 */
#include "stdio.h"
struct ggit_data
{
	char name [20];
	int x ;
} students[100] ;
int  git_data ( void )   ;
void print_data( void ) ;
int main ()
{
	print_data() ;
	return 0 ;
}
int  git_data ( void )
{
	int i = 0 , y  ;
	printf("enter number of students = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	for (  i = 0 ; i<y ; i++ )
	{
		printf("enter name : " ) ;
		fflush(stdin) ; fflush(stdout) ;
		gets( students[i].name ) ;
		printf("enter marks = " ) ;
		fflush(stdin) ; fflush(stdout) ;
		scanf("%d",&students[i].x) ;
	}
	return y ;
}
void print_data( void )
{
	int y = git_data ( ) ;
	for ( int i = 0 ; i<y ; i++ )
	{
		printf("your name is : %s\n",students[i].name ) ;
		printf("your marks = %d\n",students[i].x ) ;
	}

}
