/*
 * main.c
 *
 *  Created on: Aug 7, 2022
 *      Author: karim
 */
#include "stdio.h"
typedef struct gpreson{
	char *name ;
	int age ;
} person ;

int main ()
{
    int i = 0 ;
	person data_person_1 = { "karim" , 21 } , data_person_2 = { "ahmed" , 26 } ;
	person data_person_3 = { "aya" , 24 }  ;
	person *p[3] = { &data_person_1 , &data_person_2 , &data_person_3 } ;
	person (*(*pt)[3]) =&p ;
	for (  i = 0 ; i < 3 ; i++ )
	{
		printf("name of person : %s\n",(*(*pt+i)) ->name) ;
		printf("age of person= %d\n",(*(*pt+i)) ->age );
	}
	return 0 ;
}

