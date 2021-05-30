/*   cpyFct.c   */

#include <stdio.h>
#include <bsd/string.h>
#include <time.h>
#include <sys/time.h>
#include "strtnt.h"

#define TAILLE 10

/* initialiser à 200 000 000 pour tests finaux */
#define NBTESTSCPY 200000000

int main(void) {

    /* Clock used to count execution time from a function */
    clock_t tspend;
    struct timeval t0,
                    t1;

    int i = 0;

    /* String to copy in target with the same number */
    char tocpy1[] = "coucou";
    /* target to cy the string from the tocpy with the same number */
    char cpyTarget1[TAILLE];

    char tocpy2[] = "coucou";
    char cpyTarget2[TAILLE];

    char tocpy3[] = "coucou";
    char cpyTarget3[TAILLE];

    printf("\n--------------- %i tests pour les fonctions de copie---------------\n\n", NBTESTSCPY );


    /****************************
     ****** TESTS DE COPIE ******
     *****************************/

    /* TEST MEMCCPY */
    tspend = clock();
    for ( i = 0; i < NBTESTSCPY; i++)
        memccpy(cpyTarget1, tocpy1, '\0', strlen(tocpy1)+1);
    tspend = clock() - tspend;
    printf("copie de %s avec memccpy %i fois = %.2Lf secondes\n", tocpy1, NBTESTSCPY, (long double) tspend/CLOCKS_PER_SEC);
    printf("Resultat : %s\n", cpyTarget1);

    /* TEST STRLCPY */
    tspend = clock();
    for ( i = 0; i < NBTESTSCPY; i++)
        strlcpy(cpyTarget2, tocpy2, sizeof(cpyTarget2));
    tspend = clock() - tspend;
    printf("copie de %s avec strlcpy %i fois = %.2Lf secondes\n", tocpy2, NBTESTSCPY, (long double) tspend/CLOCKS_PER_SEC);
    printf("Resultat : %s\n", cpyTarget2);

    /* TEST STRNTCPY */
    tspend = clock();
    for ( i = 0; i < NBTESTSCPY; i++)
        strntcpy(cpyTarget3, sizeof(cpyTarget3), tocpy3);
    tspend = clock() - tspend;
    printf("copie de %s avec strncpy %i fois = %.2Lf secondes\n", tocpy3, NBTESTSCPY, (long double) tspend/CLOCKS_PER_SEC);
    printf("Resultat : %s\n", cpyTarget3);
