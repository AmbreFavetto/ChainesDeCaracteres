#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

/*
 * Erreur de segmentation, a verifier 
 * Leo verifie si c'est moi qui vois 
 * pas de problème ou si vraiment ça marche pas
 */

int main (void) {

    char s1[BUFSIZE];
    char s2[BUFSIZE];
    char d[BUFSIZE];
    size_t dsize;
    char * p = NULL;

    printf("> ");
    fgets(s1,BUFSIZE,stdin);
    dsize = BUFSIZE;
    
    p = memccpy(d,s1,'\0',dsize);
    dsize -= (p - d - 1);
    memccpy(p - 1, s2,'\0',dsize);

    printf("s1 --> %staille %lu\n",s1,strlen(s1));
    printf("s2 --> %staille %lu\n",s2,strlen(s2));
    printf("d --> %staille %lu\n",d,dsize);

    return 0;
}
