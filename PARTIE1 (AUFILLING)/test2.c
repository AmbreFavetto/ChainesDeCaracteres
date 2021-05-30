#include <stdio.h>
#include <string.h>

int main (void) {

    char cc[3] = "aze";   // chaîne mal formée
    char yy[6] = "salut"; // chaine bien formée
    
    /* Taille de cc = 8 buffer overflow */
    printf("Taille de cc : %ld\n",strlen(cc)); 
    
    /* Taille de yy = 5 */
    printf("Taille de yy : %ld\n",strlen(yy));
    
    /* copie de cc la chaine mal formée */
    strncpy(yy,cc,3);
    
    printf("chaine cc : %s\n", cc);
    printf("chaine yy : %s\n", yy);
     
    return 0;

}
