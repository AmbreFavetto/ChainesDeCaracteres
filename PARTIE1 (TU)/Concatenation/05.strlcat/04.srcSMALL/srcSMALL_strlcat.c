/*
 * Cas ou la on va concaténer la chaîne src à la chaîne dst et celle-ci
 * peut accueillir sans problème cette concaténation
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
  
    char * src = "cdef";
    char dst[BUFSIZE] = "ab";
    int ret;

    ret = strlcat(dst,src,sizeof(dst));

    printf("strlcat -- cas : src SMALL -- \n");
    printf("ret (ATTENDU) : 6 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : abcdef -- dst (REEL) : "); /* aucun resultat attendu */
    printf("%s\n",dst);
  
    verif(dst,BUFSIZE);

    /* résultats correspondent aux attentes */

    return 0;

}
