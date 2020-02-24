#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

/*
 * Test du fonctionnement 
 * normal de memccpy
 */

/*
 * Verifie si un caractere nul est present
 * dans une chaine de caracteres
 */
void chercherNul(char * s) {

    char * p;    
    p = s;
    p += strlenAd(s) + 1;
    
    if(*p == '\0')
        printf("\\0  present dans %s\n",s);
}

/*
 * Calculer taille chaine
 */
int strlenAd(char * s) {
    char * p;
    for (p=s; *p; p++);
    return (p-s);
}

int main (void) {

    char dest[BUFSIZE];
    char src[BUFSIZE];
    
    printf("> ");
    fgets(src,BUFSIZE,stdin);
    
    memccpy(dest,src,'\0',strlenAd(src) + 1);
   
    printf("src -> %s\n",src);
    printf("dest -> %s\n",dest);
  
    chercherNul(src);
    chercherNul(dest);
    
    printf("Taille de src --> %d\n",strlenAd(src));
    printf("Taille de dest --> %d\n",strlenAd(dest));    

    return 0;
}
