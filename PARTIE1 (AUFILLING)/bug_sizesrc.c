#include <stdio.h>
#include <string.h>

#define SRCSIZE 20
#define DESTSIZE 10

/* 
 * Copier une chaine de caractere src dans
 * dest mais src.length() > dest.length()
 */
int main(void) {
 
    char src[SRCSIZE];
    char dest[DESTSIZE];

    printf("> ");
    scanf("%s",src);

    memccpy(dest,src,'\0',strlen(src)+1);

    printf("src --> %s et taille %lu\n",src,strlen(src));
    printf("dest --> %s et taille %lu\n",dest,strlen(dest));

    return 0;
}
