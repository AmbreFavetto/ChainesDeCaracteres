/*
 * Je rentre 11 caracteres - 1 dans chaine1
 * donc chaine1 n'a pas de caractere nul,
 * la copie s'effectue sans probleme dans
 * toutes les autres chaines
 *
 */

#include <stdio.h>
#include <string.h>

#define TAILLE 10

int main (void) {

    char chaine1[TAILLE];
    char chaine2[TAILLE];
    char chaine3[TAILLE];
    char chaine4[TAILLE];
   

    printf("> ");
    fgets(chaine1,11,stdin);
    printf("chaine1 --> %s\n",chaine1);
    printf("taille de chaine1 --> %lu\n",strlen(chaine1));
    
    memccpy(chaine2,chaine1,'\0',50);
    memccpy(chaine3,chaine2,'\0',20);
    memccpy(chaine4,chaine3,'\0',20);
  
    printf("chaine2 --> %s\n",chaine2);
    printf("taille de chaine2 --> %lu\n",strlen(chaine2));
    
    printf("chaine3 --> %s\n",chaine3);
    printf("taille de chaine3 --> %lu\n",strlen(chaine3));
    
    printf("chaine4 --> %s\n",chaine4);
    printf("taille de chaine4 --> %lu\n",strlen(chaine4));
  
    return 0;
}
