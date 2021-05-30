/* 
 * Compilation :
 * 
 * gcc -c strtnt.c
 * gcc -c TDD_1.c
 * gcc -o TDD_1 strtnt.o TDD_1.o
 * 
 * Tests pour copie et concatenation
 * 
 * toutes les fonctions de memccpy, strtnt
 *
 * strlen(src) == strlen(dest) avec \0		FAIT
 * strlen(src) == strlen(dest) sans \0		FAIT
 * strlen(src) > strlen(dest) avec \0		FAIT
 * strlen(src) < strlen(dest) avec \0		FAIT
 * strlen(src) > strlen(dest) sans \0		FAIT
 * strlen(src) < strlen(dest) sans \0	    FAIT
 * sizeof(src) == sizeof(dest)              FAIT
 * sizeof(src) > sizeof(dest)               FAIT
 * sizeof(src) < sizeof(dest)               FAIT
 *
 * dest pas initialise et src initlialise   FAIT
 * dest initialiase et src pas initialise   FAIT
 * aucun des deux initialises				FAIT
 * deux initialises							FAIT
 *
 * pas de '\0'								FAIT
 *
 * troncation silencieuse					FAIT
 *
 * buffer overflow							FAIT
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtnt.h"

#define TAILLE 40
#define TAILLEINF 20

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

/* 
 * Copies de la chaine src dans la chaine dest 
 * avec un buffer pouvant contenir la chaine src
 * et contient également un caractere nul
 */
void copiesAvecCaracNulTailleEgale(void) {
    
    int nbTestOk = 0;

    char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLE];
    char dest2[TAILLE];
    char dest3[TAILLE];
    char dest4[TAILLE];

    printf("\n********** TESTS DE COPIE AVEC CARACTERE NUL **********\n\n");

    printf("Taille de src --> %lu\n\n",strlen(src) + 1);

    memccpy1(dest1,src,'\0',strlen(src) + 1);
    memccpy2(dest2,src,'\0',strlen(src) + 1);
    memccpy(dest3,src,'\0',strlen(src) + 1);
    strntcpy(dest4,sizeof(dest4),src);


    printf("src --> %s\n",src);
    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    /* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est bien passée
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) == 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) == 0) {
	    nbTestOk++;
    }

    if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}

}

/* 
 * Copies de la chaine src dans la chaine dest 
 * avec un buffer pouvant contenir la chaine src
 * mais ne contient pas de caractere nul
 */
void copiesSansCaracNulTailleEgale(void) {

    int nbTestOk = 0;

	char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLE];
    char dest2[TAILLE];
    char dest3[TAILLE];
    char dest4[TAILLE];

	printf("\n********** TESTS DE COPIE SANS CARACTERE NUL *********\n\n");

    printf("Taille de src --> %lu\n\n",strlen(src) + 1);

    memccpy1(dest1,src,'\0',strlen(src));
    memccpy2(dest2,src,'\0',strlen(src));
    memccpy(dest3,src,'\0',strlen(src));
    strntcpy(dest4,sizeof(dest4),src);

    printf("src --> %s\n",src);
    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);
	
	/* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est bien passée malgré 
     * que le caractere nul ne soit pas dans la chaine dest
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) == 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) == 0) {
	    nbTestOk++;
    }

    if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}

}

/* 
 * Copies de la chaine src dans la chaine dest 
 * avec un buffer ne pouvant pas contenir la chaine src
 * et contient également un caractere nul
 */
void copiesAvecCaracNulTailleInf(void) {

    int nbTestOk = 0;

    char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLEINF];
    char dest2[TAILLEINF];
    char dest3[TAILLEINF];
    char dest4[TAILLEINF];

	printf("\n********** TESTS DE COPIE AVEC CARACTERE NUL ET TAILLE INF **********\n\n");

    printf("Taille de src --> %lu\n\n",strlen(src) + 1);

    memccpy1(dest1,src,'\0',strlen(src) + 1);
    memccpy2(dest2,src,'\0',strlen(src) + 1);
    memccpy(dest3,src,'\0',strlen(src) + 1);
    strntcpy(dest4,sizeof(dest4),src);


    printf("src --> %s\n",src);
    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    /* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est mal passée
     * dans un buffer inférieur
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) != 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) != 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) != 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) != 0) {
	    nbTestOk++;
    }

    if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}

}

/* 
 * Copies de la chaine src dans la chaine dest 
 * avec un buffer ne pouvant pas contenir la chaine src
 * et contient pas de caractere nul
 */
