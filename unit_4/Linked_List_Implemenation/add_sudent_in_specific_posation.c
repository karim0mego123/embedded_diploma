/*
 * add_sudent_in_specific_posation.c
 *
 *  Created on: Sep 9, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "stdlib.h"
struct student {
	int id ;
	char name[50] ;
	float height ;
};
struct node {
	struct student person ;
	struct node *link ;
};
extern struct node* Head ;
void add_sudent_in_specific_posation ()
{
	int n ;
	struct node *temp1 ;
	temp1 = (struct node*)malloc(sizeof(struct node ) ) ;
	temp1 = Head ;
	struct node *temp2 ;
	temp2 = (struct node*)malloc(sizeof(struct node ) ) ;
	printf("enter your id you want to insert after " ) ;
	fflush(stdout) ;
	scanf("%d",&n) ;
	printf("enter name to insert : "  ) ;
	fflush(stdout) ;
	scanf("%s",temp2->person.name) ;
	printf("enter id ffor your student = " ) ;
	fflush(stdout) ;
	scanf("%d",&temp2->person.id) ;
	printf("enter height for your person = " ) ;
	fflush(stdout) ;
	scanf("%f",&temp2->person.height) ;
	if ( temp1 != NULL )
		printf("linked list is empty " ) ;
	else
	{
		while ( 1 )
		{
			if ( temp1->person.id != n )
				temp1 = temp1->link ;
			else
			{
				temp2->link = temp1->link ;
				temp1->link = temp2 ;
				break ;
			}
		}
	}
}

