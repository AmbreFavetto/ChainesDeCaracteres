/*	@(#)	strtnt.h	*/
/*
 *      v 1.0, 2019/10 Eric Sanchis
 */

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


#ifndef _STRTNT_H

#define	_STRTNT_H


int strntcpy(char *dst, size_t dstsize, const char *src);

int strtcpy(char *dst, size_t dstsize, const char *src);

int strsntcpy( char *dst, size_t dstsize, const char *src, size_t nb);

int strstcpy( char *dst, size_t dstsize, const char *src, size_t nb);

int strntcat(char *dst, size_t dstsize, const char *src);

int strtcat(char *dst, size_t dstsize, const char *src);

int strsntcat( char *dst, size_t dstsize, const char *src, size_t nb);

int strstcat( char *dst, size_t dstsize, const char *src, size_t nb);



#define   ONOTRUNC  0		/* copy/concatenation performed without truncation */
#define   OTRUNC    1		/* copy/concatenation performed with truncation */


#define   EDSTPAR   -1		/* Error : bad dst parameters */
#define   ESRCPAR   -2		/* Error : bad src parameters */
#define   ETRUNC    -3		/* Error : not enough space to copy/concatenate
						and truncation not allowed */

#endif
