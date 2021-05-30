#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 20

void ec (char * s) {
    char * q;

    if ((q = strrchr(s,'\0')) != NULL) {
        *q = ' ';
    }
}

int main (void) {

    char src[BUFSIZE];
    char dest[BUFSIZE];

    printf("> ");
    fgets(src,BUFSIZE,stdin);
    printf("src -> %s\n",src);

    ec(src);
    memccpy(dest,src,'\0',strlen(src));

    printf("dest -> %s\n",dest);

    return 0;
}
