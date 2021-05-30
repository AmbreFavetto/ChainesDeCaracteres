/*
 * Cas où la chaîne src contient des caractères et dst est vide 
 * et leur concaténation va provoquer un débordement donc on regarde 
 * le comportement de la fonction
 */

#include <stdio.h>
#include <bsd/string.h>

#define BUFSIZE 3

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
  
    char * src = "abcdef";
    char dst[BUFSIZE];
    int ret;

    memset(dst,0,BUFSIZE);

    ret = strlcat(dst,src,sizeof(dst));

    printf("strlcat -- cas : DEBORDEMENT -- \n");
    printf("ret (ATTENDU) : 6 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : ab -- dst (REEL) : "); 
    printf("%s\n",dst);
  
    verif(dst,BUFSIZE);

    /* résultats correspondent aux attentes */
    return 0;

}
