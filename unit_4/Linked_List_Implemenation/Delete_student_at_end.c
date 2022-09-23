/*
 * Delete_student_at_end.c
 *
 *  Created on: Sep 8, 2022
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
void Delete_student_at_end ( )
{
	if ( Head == NULL )
		printf("linked list is empty " ) ;
	else
	{
		struct node *temp1 , *temp2 ;
		temp1 = (struct node*) malloc (sizeof(struct node*) ) ;
		temp2 = (struct node*) malloc (sizeof(struct node*) ) ;
		temp1 = Head ;
		temp2 = Head ;
		while ( temp2->link != NULL )
		{
			temp1 = temp2 ;
			temp2 = temp2->link ;
		}
		temp1->link = NULL ;
		free(temp2) ;
		temp2 = NULL ;
	}
}

