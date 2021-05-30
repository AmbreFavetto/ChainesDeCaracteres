/*
 * Test quand src et dst ont des caractères et 
 * la concaténation de src est faisable car tous les 
 * caractères pourront rentrer
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

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

    ret = strncat(dst,src,strlen(src) + 1);

    printf("strncat -- cas : SRC SMALL -- \n");
    printf("ret (ATTENDU) : a -- ret (REEL) : ");
    printf("%c\n",*ret);
    printf("dst (ATTENDU) : abcdef -- dst (REEL) : ");
    printf("%s\n",dst);
  
    verif(dst,BUFSIZE);

    /* résultats correspondent aux attentes */

    return 0;

}
