/*
 * Test de la concaténation de src avec du contenu 
 * dans dst qui est NULL
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

    ret = strntcat(dst,sizeof(dst),src);

    printf("strntcat -- cas : dst (NULL) -- \n");
    printf("ret (ATTENDU) : -1 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */
   
    return 0;
}
