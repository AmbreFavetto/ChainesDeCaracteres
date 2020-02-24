#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

/*
 * Permet de vérifier l'existence d'un 
 * caractere nul dans une chaine de caracteres
 */
void parcours(char * s) {
    
    char * p;
    p  = s;
    while (*p != '\0') {
        p++;
    }    

    p++;
    if (*p == '\0') {
        printf("Caractere nul present dans %s\n",s);
    } 
}

/*
 * Permet d'enlever le 
 * caractère '\n'
 */
void enleverN(char * s) {
   
    char * p;
    p = s;
    while (*p != '\0') {
        if (*p == '\n') 
	    *p = '\0';
	p++;
    }
}

int main (void) {

    char src[BUFSIZE];
    char dest[BUFSIZE];

    printf("> ");
    fgets(src,BUFSIZE,stdin);
    enleverN(src);
    parcours(src);
    printf("src -> "); fputs(src,stdout); printf("\n");
    
    memccpy(dest,src,'\0',strlen(src));
    
    enleverN(dest);
    parcours(dest);
    printf("dest -> "); fputs(dest,stdout); printf("\n");
    return 0;
}
