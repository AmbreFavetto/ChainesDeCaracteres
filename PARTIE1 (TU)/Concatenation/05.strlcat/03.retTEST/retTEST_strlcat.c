/*
 * Cas où on concatène une chaîne src contenant des caractères
 * à une chaîne dst pouvant accueillir tous les caractères 
 */

#include <stdio.h>
#include <bsd/string.h>

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
  
    char * src = "abcd";
    char dst[BUFSIZE];
    int ret;

    memset(dst,0,BUFSIZE);

    ret = strlcat(dst,src,sizeof(dst));

    printf("strlcat -- cas : NORMAL -- \n");
    printf("ret (ATTENDU) : 4 -- ret (REEL) : ");
    printf("%d\n",ret);
    printf("dst (ATTENDU) : abcd -- dst (REEL) : "); 
    printf("%s\n",dst);

    /* résultats correspondent aux attentes */
  
    verif(dst,BUFSIZE);

    return 0;

}
