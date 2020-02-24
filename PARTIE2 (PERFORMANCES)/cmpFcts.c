/*   cmpFcts.c   */

#include <stdio.h>
#include <bsd/string.h>
#include <time.h>
#include <sys/time.h>
#include "strtnt.h"

#define TAILLE 10

/* initialiser à 200 000 000 pour tests finaux */
#define NBTESTSCPY 200000000

#define NBTESTSCAT 100000

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

    /* part of the concatenation to add to the target with the same number */
    char * toconcat1[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
                            "n","o","p","q","r","s","t","u","v","w","x","y","z"};
    /* first part of the concatenation to be followed by the toconcat with the same number */
    char concatTarget1[NBTESTSCAT];


    char * toconcat2[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
                            "n","o","p","q","r","s","t","u","v","w","x","y","z"};
    /* strntcat ne marche pas si la chaine n'est pas initialisée */
    char concatTarget2[NBTESTSCAT] = "";



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

    printf("\n\n--------------- %i tests pour les fonctions de concatenation ---------------\n\n", NBTESTSCAT);
    /******************************
     *** TESTS DE CONCATENATION ***
     ******************************/

    /* TEST STRLCAT */
    tspend = clock();
    for (int i = 0; i < NBTESTSCAT; i++)
        strlcat(concatTarget1, toconcat1[i%26], sizeof(concatTarget1));
    tspend = clock() - tspend;
    printf("concatenation de l'alphabet lettre par lettre avec strlcat = %.2Lf secondes\n", (long double) tspend/CLOCKS_PER_SEC);
    /* printf("Resultat : %s\n", concatTarget1); */

    /* TEST STRNTCAT */
    tspend = clock();
    for (int i = 0; i < NBTESTSCAT; i++)
        strntcat(concatTarget2, sizeof(concatTarget2), toconcat2[i%26]);
    tspend = clock() - tspend;
    printf("concatenation de l'alphabet lettre par lettre avec strncat = %.2Lf secondes\n", (long double) tspend/CLOCKS_PER_SEC);
    /* printf("Resultat : %s\n", concatTarget2); */


    return 0;
}
