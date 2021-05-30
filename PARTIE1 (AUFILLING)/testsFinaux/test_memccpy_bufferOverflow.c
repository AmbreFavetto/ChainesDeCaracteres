#include <stdio.h>
#include <string.h>

#define SRCSIZE 20
#define DSTSIZE 10

/*
 * Programme qui permet de faire un
 * débordement de tampon 
 * dans dst car dst a une taille inferieure 
 * à src
 */

int main (void) {

    char src[SRCSIZE];
    char dst[DSTSIZE];

    printf("Entrez une chaine de caractères supérieure à 10 : ");
    fgets(src,SRCSIZE,stdin);
    
    /* copie de src qui fait une taille supérieure à 10
     * dans dst qui fait une taille de 10
     * donc buffer overflow dans dst
     */
    memccpy(dst,src,'\0',strlen(src) + 1);

    printf("src --> %s\n",src);
    printf("Taille de src : %lu\n",strlen(src));

    printf("dst --> %s\n",dst);
    printf("Taille de dst : %lu\n",strlen(dst));    

    return 0;

}
