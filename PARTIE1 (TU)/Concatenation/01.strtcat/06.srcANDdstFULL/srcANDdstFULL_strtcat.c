/*
 * Test de la valeur de retour et de la chaîne destination
 * en situation où src et destination contiennent des caractères 
 * et vérification si la troncation se fait correctement 
 * 
 * gcc -c strtnt.c
 * gcc -c srcANDdstFULL.c
 * gcc -o srcANDdstFULL strtnt.o srcANDdstFULL.o
 */


#include <stdio.h>
#include "strtnt.h"

#define BUFSIZE 6

/* chercher le caractère nul dans la chaîne et pas au delà du buffer */
void verif(char * s, int bufsize) {
    char * p;
    int i = 0;
    int ok = 0;
    for (p = s; i < bufsize; p++) {
	if (*p == '\0' && i == bufsize - 1) {
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

    ret = strtcat(dst,sizeof(dst),src);		  

    printf("strtcat -- cas : TEST DEBORDEMENT (TRONCATION) -- \n");
    printf("ret (ATTENDU) : 1 -- ret (REEL) : "); /* concaténation effectuée avec troncation */
    printf("%d\n",ret);

    printf("dst (ATTENDU) : 1234a -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    /* résultats correspondent aux attentes */

    return 0;
}
