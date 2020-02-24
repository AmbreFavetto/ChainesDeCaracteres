#include <stdio.h>
#include <string.h>

int main (void) {

    char cc[3] = "aze";   // chaîne mal formée
    char yy[5] = "salut"; // chaine bien formée
    char dd[6] = "bugbug";
    char resultat[25];

    /* Taille de cc = 20 buffer overflow */
    printf("Taille de cc : %ld\n",strlen(cc)); 
    
    /* Taille de yy = 17 buffer overflow */
    printf("Taille de yy : %ld\n",strlen(yy));
    
    /* copie de cc la chaine mal formée */
    strncpy(yy,cc,3);
    
    printf("chaine cc : %s\n", cc);
    printf("chaine yy : %s\n", yy);
    
    strncpy(resultat,cc,14);
    printf("Chaine resultat : %s\n",resultat);
    printf("Taille de resultat : %ld\n",strlen(resultat));
    return 0;

}
