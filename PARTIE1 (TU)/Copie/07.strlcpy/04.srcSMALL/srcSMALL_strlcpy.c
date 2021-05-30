/*
 * Test de la valeur de retour et de la chaîne destination
 * en situation normale
 */

#include <stdio.h>
#include <bsd/string.h>

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

    const char * src = "123456a";

    char dst[BUFSIZE];

    size_t ret;

    ret = strlcpy(dst,src,sizeof(dst));
    
    printf("strlcpy -- cas : NORMAL -- \n");
    printf("ret (ATTENDU) : 7 -- ret (REEL) : ");
    printf("%lu\n",ret);

    printf("dst (ATTENDU) : 12345 -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    return 0;
}
