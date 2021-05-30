/*
 * Test de la concaténation d'une src NULL
 * à une destination
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 6

int main (void) {


    char * src = NULL;
    char dst[BUFSIZE];
    char * ret;

    memset(dst,0,BUFSIZE);

    ret = strcat(dst,src);
    
    printf("strcat -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);
  
    /* provoque une erreur de segmentation */
   
    return 0;
}


