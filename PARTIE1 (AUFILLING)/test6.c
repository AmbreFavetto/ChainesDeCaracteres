#include <stdio.h>
#include <string.h>

#define TAILLE 13
#define TEST 4

int main (void) {

    char * s1 = "COUCOU";
    char s2[TAILLE];
    char d[TAILLE];
    char test[TEST];
    
    test[0] = 'H';
    test[1] = 'E';
    test[2] = 'L';
    test[3] = 'L';
    test[4] = 'O';
    
   
    strncpy(d,s1,6); /* d = COUCOU */
    strncpy(s2,d,6); /* s2 = COUCOU */
    strncat(d,s2,6); /* d = COUCOUCOUCOU */
    /* Plantage complet */
    strncat(d,test,10);

    printf("s1 : %s\n",s1);
    printf("s2 : %s\n",s2);
    printf("d : %s\n",d);
    printf("test : %s\n",test);

    printf("Taille de d : %lu\n",strlen(d)); 
    printf("Taille de test : %lu\n",strlen(test)); 
    
    return 0;

}
