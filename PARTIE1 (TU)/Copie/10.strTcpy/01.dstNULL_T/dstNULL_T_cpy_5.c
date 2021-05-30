/*	@(#)	dstNULL_NT_cpy_5.c	*/

#include <stdio.h> 

#include "strtnt.h"


void printf_ret( int r ) ;



int main(void)
{
	char * dst = NULL ;

    int ret ;


ret = strtcpy(dst,sizeof(dst),"12345") ; 

fprintf(stderr," strtcpy -- cas : dst (NULL) --  \n") ;
fprintf(stderr,"  ret (ATTENDU) : EDSTPAR   --  ret (REEL) : ") ;
printf_ret(ret) ;

return 0 ;
}
