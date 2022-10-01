/*
 * student.c
 *
 *  Created on: Sep 24, 2022
 *      Author: karim
 */
#include "student.h"
uint32_t i = 0 ;
char id_courses [][19] = { "physics" , "maths" , "arabic" , "english" , "chemistry" }  ;
fifo_status_e init_fifo ( student_info* person1 , uint32_t* temp , uint32_t *p )
{
	*p = 0 ;
	person1->head = (Sperson*)&temp ;
	person1->base = (Sperson*)&temp ;
	system("cls") ;
	return fifo_no_error ;
}
fifo_status_e add_student_details_from_file ( student_info* person1 , uint32_t *p )
{
	system("cls") ;
	FILE* pfile = NULL ;
	pfile = fopen ( "karim.txt" , "r" ) ;
	uint32_t id  ;
	printf("enter your id = " ) ;
	Clean_Buffer
	scanf("%d",&id) ;
	if ( person1->head == person1->base+ ( sizeof(student_info) * number_of_student ) )
		return fifo_full ;
	while ( fscanf(pfile,"%d",&person1->student[*p].ID )  != EOF  )
	{
		if ( id == person1->student[*p].ID )
		{
			fscanf(pfile,"%s",person1->student[*p].First_name ) ;
			fscanf(pfile,"%s",person1->student[*p].Second_name ) ;
			fscanf(pfile,"%f",&person1->student[*p].gpa ) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				fscanf(pfile,"%d\n",&person1->student[*p].courses[j]) ;
			}
			++*p ;
			fclose ( pfile );
			person1->head++ ;
			return fifo_no_error ;
		}
		else
		{
			fscanf(pfile,"%d",&person1->student[*p].ID ) ;
			fscanf(pfile,"%s",person1->student[*p].First_name ) ;
			fscanf(pfile,"%s",person1->student[*p].Second_name ) ;
			fscanf(pfile,"%f",&person1->student[*p].gpa ) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				fscanf(pfile,"%d\n",&person1->student[*p].courses[j]) ;
			}
		}
	}
	printf("this id is not in list\n" ) ;
	fclose ( pfile );
	return fifo_no_error ;
}
fifo_status_e add_stduent_details_manually ( student_info* person1 ,  uint32_t *p )
{
	system("cls") ;
	printf("enter student id number = " ) ;
	Clean_Buffer
	scanf("%d",&person1->student[*p].ID ) ;

	printf("enter first name of student : " ) ;
	Clean_Buffer
	scanf("%s",person1->student[*p].First_name) ;
	printf("enter second name of student : " ) ;
	Clean_Buffer
	scanf("%s",person1->student[*p].Second_name) ;
	printf("enter student GPA = " ) ;
	Clean_Buffer
	scanf("%f",&person1->student[*p].gpa) ;
	printf( "courses codes	" \
			"0-physics 1-maths 2-arabic 3-english 4-chemistry\n"\
			"enter -1 if you do not want to share this course\n"  ) ;
	for ( i = 0 ; i < Number_of_courses ; i++ )
	{
		printf("enter id of %ss you want to share = " ,id_courses[i] ) ;
		Clean_Buffer
		scanf("%d",&person1->student[*p].courses[i]) ;
	}
	system("cls") ;
	person1->head++ ;
	++*person1->count ;
	return fifo_no_error ;
}
fifo_status_e find_student_by_giving_id ( student_info* person1 , uint32_t *r )
{
	system("cls") ;
	uint32_t id_for_search ;
	if ( person1->head == person1->base )
		return fifo_empty ;
	printf("enter id of student you want to search for = " ) ;
	Clean_Buffer
	scanf("%d",&id_for_search) ;
	for ( i = 0 ; i < *r ; i++ )
	{
		if ( id_for_search == person1->student[i].ID)
		{
			system("cls") ;
			printf("wait to git information of your student \n" ) ;
			printf("student id = %d\n",person1->student[i].ID) ;
			printf("student first name : %s\n",person1->student[i].First_name) ;
			printf("student second name : %s\n",person1->student[i].Second_name) ;
			printf("student GPA = %f\n",person1->student[i].gpa) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				printf("id of coures %s = %d\n",id_courses[j],person1->student[i].courses[j] ) ;
			}
			return fifo_no_error ;
		}
	}
	printf("your id is not recognize please try again\n") ;
	return fifo_no_error ;
}
fifo_status_e find_studen_by_first_name ( student_info* person1 , uint32_t *r )
{
	system("cls") ;
	uint8_t first_name_for_search[10] ;
	if ( person1->head == NULL )
		return fifo_empty ;
	printf("enter first name of student you want to search for = " ) ;
	Clean_Buffer
	scanf("%s",first_name_for_search) ;
	for ( i = 0 ; i < number_of_student ; i++ )
	{
		if ( stricmp( first_name_for_search , person1->student[i].First_name  ) == 0 )
		{
			system("cls") ;
			printf("wait to git information of your student \n" ) ;
			printf("student id = %d\n",person1->student[i].ID) ;
			printf("student first name : %s\n",person1->student[i].First_name) ;
			printf("student second name : %s\n",person1->student[i].Second_name) ;
			printf("student GPA = %f\n",person1->student[i].gpa) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				printf("id of coures %s = %d\n",id_courses[j],person1->student[i].courses[j] ) ;
			}
			return fifo_no_error ;
		}
	}
	printf("your id is not recognize please try again\n") ;
	return fifo_no_error ;
}
fifo_status_e find_student_registered_in_coursre ( student_info* person1 , uint32_t *r )
{
	system("cls") ;
	printf( "courses codes	" \
			"0-physics 1-maths 2-arabic 3-english 4-chemistry\n"\
			"enter -1 if you do not want to share this course\n"  ) ;
	uint32_t course_id ;
	if ( person1->head == NULL )
		return fifo_empty ;
	printf("enter course id to display participants = " ) ;
	Clean_Buffer
	scanf("%d",&course_id) ;
	printf("student share this course :\n") ;
	for ( i = 0 ; i < *r ; i++ )
	{
		if ( person1->student[i].courses[course_id] != -1 )
		{
			printf("%s %s\n",person1->student[i].First_name,person1->student[i].Second_name) ;
		}
	}
	return fifo_no_error ;

}
fifo_status_e count_of_student ( student_info* person1 , uint32_t *r )
{
	if ( person1->head == person1->base )
		return fifo_empty ;
	printf("number of student = %d\n",*r) ;
	return fifo_no_error ;
}
fifo_status_e delete_student ( student_info* person1 ,uint32_t *r )
{
	system("cls") ;
	uint32_t id_to_delete ;
	if ( person1->head == person1->base )
		return fifo_empty ;
	printf("enter id for student tou want to delete = " ) ;
	Clean_Buffer
	scanf("%d",&id_to_delete) ;
	for ( i = 0 ; i < *r ; i++ )
	{
		if ( id_to_delete == person1->student[i].ID )
		{
			printf("this student information has been deleted\n") ;
			printf("student id = %d\n",person1->student[i].ID) ;
			printf("student first name : %s\n",person1->student[i].First_name) ;
			printf("student second name : %s\n",person1->student[i].Second_name) ;
			printf("student GPA = %f\n",person1->student[i].gpa) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				printf("id of coures %s = %d\n",id_courses[j],person1->student[i].courses[j] ) ;
			}
			for ( ;i < (*r-1);i++ )
			{
				person1->student[i].ID = person1->student[i+1].ID ;
				strcpy ( person1->student[i].First_name , person1->student[i+1].First_name );
				strcpy ( person1->student[i].Second_name , person1->student[i+1].Second_name ) ;
				person1->student[i].gpa = person1->student[i+1].gpa ;
				for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
				{
					person1->student[i].courses[j] = person1->student[i+1].courses[j] ;
				}
			}
			--*person1->count ;
			person1->head-- ;
			return fifo_no_error ;
		}
	}
	printf("this id is not recognize\n") ;
	--*person1->count ;
	person1->head-- ;
	return fifo_no_error ;

}
fifo_status_e updata_student ( student_info* person1 , uint32_t *r )
{
	system("cls") ;
	uint32_t id_updata ;
	if ( person1->head == person1->base )
		return fifo_empty ;
	printf("enter id of student you want to updata = " ) ;
	Clean_Buffer
	scanf("%d",&id_updata) ;
	for ( i = 0 ; i < *r ; i++ )
	{
		if ( id_updata == person1->student[i].ID )
		{
			printf("enter student new_id number = " ) ;
			Clean_Buffer
			scanf("%d",&person1->student[i].ID) ;
			printf("enter new_first name of student : " ) ;
			Clean_Buffer
			scanf("%s",person1->student[i].First_name) ;
			printf("enter new_second name of student : " ) ;
			Clean_Buffer
			scanf("%s",person1->student[i].Second_name) ;
			printf("enter student new_GPA = " ) ;
			Clean_Buffer
			scanf("%f",&person1->student[i].gpa) ;
			for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
			{
				printf("enter new_id of %s" \
						"enter id of course = ",id_courses[j] ) ;
				Clean_Buffer
				scanf("%d",&person1->student[i].courses[j]) ;
			}
		}
	}
	return fifo_no_error ;
}
fifo_status_e print_all_students ( student_info* person1 , uint32_t *r )
{
	system("cls") ;
	if ( person1->head == person1->base )
		return fifo_empty ;
	for ( i = 0 ; i < *r ; i++ )
	{
		printf("student id = %d\n",person1->student[i].ID) ;
		printf("student first name : %s\n",person1->student[i].First_name) ;
		printf("student second name : %s\n",person1->student[i].Second_name) ;
		printf("student GPA = %.2f\n",person1->student[i].gpa) ;
		for ( uint32_t j = 0 ; j < Number_of_courses ; j++ )
		{
			printf("id of coures %s = %d\n",id_courses[j],person1->student[i].courses[j] ) ;
		}
	}
	return fifo_no_error ;

}



