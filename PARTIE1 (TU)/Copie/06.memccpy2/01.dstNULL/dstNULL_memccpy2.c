/*
 * Test du cas où dst est à NULL
 *
 */

#include <string.h>
#include <stdio.h>

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

    char * dst = NULL;

    char * ret;

    ret = memccpy2(dst,"12345",'\0',6);
    ret-=2;

    printf("memccpy2 -- cas : dest (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : "); 
    printf("%c\n",*ret); 
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : "); 
    printf("%s\n",dst);

    return 0;
}
