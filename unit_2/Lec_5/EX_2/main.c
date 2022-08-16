#include "stdio.h"
enum {feet , inch } ;
struct information {
	float info[2] ;
} x , y , result ;
struct information git_information ( struct information ) ;
int main ()
{
	x = git_information (x) ;
	y = git_information (y) ;
	result.info[feet] = x.info[feet] + y.info[feet] ;
	result.info[inch] = x.info[inch] + y.info[inch] ;
	while ( result.info[inch] >=12.0 )
	{
		result.info[inch] -= 12 ;
		++result.info[feet] ;
	}
	printf("%.0f'-%.1f",result.info[feet] ,	result.info[inch]   ) ;

}
struct information git_information ( struct information n )
{
	printf("enter information 1st\n" ) ;
	printf("enter feet = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&n.info[feet]) ;
	printf("enter feet = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&n.info[inch]) ;
	return n;
}
