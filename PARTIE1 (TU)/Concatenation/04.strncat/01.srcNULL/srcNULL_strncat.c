/*
 * Test de la fonction quand la src est NULL
 * et la destination a une longueur de 
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 6

int main (void) {


    char * src = NULL;
    char dst[BUFSIZE];
    char * ret;

    memset(dst,0,BUFSIZE);

    ret = strncat(dst,src,strlen(src) + 1);
    
    printf("strncat -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */
   
    return 0;
}


