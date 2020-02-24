#include <stdio.h>
#include <string.h>

#define BUFSIZE 10
#define SIZEDESTECLATEE 5

void * memccpy(void * dst, const void *  src, int c, size_t n) {

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

    char src[BUFSIZE];
    char dest[BUFSIZE];
    char destEclatee[SIZEDESTECLATEE];

    printf("Situtation normale > ");
    fgets(src,BUFSIZE,stdin);

    memccpy(dest,src,'\0',strlen(src) + 1);

    printf("Taille de base %d, src --> %s, taille de src : %lu\n",BUFSIZE,src,strlen(src));
    printf("Taille de base : %d, dest --> %s, taille de dest : %lu\n",BUFSIZE,dest,strlen(dest));
  
    memccpy(destEclatee,dest,'\0',strlen(dest) + 1);
   
    printf("Taille de base : %d, destEclatee --> %s, taille de destEclatee %lu\n",SIZEDESTECLATEE,destEclatee,strlen(destEclatee));

    return 0;
}
