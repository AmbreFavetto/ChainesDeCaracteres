/*
 * Test de la concaténation quand dst et src
 * ont des caractères et la concaténation de ces 
 * caractères entraineraient un débordement de tampon
 * donc la concaténation ne doit pas de produire 
 * car cette fonction n'autorise pas la troncation
 *
 * gcc -c strtnt.c
 * gcc -c fichier.c
 * gcc -o fichier strtnt.o fichier.o
 */

#include <stdio.h>
#include <string.h>
#include "strtnt.h"

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

    const char * src = "abcd";

    char dst[BUFSIZE] = "1234";

    int ret;

    ret = strntcat(dst,sizeof(dst),src);		  

    printf("strntcat -- cas : TEST DEBORDEMENT OU NON -- \n");
    printf("ret (ATTENDU) : -3 -- ret (REEL) : "); 
    printf("%d\n",ret);

    /* le résultat est la chaîne dst car la troncation ne peut pas se faire */
    printf("dst (ATTENDU) : 1234 -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    /* résultats correspondent aux attentes */

    return 0;
}
