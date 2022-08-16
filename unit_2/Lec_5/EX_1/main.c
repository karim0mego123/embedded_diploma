/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: karim
 */
#include "stdio.h"
struct person {
	char name[20] ;
	char age ;
	int salary ;
} x[10] ;
void git_data (  int i ) ;
void print ( int i ) ;
int main ()
{
	int i ;
	printf("enter number of persons = " ) ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&i) ;
	print (  i ) ;
	return 0 ;

}
void git_data (  int i )
{
	for ( int j = 0 ; j < i ; j++ )
	{
		printf("enter your name = " ) ;
		fflush (stdin) ; fflush(stdout) ;
		gets( x[j].name ) ;
		printf("enter your age = " ) ;
		fflush (stdin) ; fflush(stdout) ;
		scanf("%d",&x[j].age) ;
		printf("enter your salary = " ) ;
		fflush (stdin) ; fflush(stdout) ;
		scanf("%d",&x[j].salary ) ;
	}
}
void print ( int i ) {
	git_data (  i ) ;
	for ( int j = 0 ; j < i ; j++ )
	{
		printf("name_%d :%s\n",j+1,x[j].name ) ;
		printf("age_%d = %d\n",j+1,x[j].age) ;
		printf("salary_%d = %d\n",j+1,x[j].salary ) ;
	}
}
