/*
 * Test de la valeur de retour et de la chaîne destination
 * en situation normale
 */

/* 
 * gcc -c strtnt.c
 * gcc -c TU_strntcpy.c
 * gcc -o TU_strntcpy strtnt.o TU_strntcpy.o
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

    const char * src = "abcd";

    char dst[BUFSIZE];

    int ret;

    ret = strtcpy(dst,sizeof(dst),src);		  

    printf("strtcpy -- cas : NORMAL -- \n");
    printf("ret (ATTENDU) : 0 -- ret (REEL) : ");
    printf("%d\n",ret);

    printf("dst (ATTENDU) : abcd -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    return 0;
}
