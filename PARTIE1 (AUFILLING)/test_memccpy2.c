/* 
 * Le but de ce programme est d'entrer 
 * plus de caractères que prevu dans la 
 * chaine1, j'utilise fgets mais au lieu de rentrer strlen(chaine1)
 * caracteres j'en entre plus que prevu.
 * Le fonction memccpy ne detecte pas la non présence 
 * du caractère nul dans la chaine1.
 * Je copie 10 caractères de chaine1 dans chaine2 qui a une taille de 10
 * alors ni chaine1 ni chaine2 ne possède de caractère nul.
 * Si on affiche pas les chaines il est impossible de savoir
 * que ça a bug.
 * Et tout cela est possible même sans l'option -fn-stack-protector 
 */

#include <stdio.h>
#include <string.h>

int main (void) {

    char chaine1[10];
    char chaine2[10];
    char chaine3[20];

    printf("> ");
    /* je lui autorise 15 caractères dans chaine1 alors qu'elle fait 10 */
    fgets(chaine1,15,stdin);
    memccpy(chaine2,chaine1,'\0',10); 
    /* j'affiche pour voir que ça a bug mais sinon on peut pas le savoir */
    printf("Chaine1 --> %s\n",chaine1);
    printf("Chaine2 --> %s\n",chaine2);
    
    memccpy(chaine3,chaine2,'\0',strlen(chaine2));
    printf("Chaine3 --> %s\n",chaine3);

    return 0;
}
