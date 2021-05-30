/*
 * Test du cas où dst est à NULL
 *
 */

#include <string.h>
#include <stdio.h>

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

int main (void) {

    char * dst = NULL;

    char * ret;

    ret = memccpy1(dst,"12345",'\0',6);
    ret-=2;

    printf("memccpy1 -- cas : dest (NULL) -- \n");
    printf("ret (ATTENDU) : Erreur de segmentation -- ret (REEL) : "); 
    printf("%c\n",*ret); 
    printf("dst (ATTENDU) : Erreur de segmentation -- dst (REEL) : "); 
    printf("%s\n",dst);

    return 0;
}
