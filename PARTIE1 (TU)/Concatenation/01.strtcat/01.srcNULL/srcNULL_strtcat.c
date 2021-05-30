/*
 * Test d'une concaténation avec la source NULL
 * dans une destination de 6
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

    char * src = NULL;
    char dst[BUFSIZE];
    int ret;

    memset(dst,0,BUFSIZE);

    ret = strtcat(dst,sizeof(dst),src);

    printf("strtcat -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : -2 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); /* aucun resultat attendu */
    printf("%s\n",dst);

    /* résultats conforment aux attentes */
    

    return 0;
}
