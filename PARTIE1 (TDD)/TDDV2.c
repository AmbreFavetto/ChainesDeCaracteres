/* 
 * Compilation :
 * 
 * gcc -c strtnt.c
 * gcc -c TDD.c
 * gcc -o TDD strtnt.o TDD.o
 * 
 * Tests pour copie et concatenation
 * 
 * toutes les fonctions de memccpy, strtnt (prof)
 *
 * strlen(src) == strlen(dest)
 * strlen(src) > strlen(dest) avec \0
 * strlen(src) < strlen(dest) avec \0
 * strlen(src) > strlen(dest) sans \0
 * strlen(src) < strlen(dest) sans \0
 * sizeof(src) == sizeof(dest)
 * sizeof(src) > sizeof(dest)
 * sizeof(src) < sizeof(dest)
 *
 * dest pas initialise et src initlialise
 * dest initialiase et src pas initialise
 * aucun des deux initialises
 * deux initialises
 *
 * pas de '\0'
 *
 * troncation silencieuse
 *
 * buffer overflow
 *
 * NE PAS OUBLIER DE TESTER LA METHODE DU PROF 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtnt.h"

#define NBTESTSBUFEGAUX 8
#define NBTESTSBUFSUP 8
#define NBTESTSBUFINF 8

#define BUF 80
#define BUFINF 60
#define BUFSUP 100

/*
 * Première méthode de memccpy du document de la partie 1
 */
void * memccpy1(void * dst, const void *  src, int c, size_t n) {

    void * pc = memchr(src,c,n);
    void * ret;

    if (pc) {
        n = (char*) pc - (char*) src + 1;
	ret = (char*) dst + n;
    } else {
        ret = 0;
    }

    memcpy(dst,src,n);
    
    return ret;
}

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


