/*   memccpy_to_init.c   */

#include <stdio.h>
#include <string.h>

#define TAILLE 10

int main(void) {

    char sansinit[TAILLE];

    char initvide[TAILLE] = "";

    char initnonvide[TAILLE] = "aeffacer";

    char tocpy[] = "copie";


    memccpy(sansinit, tocpy, '\0', strlen(tocpy)+1);

    memccpy(initvide, tocpy, '\0', strlen(tocpy)+1);

    memccpy(initnonvide,tocpy, '\0', strlen(tocpy)+1);


    printf("copie du mot %s dans une chaine non initialisée,\nresultat : %s\n", tocpy, sansinit);

    printf("copie du mot %s dans une chaine vide,\nresultat : %s\n", tocpy, initvide);

    printf("copie du mot %s dans une chaine nonvide,\nresultat : %s\n", tocpy, initnonvide);

    return(0);
}
