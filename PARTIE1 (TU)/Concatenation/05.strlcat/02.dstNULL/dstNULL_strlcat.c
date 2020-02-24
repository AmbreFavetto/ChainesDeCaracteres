/*
 * Cas où on essaye de concaténer une chaîne src contenant des caractères
 * à une chaîne dst qui est NULL
 */

#include <stdio.h>
#include <bsd/string.h>

int main(void) {

    char * src = "1234";
    char * dst = NULL;
    int ret;

    ret = strlcat(dst,src,sizeof(dst));
	
    printf("strlcat -- cas : dst (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */
    return 0;
}
