#include "stdio.h"
#define function( type , a ) int type ( int x ) { return x * a ; }
function(square , 2)
function (quad , 4 )
#undef function
#define function 31
#define output(a) printf(#a)
/*
 * 		int square ( int x )
 * 		{
 * 			return x*2 ;
 * 		}
 * 		function = 31 ;
 * 		output(a) = printf("a") ;

 * 		int quad ( int x )
 * 		{
 * 			return x * 4 ;
 * 		}
 *
 */
int main ()
{
    printf("file : %s\nline : %d\ndata : %s\ntime = %s\n",__FILE__,__LINE__,__DATE__,__TIME__) ;
	printf("%d\n",square(4)) ;
	printf("%d\n",quad(3) ) ;
	printf("%d",function) ;
	output(\nkarim) ;
	return 0 ;
}
