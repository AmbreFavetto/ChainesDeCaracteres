#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

int main(void) {

    char src[BUFSIZE];
    char dest[BUFSIZE];
    char dest2[BUFSIZE];
    char * p = NULL;   
    size_t dsize;

    dsize = strlen(src);

    printf("> ");
    fgets(src,BUFSIZE,stdin);
   
    p = memccpy(dest,src,'\0',dsize); 
    
    if (p) {
        --p;
	p = memccpy(p,"/",'\0',dsize - (p - dest));
	if (p) {
            --p;
	    p = memccpy(p,dest2,'\0',dsize - (p - dest));
        }
    } else {
        dest[dsize-1] = '\0';
    }

    printf("src --> %s\n",src);
    printf("dest --> %s\n",dest);
    printf("dest2 --> %s\n",dest2);


    return 0;
}
