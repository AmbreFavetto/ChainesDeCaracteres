/*
 * Test de la valeur de retour et de la chaîne destination
 * avec dst trop petit
 * fno-stack-protector pour bien voir
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 3

/*
 * Première méthode de memccpy du document de la partie 1
 */
void * memccpy1(void * dst, const void *  src, int c, size_t n) {

    void * pc = memchr(src,c,n);
    void * ret;

    if (pc) {
        n = (char*) pc - (char*) src + 1;
	ret = (char*) dst + n;
    } else {
        ret = 0;
    }

    memcpy(dst,src,n);
    
    return ret;
}

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

    memset(dst,0,BUFSIZE);

    ret = memccpy1(dst,src,'\0',strlen(src));
    ret-=2;

    printf("memccpy1 -- cas : DST SMALL AND NOT '\\0' -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : ");
    printf("%c\n",*ret);

    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : ");
    printf("%s\n",dst);

    verif(dst,BUFSIZE);

    return 0;
}