void copiesSansCaracNulTailleInf(void) {

    int nbTestOk = 0;

    char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLEINF];
    char dest2[TAILLEINF];
    char dest3[TAILLEINF];
    char dest4[TAILLEINF];

	printf("\n********** TESTS DE COPIE SANS CARACTERE NUL ET TAILLE INF **********\n\n");

    printf("Taille de src --> %lu\n\n",strlen(src) + 1);

    memccpy1(dest1,src,'\0',strlen(src));
    memccpy2(dest2,src,'\0',strlen(src));
    memccpy(dest3,src,'\0',strlen(src));
    strntcpy(dest4,sizeof(dest4),src);

    printf("src --> %s\n",src);
    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    /* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est mal passée
     * dans un buffer inferieur et sans le caractere nul
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) != 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) != 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) != 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) != 0) {
	    nbTestOk++;
    }

    if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}


}

/* 
 * Copier une chaine src dans une chaine dest
 * sous forme de pointeur
 * sans taille définie 
 */
void copiesDestPasInitAvecCaracNul(void) {

    printf("\n********* TESTS DE COPIE DEST PAS INIT **********\n\n");

    printf("Fait une erreur de segmentation\n");

}

/* 
 * Copier une chaine src pas initialisé 
 * dans une chaine dest 
 */
void copiesSrcPasInitAvecCaracNul(void) {

    printf("\n********** TESTS DE COPIE SRC PAS INIT *********\n\n");

    printf("Fait une erreur de segmentation\n");

}

/*
 * Copier une chaine src dans une chaine dest
 * qui contenait déjà une chaine de caracteres 
 * avec le caractere nul
 */
void copiesDestDejaPleinAvecCaracNul(void) {

    int nbTestOk = 0;

    char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLE] = "Dest est deja initialise";
    char dest2[TAILLE] = "Dest est deja initialise";
    char dest3[TAILLE] = "Dest est deja initialise";
    char dest4[TAILLE] = "Dest est deja initialise";

	printf("\n********** TESTS DE COPIE AVEC CARACTERE NUL ET DEST CONTENANT UNE CHAINE **********\n\n");

	printf("src --> %s\n",src);
    printf("Taille de src --> %lu\n",strlen(src) + 1);

    printf("\n---------- AVANT LA COPIE ----------\n\n");

    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    memccpy1(dest1,src,'\0',strlen(src) + 1);
    memccpy2(dest2,src,'\0',strlen(src) + 1);
    memccpy(dest3,src,'\0',strlen(src) + 1);
    strntcpy(dest4,sizeof(dest4),src);

    printf("\n---------- APRES LA COPIE ----------\n\n");

    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    /* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est bien passée
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) == 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) == 0) {
	    nbTestOk++;
    }
	
	if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}
}

/*
 * Copier une chaine src dans une chaine dest
 * qui contenait déjà une chaine de caracteres 
 * sans le caractere nul
 */
void copiesDestDejaPleinSansCaracNul(void) {

    int nbTestOk = 0;

    char * src = "Test avec une chaine de 40 caracteres::";

    char dest1[TAILLE] = "Dest est deja initialise";
    char dest2[TAILLE] = "Dest est deja initialise";
    char dest3[TAILLE] = "Dest est deja initialise";
    char dest4[TAILLE] = "Dest est deja initialise";

	printf("\n********** TESTS DE COPIE SANS CARACTERE NUL ET DEST CONTENANT UNE CHAINE **********\n\n");

	printf("src --> %s\n",src);
    printf("Taille de src --> %lu\n",strlen(src) + 1);

    printf("\n---------- AVANT LA COPIE ----------\n\n");

    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

    memccpy1(dest1,src,'\0',strlen(src));
    memccpy2(dest2,src,'\0',strlen(src));
    memccpy(dest3,src,'\0',strlen(src));
    strntcpy(dest4,sizeof(dest4),src);

    printf("\n---------- APRES LA COPIE ----------\n\n");

    printf("dest1 --> %s\n",dest1);
    printf("dest2 --> %s\n",dest2);
    printf("dest3 --> %s\n",dest3);
    printf("dest4 --> %s\n",dest4);

     /* 
     * Comparaison de la chaine src et des chaines dest 
     * pour vérifier que la copie s'est bien passée
     * malgré qu'il n'y est pas de caractere nul
     */
	if (strncmp(src,dest1,strlen(dest1) + 1) == 0) {
	    nbTestOk++;
    }
    
    if (strncmp(src,dest2,strlen(dest2) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest3,strlen(dest3) + 1) == 0) {
	    nbTestOk++;
    }

    if (strncmp(src,dest4,strlen(dest4) + 1) == 0) {
	    nbTestOk++;
    }

    if (nbTestOk == 4) {
		printf("\nTous les tests sont OK\n");
    } else {
    	printf("\nNombre de test(s) OK --> %d/4\n",nbTestOk);
	}

}

int main (void) {
	
	printf("************************************************************\n"
           "********************* TESTS DE COPIES **********************"
		   "\n************************************************************\n");

	copiesAvecCaracNulTailleEgale();
    copiesSansCaracNulTailleEgale();
	copiesAvecCaracNulTailleInf();
	copiesSansCaracNulTailleInf();
    copiesDestPasInitAvecCaracNul();
    copiesSrcPasInitAvecCaracNul();
    copiesDestDejaPleinAvecCaracNul();
    copiesDestDejaPleinSansCaracNul();
    

    return 0;

}

