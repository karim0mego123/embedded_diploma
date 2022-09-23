/*
 * print_nodes.c
 *
 *  Created on: Sep 6, 2022
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
void print ( )
{
	struct node* temp ;
	temp = (struct node* ) malloc (sizeof(struct node*)) ;
	temp = Head ;
	if ( temp == NULL )
		printf("linked list is empty" ) ;
	else
	{
		while ( temp != NULL )
		{
			printf("%s\n",temp->person.name) ;
			printf("%d\n",temp->person.id) ;
			printf("%.2f\n",temp->person.height) ;
			temp = temp->link ;
		}
	}
}

