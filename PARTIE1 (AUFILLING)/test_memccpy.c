/* 
 * Le but de ce programme est d'entrer 
 * plus de caractères que prevu dans la 
 * chaine1, c'est pour cela que la saisie se fait
 * avec scanf
 * Le fonction memccpy ne detecte pas la non présence 
 * du caractère nul dans la chaine1, la chaine1 est trop grande
 * alors memccpy copie une chaine trop grande dans la chaine2 et 
 * en plus aucun caractere nul.
 * Si on affiche pas les chaines il est impossible de savoir
 * que ça a bug.
 */

#include <stdio.h>
#include <string.h>

int main (void) {

    char chaine1[10];
    char chaine2[10];

    printf("> ");
    scanf("%s",chaine1);
    memccpy(chaine2,chaine1,'\0',strlen(chaine1)); 
    printf("Chaine1 --> %s\n",chaine1);
    printf("Chaine2 --> %s\n",chaine2);
    
    return 0;
}
