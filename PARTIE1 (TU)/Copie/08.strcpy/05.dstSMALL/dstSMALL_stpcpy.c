/*
 * Test de la valeur de retour et de la chaîne destination
 * en situation où src est trop petite 
 * utiliser fno-stack-protector pour bien voir le résultat
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 3

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

    const char * src = "12345";

    char dst[BUFSIZE];

    char * ret;

    ret = strcpy(dst,src) /* ret = '\0' */;

    printf("strcpy -- cas : NORMAL -- \n");
    printf("ret (ATTENDU) : 1 -- ret (REEL) : ");
    printf("%c\n",*ret);

    printf("dst (ATTENDU) : 12 -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    return 0;
}
