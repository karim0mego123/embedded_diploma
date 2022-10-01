/*
 * main.c
 *
 *  Created on: Sep 24, 2022
 *      Author: karim
 */
#include "student.h"
int main ()
{
	system("color 4") ;
	uint32_t temp ;
	student_info person ;
	person.base = NULL ;
	person.head = NULL ;
	uint32_t r = 0 ;s
	person.count = &r ;
	int choice ;
	while (1)
	{
		printf(	"0-craete list\n"\
				"1-add_student_details_from_file\n" \
				"2-add_stduent_details_manually\n" \
				"3-find_student_by_giving_id\n" \
				"4-find_studen_by_first_name\n" \
				"5-find_student_registered_in_coursre\n" \
				"6-count_of_student\n" \
				"7-delete_student\n" \
				"8-updata_student\n" \
				"9-print all students\n" \
				"10-exit you programm\n"
		) ;
		printf("enter your choice = " ) ;
		fflush(stdin) ; fflush(stdout) ;
		scanf("%d",&choice) ;
		switch ( choice )
		{
		case initFifo :
			init_fifo( &person , &temp , person.count ) ;
			break ;
		case addStudent_details_from_file :
			if ( add_student_details_from_file ( &person , person.count) )
			{
				system("cls") ;
				printf("fifo is full \n") ;
			}
			break ;
		case addStduent_details_manually :
			if ( add_stduent_details_manually( &person , person.count ) == fifo_full )
			{
				system("cls") ;
				printf("fifo is full \n") ;
			}			break ;
		case findStudent_by_giving_id :
			if ( find_student_by_giving_id( &person , person.count ) == fifo_empty )
			{
				system("cls") ;
				printf("fifo is full \n") ;
			}
			break ;
		case findStuden_by_first_name :
			if ( find_studen_by_first_name( &person , person.count ) == fifo_empty )
			{
				system("cls") ;
				printf("fifo is full \n") ;
			}
			break ;
		case findStudentRegisteredInCoursre :
			if (find_student_registered_in_coursre ( &person , person.count ) == fifo_empty )
			{
				system("cls") ;
				printf("fifo is full \n") ;
			}
			break ;
		case countOfStudent :
			if ( count_of_student( &person , person.count ) == fifo_empty )
			{
				system("cls") ;
				printf("fifo is empty \n") ;
			}			break ;
		case deleteStudent :
			if ( delete_student ( &person , person.count ) == fifo_empty )
				printf("fifo is empty\n") ;
			break ;
		case updataStudent :
			if ( updata_student ( &person , person.count ) == fifo_empty )
				printf("fifo is empty\n") ;
			break ;
		case printAll_students :
			if ( print_all_students ( &person , person.count ) == fifo_empty )
				printf("there are no students\n") ;
			break ;
		case exit_programm :
			return fifo_no_error ;
			break ;
		default :
			printf("you have entered wrong choice ! " ) ;
		}
	}
	return fifo_no_error ;
}

