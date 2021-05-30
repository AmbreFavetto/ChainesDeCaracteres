/**
 * Fonction test0_abscaracnull.c
 * qui test la fonction memccpy dans
 * le cas de la copie d'une chaîne 
 * mal formée
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZESRC 5
#define SIZEDEST 7 

int main (void) {
    char src[SIZESRC];
    char dest[SIZEDEST];

    printf("Chaîne superieure à 5 > ");
    fgets(src, 7, stdin);

    memccpy(dest, src, '\0', strlen(src) + 1);

    printf("Taille de base : %d\nsrc --> %s\ntaille de src : %lu\n",SIZESRC,src,strlen(src));

    if(strchr(src, '\0') != NULL && strlen(src) < SIZESRC) {
	    printf("Le caractère null a bien été trouvé.\n\n");
    } else {
	    printf("Le caractère null n'a pas été trouvé\n\n");
    }

    printf("Taille de base : %d\ndest --> %s\ntaille de dest : %lu\n",SIZEDEST,dest,strlen(dest));
   
    if(strchr(dest, '\0') != NULL && strlen(dest) < SIZEDEST) {
            printf("Le caractère null a bien été trouvé.\n\n");
    } else {
            printf("Le caractère null n'a pas été trouvé\n\n");
    }

    return 0;
}

