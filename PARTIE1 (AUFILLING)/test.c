#include <stdio.h>
#include <string.h>

int main (void) {

    char test[6] = "Coucou";

    fputs(test,stdout);
    printf("\n");

    test[5] = 'z';
    test[6] = 'z';

    fputs(test,stdout);
    printf("\n");

    return 0;

}
