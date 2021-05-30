/*	@(#)	dstSmall_cpy_5.c	*/

#include <stdio.h>

#include "strtnt.h"


void printf_ret(int r)
{
switch (r)
{
  case ONOTRUNC : printf("ONOTRUNC\n") ; return ;
  case OTRUNC : printf("OTRUNC\n") ; return ;
  case EDSTPAR : printf("EDSTPAR\n") ; return ;
  case ESRCPAR : printf("ESRCPAR\n") ; return ;
  case ETRUNC : printf("ETRUNC\n") ; return ;
}
}

