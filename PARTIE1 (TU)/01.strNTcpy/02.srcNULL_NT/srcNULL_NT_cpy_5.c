/*	@(#)	02.src_NULL_cpy_5.c	*/

#include <stdio.h> 

#include "strtnt.h"


void printf_ret( int r ) ;


#define	DSTSIZE	5


int main(void)
{
	char dst[DSTSIZE] ;

	char * src = NULL ;

	int ret ;


ret = strntcpy(dst,sizeof(dst),src) ;	/* ret = ESRCPAR */

fprintf(stderr," strntcpy -- cas : src (NULL) --  \n") ;
fprintf(stderr,"  ret (ATTENDU) : ESRCPAR   --  ret (REEL) : ") ;
printf_ret(ret) ;

return 0 ;
}


