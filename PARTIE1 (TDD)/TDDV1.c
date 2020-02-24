/* 
 * Compilation :
 * 
 * gcc -c strtnt.c
 * gcc -c TDD.c
 * gcc -o TDD strtnt.o TDD.o
 * 
 * Tests pour copie et concatenation
 * 
 * toutes les fonctions de memccpy, strtnt (prof)
 *
 * strlen(src) == strlen(dest)
 * strlen(src) > strlen(dest) avec \0
 * strlen(src) < strlen(dest) avec \0
 * strlen(src) > strlen(dest) sans \0
 * strlen(src) < strlen(dest) sans \0
 * sizeof(src) == sizeof(dest)
 * sizeof(src) > sizeof(dest)
 * sizeof(src) < sizeof(dest)
 *
 * dest pas initialise et src initlialise
 * dest initialiase et src pas initialise
 * aucun des deux initialises
 * deux initialises
 *
 * pas de '\0'
 *
 * troncation silencieuse
 *
 * buffer overflow
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtnt.h"

#define NBTESTS 8
#define BUF 80

void * memccpy1(void * dst, const void *  src, int c, size_t n) {

    void * pc = memchr(src,c,n);
    void * ret;

    if (pc) {
        n = (char*) pc - (char*) src + 1;
	ret = (char*) dst + n;
    } else {
        ret = 0;
    }

    memcpy(dst,src,n);
    
    return ret;
}

void * memccpy2(void * dst, const void * src,int c, size_t n) {

    const char * s = src;
    char * ret;
    
    for (ret = dst; n; ++ret, ++s, --n) {
	*ret = *s;
        if ((unsigned char) * ret == (unsigned char)c)
            return ret + 1;
    }

    return 0;
}


int main (void) {

    int i; 
    
    char * src = "Test avec une chaine de caractères suffisamment longue pour voir les bugs, yes";

    char * chainesDest[NBTESTS];

    printf("Taille de src : %lu\n",strlen(src) + 1);
    
    for (i = 0; i < NBTESTS; i++) {
        chainesDest[i] = malloc(sizeof(char) * BUF);
    }
    
    memccpy1(chainesDest[0],src,'\0',strlen(src) + 1);
    memccpy2(chainesDest[1],src,'\0',strlen(src) + 1);
    memccpy(chainesDest[2],src,'\0',strlen(src) + 1);
    strntcpy(chainesDest[3],sizeof(chainesDest[3]),src);

    for (i = 0; i < 4; i++) {
        printf("chainesDest[%d] --> %s\n",i,chainesDest[i]);
    }

    return 0;

}
