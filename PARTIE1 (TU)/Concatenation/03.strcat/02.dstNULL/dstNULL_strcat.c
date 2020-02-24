/*
 * Test de la fonction quand on concatène 
 * une chaîne src à une chaîne dst NULL
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    char * src = "1234";
    char * dst = NULL;
    char * ret;

    ret = strcat(dst,src);
	
    printf("strcat -- cas : dst (NULL) -- \n");
    printf("ret (ATTENDU) : -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : -- dst (REEL) : "); /* aucun resultat attendu */
    printf("%s\n",dst);

    /* provoque une erreur de segmentation */

    return 0;
}
