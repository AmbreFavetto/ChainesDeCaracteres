/*
 * Test de la fonction quand on concatène src
 * à la dst vide pouvant accueillir tous
 * les caractères donc aucun problème 
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 6

/* chercher le caractère nul dans la chaîne et pas au delà du buffer */
void verif(char * s, int bufsize) {
    char * p;
    int i = 0;
    int ok = 0;
    for (p = s; i < bufsize; p++) {
	if (*p == '\0' && i == strlen(s)) {
           printf("'\\0' present -- position de '\\0' : %d\n",i); 
	   ok = 1;
        } 
	i++;
    }
    if (ok == 0) {
	printf("'\\0' non present\n"); 
    }
}

int main (void) {
  
    char * src = "abcd";
    char dst[BUFSIZE];
    char * ret;

    memset(dst,0,BUFSIZE);

    ret = strncat(dst,src,strlen(src) + 1);

    printf("strncat -- cas : NORMAL -- \n");
    printf("ret (ATTENDU) : a -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : abcd -- dst (REEL) : "); /* aucun resultat attendu */
    printf("%s\n",dst);
  
    verif(dst,BUFSIZE);
 
    /* résultats correspondent aux attentes */

    return 0;

}
