/*	@(#)	strtnt.c	*/
/* V1 */

/* Copyright (C) 2019 eric.sanchis@iut-rodez.fr
   It is a free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Public License for more details:
   <http://www.gnu.org/licenses/>.  */

#include	<string.h>

#include	"strtnt.h"



#define   TRUNC      0          /* truncation allowed */
#define   NOTRUNC    1          /* truncation not allowed */



/* = = = = = = = =  COPY  = = = = = = = = */

static
int str4cpy(char * dst, size_t dstsize, const char * src, size_t mode)
{
	size_t srclen;
        size_t nb;

	
if ( dst == NULL || dstsize == 0 )
   return EDSTPAR;
if ( src == NULL )
   return ESRCPAR;

   /* find the nul byte of src within the first dstsize characters */
for (srclen=0; srclen < dstsize && src[srclen] != '\0'; srclen++)
    ;

if ( srclen == 0 )
{
  dst[0] = '\0';   
  return ONOTRUNC;
}

nb = dstsize > srclen ? srclen : dstsize;   

if ( dstsize <= nb )    /* dst: not enough space */
{
   if ( mode == TRUNC )    /* truncation allowed */
   {
     memcpy(dst,src,dstsize-1);
     dst[dstsize-1] = '\0';
     return OTRUNC;
   }
   else  /*  mode == NOTRUNC */
     return ETRUNC; 
}

/* dst: enough space */
memcpy(dst, src, nb);   
dst[nb] = '\0';
return ONOTRUNC;
}


int strntcpy(char *dst, size_t dstsize, const char *src)
{
  return str4cpy(dst,dstsize,src,NOTRUNC);
}


int strtcpy(char *dst, size_t dstsize, const char *src)
{
  return str4cpy(dst,dstsize,src,TRUNC);
}


/* = = = = = = = =  CONCATENATION  = = = = = = = = */


static
int str4cat(char * dst, size_t dstsize, const char * src, size_t mode)
{
	size_t srclen;
	size_t dstlen;
	size_t remain;
        size_t nb;
	size_t i;
	char * p;
	
if ( dst == NULL || dstsize == 0 )
   return EDSTPAR;
if ( src == NULL )
   return ESRCPAR;

   
/* find the nul byte of dst */
for (i=0 ; i < dstsize && dst[i] != '\0' ; i++)
     ;
if ( i == dstsize )	 /* no nul byte found into the buffer pointed to by dst */
   return EDSTPAR;		/*  dst is a bad-formed string  */
dstlen = i; 

remain = dstsize - dstlen;

for (srclen=0 ; srclen < remain && src[srclen] != '\0' ; srclen++)
     ;
if ( srclen == 0 )
   return ONOTRUNC;	/* nothing to do */

p = dst + dstlen;		/* concatenation starting point  */
   
/* How many bytes to copy? */
nb = dstsize > srclen ? srclen : dstsize;   

if ( remain <= nb )    /* dst: not enough space */
{
   if ( mode == TRUNC )    /* truncation allowed */
   {
     memcpy(p, src, remain-1);
     dst[dstsize-1] = '\0';
     return OTRUNC;
   }
   else  /*  mode == NOTRUNC */
     return ETRUNC; 
}
   
/* dst: enough space */
memcpy(p, src, nb);   
p[nb] = '\0';
return ONOTRUNC;
}


int strntcat(char *dst, size_t dstsize, const char *src)
{
  return str4cat(dst,dstsize,src,NOTRUNC);
}


int strtcat(char *dst, size_t dstsize, const char *src)
{
  return str4cat(dst,dstsize,src,TRUNC);
}


  
