/*
 * search_student.c
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
void search_student ()
{
	struct node *temp ;
	temp = (struct node*)malloc(sizeof(struct node ) ) ;
	temp = Head ;
	int search ;
	printf("enter your id to search for student = " ) ;
	fflush(stdout) ;
	scanf("%d",&search) ;
	if ( Head == NULL )
		printf("linked lis is empty " ) ;
	else
	{
		while ( temp->link != NULL )
		{
			if ( temp->person.id == search )
			{
				printf("%s\n",temp->person.name) ;
				printf("%d\n",temp->person.id) ;
				printf("%.2f\n",temp->person.height) ;
				break ;
			}
			else
			{
				temp = temp->link ;
			}
		}
	}
}

