/*
 * Test de la concaténation quand dst a un tampon 
 * de 6 et src est NULL
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

    ret = strntcat(dst,sizeof(dst),src);

    printf("strntcat -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : -2 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); /* rien car aucune chaîne attendue*/
    printf("%s\n",dst);				
    
    /* résultats corrects */

    return 0;
}
