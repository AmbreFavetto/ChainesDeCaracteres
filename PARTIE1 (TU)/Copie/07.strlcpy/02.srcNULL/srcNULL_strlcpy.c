/*
 * Test du cas où src est à NULL
 *
 */

#include <stdio.h>
#include <bsd/string.h>

#define DSTSIZE 5

int main (void) {

    char * src = NULL;

    char dst[DSTSIZE];

    size_t ret;

    ret = strlcpy(dst,src,sizeof(dst));

    printf("strlcpy -- cas : src (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : ");
    printf("%lu\n",ret);
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : ");
    printf("%s\n",dst);

    return 0;
}
