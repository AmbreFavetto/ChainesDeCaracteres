#include <string.h>
#include <stdio.h>

#define TAILLE 24

/*
 * Seconde méthode de memccpy du document de la partie 2
 */
void * memccpy2(void * dst, const void * src,int c, size_t n) {

    const char * s = src;
    char * ret;
    
    for (ret = dst; n; ++ret, ++s, --n) {
	*ret = *s;
        if ((unsigned char) * ret == (unsigned char)c)
            return ret + 1;
    }

    return 0;
}

struct test {
    /* numero du test */
    int n;

    struct {
        char const * dest;
        char const * source;
	char carac;
	int aCopier;
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

    char sup[] = { 'U','N',' ','T','E','\0','T',' ','G','R','A','N','D' };
    char egal[] = { 'U','N',' ','T','E','\0','T',' ','!' };
    char inf[] = { 'U','N',' ','T','E','\0','T' };

    /* retour de la fonction */
    char * p_out;

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
	{1, { chaine , sup, '\0', 14} , { sup }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{2, { chaine , egal, '\0', 10} , { egal }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{3, { chaine , inf, '\0', 8} , { inf }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{4, { "" , sup, '\0', 14} , { sup }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{5, { "" , egal, '\0', 10} , { egal }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée avec caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{6, { chaine , inf, '\0', 8} , { inf }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{7, { "" , chaine , '\0', 14} , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{8, { "" , chaine , '\0', 10} , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée avec caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{9, { "" , chaine , '\0', 8} , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{10, { chaine , chaine , '\0', 14} , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{11, { chaine , chaine , '\0', 10} , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{12, { chaine , chaine , '\0', 8} , { chaine }, s_out}, 

	/* SANS CARACTERE NUL */
	
	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source supérieure à la longueur de la chaîne destination 
	 */
	{13, { chaine , sup, '\0', 13} , { sup }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaîne destination 
	 */
	{14, { chaine , egal, '\0', 9} , { egal }, s_out}, 

	/* 
	 * chaîne source initialisée dans chaîne destination non initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination 
	 */
	{15, { chaine , inf, '0', 7} , { inf }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul 
	 * longueur de la chaîne source supérieure à la longueur de la chaîne destination
	 */
	{16, { "" , sup, '\0', 13} , { sup }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source égale à la longueur de la chaine destination
	 */
	{17, { "" , egal , '\0', 9} , { egal }, s_out}, 

	/*
	 * chaîne source initialisée dans chaîne destination initialisée sans caractère nul
	 * longueur de la chaine source inférieure à la longueur de la chaîne destination
	 */
	{18, { chaine , inf , '\0', 7} , { inf }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaîne source supérieure supérieure à la longueur de la chaine destination
         */
	{19, { "" , chaine , '\0', 13} , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
         * chaine source égale à la longueur de la chaine destination
         */
	{20, { "" , chaine , '\0', 9} , { chaine }, s_out}, 

	/*
	 * chaîne source non initialisée dans chaîne destination initialisée sans caractère nul
	 * chaine source inférieure à la longueur de la chaine destination
	 */
	{21, { "" , chaine , '\0', 7} , { chaine }, s_out}, 

	/*
	 * chaîne source non iniialisée dans chaîne destination non initialisée avec caractere nul
	 * chaine source supérieure à la longueur de la chaine destination
	 */
	{22, { chaine , chaine , '\0', 13} , { chaine }, s_out}, 

	/*
         * chaîne source non initialisée dans chaîne destination non initialisée avec caractère nul
         * chaîne source égale à la longueur de la chaine destination
         */
	{23, { chaine , chaine ,'\0',  9} , { chaine }, s_out}, 

	/*
 	 * chaîne source non initialisée dans chaîne destination non initialisée sans caractère nul 
	 * chaîne source inférieure à la longueur de la chaine destination
	 */
	{24, { chaine , chaine , '\0', 7} , { chaine }, s_out}
    };

    int err = 0;
    size_t i;

    for (i = 0; i < TAILLE; i++) {
        
        struct test * p = a + i;

        p_out = memccpy2(s_out, p->in.source, p->in.carac, p->in.aCopier);

        /* verifications */
        if (*p_out != 'T') {
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


