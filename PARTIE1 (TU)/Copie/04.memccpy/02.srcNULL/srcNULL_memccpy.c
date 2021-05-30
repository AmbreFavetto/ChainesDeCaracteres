/*
 * Test du cas où src est à NULL
 *
 */

#include <stdio.h>
#include <string.h>

#define DSTSIZE 5

int main (void) {

    char * src = NULL;

    char dst[DSTSIZE];

    char * ret;

    ret = memccpy(dst,src,'\0',5);
    ret-=2;

    printf("memccpy -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : ");
    printf("%s\n",dst);

    return 0;
}
