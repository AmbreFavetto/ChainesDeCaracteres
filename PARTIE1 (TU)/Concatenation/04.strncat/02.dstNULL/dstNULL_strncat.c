/*
 * Test de la fonction quand src contient des caractères 
 * mais la destination est NULL
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    char * src = "1234";
    char * dst = NULL;
    char * ret;

    ret = strncat(dst,src,strlen(src) + 1);
	
    printf("strncat -- cas : dst (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */

    return 0;
}
