#include <stdio.h>
#include <string.h>

#define BUFSIZE 10
#define BUFPASBON 5

void * memccpy(void * dst, const void * src,int c, size_t n) {

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

    char src[BUFSIZE];
    char dest[BUFSIZE];
    char destEclatee[BUFPASBON];
    
    /* Test en situtation normale */
    printf("Situation normale > ");
    fgets(src,BUFSIZE,stdin);

    memccpy(dest,src,'\0',strlen(src) + 1);

    printf("src --> %s\n",src);
    printf("dest --> %s\n",dest);

    /* Buffer overflow test */
    memccpy(destEclatee,dest,'\0',strlen(dest) +1);

    printf("Talle de base : %d, destEclatee --> %s, taille : %lu\n",BUFPASBON,destEclatee,strlen(destEclatee));
    return 0;

}
