/*
 * Cas où on essaye de concaténer src qui est NULL
 * à une chaîne dst de 6
 */

#include <stdio.h>
#include <bsd/string.h>

#define BUFSIZE 6

int main (void) {


    char * src = NULL;
    char dst[BUFSIZE];
    int ret;

    memset(dst,0,BUFSIZE);

    ret = strlcat(dst,src,sizeof(dst));
    
    printf("strlcat -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */
   
    return 0;
}


