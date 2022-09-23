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
struct node *p ;
void add_student_at_the_end ( )
{
	struct node *temp ;
	temp = (struct node*)malloc(sizeof(struct node ) ) ;
	p  = (struct node*)malloc(sizeof(struct node ) ) ;
	printf("enter id of student = " ) ;
	fflush(stdout) ;
	scanf("%d",&temp->person.id) ;
	printf("enter name of student = " ) ;
	fflush(stdout) ;
	scanf("%s",temp->person.name) ;
	printf("enter height of student = " ) ;
	fflush(stdout) ;
	scanf("%f",&temp->person.height) ;
    temp->link = NULL ;
	if ( Head == NULL )
        Head = temp ;
    else
    {
    p = Head ;
    while ( p->link != NULL )
	{
		p = p->link ;
	}
		p->link = temp ;
    }

}
