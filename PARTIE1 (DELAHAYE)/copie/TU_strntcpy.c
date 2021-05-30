/* 
 * gcc -c strtnt.c
 * gcc -c TU_strntcpy.c
 * gcc -o TU_strntcpy strtnt.o TU_strntcpy.o
 */

#include <string.h>
#include <stdio.h>
#include "strtnt.h" 

#define TAILLE 1

struct test {
    /* numero du test */
    int n;

    struct {
        char const * dest;
	int taille;
        char const * source;
    } in;
   
    struct {
        char const * s;
    } out;

    char const * ret;
};

int main (void) {
	
    /* chaîne de caractères avec le résultat de la copie */
    char s_out[10];

    /* chaîne de caractères pour tester les chaînes non initailisées */
    char chaine[10];

    /* retour de la fonction */
    int p_out;

    /* liste des tests */
    struct test a[TAILLE] = {
        /* 
	 * utiliser option -fno-stack-protector pour pas détecter stack smashing 
         * mais cette option n'est pas obligatoire avec la copie car certaines méthodes
         * ne détecte pas les buffer overflow
         */

	/* AVEC CARACTERE NUL */

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source supérieure à la longueur de la chaîne destination 
	 */
	{1, { chaine , sizeof(chaine), "UN TEST GRAND" } , { "UN TEST GRAND" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{2, { chaine , sizeof(chaine), "UN TEST !" } , { "UN TEST !" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{3, { chaine , sizeof(chaine), "UN TEST" } , { "UN TEST" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{4, { "" , sizeof(s_out), "UN TEST GRAND" } , { "UN TEST GRAND" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{5, { "" , sizeof(s_out), "UN TEST !" } , { "UN TEST !" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{6, { chaine , sizeof(chaine), "UN TEST" } , { "UN TEST" }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{7, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{8, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{9, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{10, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{11, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{12, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}, 

	/* SANS CARACTERE NUL */
	
	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source supérieure à la longueur de la chaîne destination 
	 */
	{13, { chaine , sizeof(chaine), "UN TEST GRAND" } , { "UN TEST GRAND" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{14, { chaine , sizeof(chaine), "UN TEST !" } , { "UN TEST !" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{15, { chaine , sizeof(chaine), "UN TEST" } , { "UN TEST" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{16, { "" , sizeof(s_out), "UN TEST GRAND" } , { "UN TEST GRAND" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{17, { "" , sizeof(s_out), "UN TEST !" } , { "UN TEST !" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{18, { chaine , sizeof(chaine), "UN TEST" } , { "UN TEST" }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{19, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{20, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{21, { "" , sizeof(s_out), chaine } , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{22, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{23, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée sans caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{24, { chaine , sizeof(chaine), chaine } , { chaine }, s_out}
    };

    int err = 0;
    size_t i;

    for (i = 0; i < TAILLE; i++) {
        
        struct test * p = a + i;

        p_out = strntcpy(s_out, p->in.taille, p->in.source);

        /* verifications */
        if (p_out < 0) {
            printf ("error at test # %d (wrong returned address)\n", p->n);
            err = 1;
        }

        if (strcmp(s_out, p->out.s) != 0) {
            printf("error at test # %d (wrong destination string) : %s\n", p->n, s_out);
            err = 1;
        }
    }

    /* validation finale */
    if (!err) {
        puts ("P A S S E D");
    }

    return 0;
}


