/*
 * Test de la concaténation en situation où src peut-être concaténé
 * à destination dans encombre 
 *
 * gcc -c strtnt.c
 * gcc -c fichier.c
 * gcc -o fichier strtnt.o fichier.o
 */

#include <stdio.h>
#include <string.h>
#include "strtnt.h"

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

    char * src = "1234";
    char dst[BUFSIZE];
    int ret;

    memset(dst,0,BUFSIZE);

    ret = strntcat(dst,sizeof(dst),src);

    printf("strntcat -- cas : NORMALE -- \n");
    printf("ret (ATTENDU) : 0 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : 1234 -- dst (REEL) : "); 
    printf("%s\n",dst);

    verif(dst,BUFSIZE);
  
    /* résultats correspondent aux attentes */

    return 0;
}
