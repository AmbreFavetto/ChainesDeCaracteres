/*
 * Test de la fonction où src est trop grande pour être concaténée
 * à la chaîne dst donc on teste le comportement de la fonction
 *
 * utiliser -fno-stack-protector
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 5

/* utiliser option -fno-stack-protector */

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
  
    char * src = "cdef";
    char dst[BUFSIZE] = "ab";
    char * ret;

    ret = strcat(dst,src);

    printf("strcat -- cas : DST SMALL -- \n");
    printf("ret (ATTENDU) : a -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : abcd -- dst (REEL) : "); 
    printf("%s\n",dst);
  
    verif(dst,BUFSIZE);

    /* résultats incorrects */

    return 0;

}
