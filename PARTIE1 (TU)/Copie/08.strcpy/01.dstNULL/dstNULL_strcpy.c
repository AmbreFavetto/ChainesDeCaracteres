/*
 * Test du cas où dst est à NULL
 *
 */

#include <string.h>
#include <stdio.h>

int main (void) {

    char * dst = NULL;

    char * ret;

    ret = strcpy(dst,"12345");

    printf("strcpy -- cas : dest (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : "); 
    printf("%c\n",*ret); 
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : "); 
    printf("%s\n",dst);

    return 0;
}