int main (void) {

    int i;
    
    int testsOk = 0; 
    
    /* chaîne à copier */    
    char * src = "Test avec une chaine de caractères suffisamment longue pour voir les bugs, yes";
 
    /* tableau de chaines de caractères contenant les chaines src copiées */
    char * chainesDest[NBTESTSBUFEGAUX];
    char * chainesDest1[NBTESTSBUFINF];
    char * chainesDest2[NBTESTSBUFSUP];

    /* permet de chercher une lettre */
    char * z;

    /* permet de chercher une lettre */
    char * q;

    printf("Taille de src : %lu\n",strlen(src) + 1);
    
    printf("\n******************************\n"
           "****** TESTS DES COPIES ******\n"
	   "******************************\n");
    
    printf("\n********** TESTS AVEC BUFFER EGAUX ET PRESENCE DU CARACTERE NUL **********\n\n");

	/* initialisation du tableau de chaines de caractères */
    for (i = 0; i < NBTESTSBUFEGAUX; i++) {
        chainesDest[i] = malloc(sizeof(char) * BUF);
    }
    
    /* copies avec les fonctions de copie avec le caractère nul */
    memccpy1(chainesDest[0],src,'\0',strlen(src) + 1);
    memccpy2(chainesDest[1],src,'\0',strlen(src) + 1);
    memccpy(chainesDest[2],src,'\0',strlen(src) + 1);
    strntcpy(chainesDest[3],sizeof(chainesDest[3]),src);	

    /* affichage des chaines destination */
    for (i = 0; i < 4; i++) {
        printf("chainesDest[%d] --> %s\n",i,chainesDest[i]);
        /* 
	     * permet de comparer les chaines destination et source 
	     * si les chaines sont égales alors le test a réussi 
	     */
	    if (strncmp(chainesDest[i],src,strlen(src) + 1) == 0) {
            testsOk++;
        }
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }
 
    printf("\n********** TESTS AVEC BUFFER EGAUX ET ABSENCE DU CARACTERE NUL **********\n\n");
	
	testsOk = 0;

	/* copies avec les fonctions de copie sans le caractère nul */
    memccpy1(chainesDest[4],src,'\0',strlen(src));
    memccpy2(chainesDest[5],src,'\0',strlen(src));
    memccpy(chainesDest[6],src,'\0',strlen(src));
    strntcpy(chainesDest[7],sizeof(chainesDest[7]),src);	

	/* affichage des chaines destination */
    for (i = 4; i < 8; i++) { 
        printf("chainesDest[%d] --> %s\n",i,chainesDest[i]);
        /* 
	     * permet de vérifier si les chaines de caractères ont 
	     * un caractère nul, dans notre cas si les chaînes destination
         * ont pas de caractère nul c'est normal car on copie pas le caractère nul
	     */
        
        /*
         * TROUVER TEST A FAIRE
         */
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }

	 printf("\n********** TESTS AVEC BUFFER SRC > BUFFER DEST AVEC CARACTERE NUL **********\n\n");
	
	 testsOk = 0;

	 for (i = 0; i < NBTESTSBUFINF; i++) {
         chainesDest1[i] = malloc(sizeof(char) * BUFINF);
     } 

	 /* 
      * copies avec les fonctions de copie de src vers dest
      * avec buf dest < buf src et avec la caractere nul
      */
    memccpy1(chainesDest1[0],src,'\0',strlen(src) + 1);
    memccpy2(chainesDest1[1],src,'\0',strlen(src) + 1);
    memccpy(chainesDest1[2],src,'\0',strlen(src) + 1);
    strntcpy(chainesDest1[3],sizeof(chainesDest1[3]),src);	

	/* affichage des chaines destination */
    for (i = 0; i < 4; i++) {
        printf("chainesDest1[%d] --> %s\n",i,chainesDest1[i]);
        /* 
	     * permet de vérifier si la taille de la chaine dest
         * est supérieure à la taille du buffer
	     */
	    if (strlen(chainesDest1[i]) > BUFINF){
            testsOk++;
        }
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }
    
	printf("\n********** TESTS AVEC BUFFER SRC > BUFFER DEST SANS CARACTERE NUL **********\n\n");
	
	testsOk = 0;

	/* 
     * copies avec les fonctions de copie de src vers dest
     * avec buf dest < buf src sans le caractère nul
     */
    memccpy1(chainesDest1[4],src,'\0',strlen(src));
    memccpy2(chainesDest1[5],src,'\0',strlen(src));
    memccpy(chainesDest1[6],src,'\0',strlen(src));
    strntcpy(chainesDest1[7],sizeof(chainesDest1[7]),src);	

	/* affichage des chaines destination */
    for (i = 4; i < 8; i++) {
        printf("chainesDest1[%d] --> %s\n",i,chainesDest1[i]);
        /* 
	     * permet de vérifier si la taille de la chaine dest
         * est supérieure à la taille du buffer
	     */
	    if ((strlen(chainesDest1[i]) > BUFINF) && (strncmp(chainesDest1[i],src,strlen(src) + 1) == 0)) {
            testsOk++;
        }
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }

    printf("\n********** TESTS AVEC BUFFER SRC < BUFFER DEST AVEC CARACTERE NUL **********\n\n");

    for (i = 0; i < NBTESTSBUFSUP; i++) {
        chainesDest2[i] = malloc(sizeof(char) * BUFSUP);
    }
	
	testsOk = 0;

	/* 
     * copies avec les fonctions de copie de src vers dest
     * avec buf dest < buf src sans le caractère nul
     */
    memccpy1(chainesDest2[0],src,'\0',strlen(src) + 1);
    memccpy2(chainesDest2[1],src,'\0',strlen(src) + 1);
    memccpy(chainesDest2[2],src,'\0',strlen(src) + 1);
    strntcpy(chainesDest2[3],sizeof(chainesDest2[3]),src);	

	/* affichage des chaines destination */
    for (i = 0; i < 4; i++) {
        printf("chainesDest2[%d] --> %s\n",i,chainesDest2[i]);
        /* 
	     * permet de vérifier si la taille de la chaine dest
         * est supérieure à la taille du buffer
	     */
	    if ((strlen(chainesDest2[i]) < BUFSUP) && (strncmp(chainesDest2[i],src,strlen(src) + 1) == 0)
             && strchr(chainesDest2[i],'\0')) {
            testsOk++;
        }
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }

    printf("\n********** TESTS AVEC BUFFER SRC < BUFFER DEST SANS CARACTERE NUL **********\n\n");
	
	testsOk = 0;

	/* 
     * copies avec les fonctions de copie de src vers dest
     * avec buf dest < buf src sans le caractère nul
     */
    memccpy1(chainesDest2[4],src,'\0',strlen(src));
    memccpy2(chainesDest2[5],src,'\0',strlen(src));
    memccpy(chainesDest2[6],src,'\0',strlen(src));
    strntcpy(chainesDest2[7],sizeof(chainesDest2[7]),src);	

	/* affichage des chaines destination */
    for (i = 4; i < 8; i++) {
        printf("chainesDest2[%d] --> %s\n",i,chainesDest2[i]);
        /* 
	     * permet de vérifier si la taille de la chaine dest
         * est supérieure à la taille du buffer
	     */
	    if ((strlen(chainesDest2[i]) < BUFSUP) && (strncmp(chainesDest2[i],src,strlen(src) + 1) == 0)) {
            testsOk++;
        }
    }

    if (testsOk == 4) {
        printf("Tous les tests OK\n");
    } else {
        printf("Tous les tests non OK, nb de tests OK : %d\n",testsOk);
    }

    return 0;

}
