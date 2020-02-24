/*
 * Test du cas où dst est à NULL
 *
 */

#include <bsd/string.h>
#include <stdio.h>

int main (void) {

    char * dst = NULL;

    size_t ret;

    ret = strlcpy(dst,"12345",6);

    printf("strlcpy -- cas : dest (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : "); 
    printf("%lu\n",ret); 
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : "); 
    printf("%s\n",dst);

    return 0;
}
