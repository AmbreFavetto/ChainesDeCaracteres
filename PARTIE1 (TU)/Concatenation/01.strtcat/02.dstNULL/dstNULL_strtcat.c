/*
 * Test d'une concaténation d'une source 
 * à une destination NULL
 *
 * gcc -c strtnt.c
 * gcc -c fichier.c
 * gcc -o fichier strtnt.o fichier.o
 */

#include <stdio.h>
#include <string.h>
#include "strtnt.h"

#define BUFSIZE 6

int main (void) {

    char * src = "12345";
    char * dst = NULL;
    int ret;

    /* memset(dst,0,BUFSIZE); */

    ret = strtcat(dst,sizeof(dst),src);

    printf("strtcat -- cas : dst (NULL) -- \n");
    printf("ret (ATTENDU) : -1 -- ret (REEL) : ");
    printf("%d\n",ret);

    /* résultats conforment aux attentes */
   
    return 0;
}
