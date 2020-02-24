#include <bsd/string.h>
#include <stdio.h>

#define TAILLE 24

struct test {
    /* numero du test */
    int n;

    struct {
        char const * dest;
        char const * source;
	int taille;
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
    size_t p_out;

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
	{1, { chaine , "UN TEST GRAND", sizeof(chaine) } , { "UN TEST GRAND" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{2, { chaine , "UN TEST !", sizeof(chaine) } , { "UN TEST !" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{3, { chaine , "UN TEST", sizeof(chaine) } , { "UN TEST" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{4, { "" , "UN TEST GRAND", sizeof(s_out) } , { "UN TEST GRAND" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{5, { "" , "UN TEST !", sizeof(s_out) } , { "UN TEST !" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{6, { chaine , "UN TEST", sizeof(s_out) } , { "UN TEST" }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{7, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{8, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{9, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{10, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{11, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{12, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 

	/* SANS CARACTERE NUL */
	
	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source supérieure à la longueur de la chaîne destination 
	 */
	{13, { chaine , "UN TEST GRAND", sizeof(chaine) } , { "UN TEST GRAND" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{14, { chaine , "UN TEST !", sizeof(chaine) } , { "UN TEST !" }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{15, { chaine , "UN TEST", sizeof(chaine) } , { "UN TEST" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{16, { "" , "UN TEST GRAND", sizeof(s_out) } , { "UN TEST GRAND" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{17, { "" , "UN TEST !", sizeof(s_out) } , { "UN TEST !" }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{18, { chaine , "UN TEST", sizeof(chaine) } , { "UN TEST" }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{19, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{20, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{21, { "" , chaine, sizeof(s_out) } , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{22, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{23, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée sans caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{24, { chaine , chaine, sizeof(chaine) } , { chaine }, s_out}, 
    };

    int err = 0;
    size_t i;

    for (i = 0; i < TAILLE; i++) {
        
        struct test * p = a + i;

        p_out = strlcpy(s_out, p->in.source, p->in.taille);

        /* verifications */
        if (p_out != strlen(p->in.source)) {
            printf ("error at test # %d (incorrect string size)\n", p->n);
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


