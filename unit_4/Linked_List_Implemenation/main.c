/*
 * main.c
 *
 *  Created on: Sep 5, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "stdlib.h"
#include "add_student_at_the_end.h"
#include "Delete_student_at_end.h"
#include "print_student.h"
#include "search_student.h"
#include "add_sudent_in_specific_posation.h"
struct student {
	int id ;
	char name[50] ;
	float height ;
}  ;
struct node {
	struct student person ;
	struct node *link ;
};
struct node* Head ;
int main ()
{
	Head = (struct node*)malloc(sizeof(struct node)) ;
	Head = NULL ;
	int ch ;
	while (1)
	{
		printf("1-add_student_at_end\n" ) ;
		printf("2-add_student_at_specific_posation \n") ;
		printf("3-delete student at end\n") ;
		printf("4-searcch for student by id = \n" ) ;
		printf("5-print your linked list\n" ) ;
		printf("6-to exit from your programm\n" ) ;
		printf("enter your choice = " ) ;
		fflush(stdout) ;
		scanf("%d",&ch) ;
		switch (ch)
		{
		case 1 :
			add_student_at_the_end() ;
			break ;
		case 2 :
			add_sudent_in_specific_posation ( ) ;
			break ;
		case 3 :
			Delete_student_at_end() ;
			break ;
		case 4 :
			search_student() ;
			break ;
		case 5 :
			print() ;
			break ;
		case 6 :
			exit(1) ;
			break ;
		default :
			printf("you have entered wrong answer\n") ;
			break ;
		}
	}
}
