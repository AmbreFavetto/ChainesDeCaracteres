#include <stdio.h>
#include <string.h>

int main(void) {

    char * s = "guitares";
    char v[10];
    char * m;

    m = memccpy(v,s,'\0',strlen(s) + 1);
    printf("%c\n",*m);

    *m = v[strlen(v) - 1];

    printf("%c\n",*m);

    return 0;
}
