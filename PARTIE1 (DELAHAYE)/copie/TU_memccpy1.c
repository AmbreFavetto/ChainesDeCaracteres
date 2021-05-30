#include <string.h>
#include <stdio.h>

#define TAILLE 6

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

struct test {
    /* numero du test */
    int n;

    struct {
        char const * dest;
        char const * source;
    } in;
   
    struct {
        char const * s;
    } out;

    char const * ret;
};

int main (void) {

    char s_out[5];

    char * p_out;
 
    /* liste des tests */
    struct test a[TAILLE] = {
        /* 
		 * utiliser option -fno-stack-protector pour pas détecter stack smashing 
		 * mais cette option n'est pas obligatoire avec la copie car certaines méthodes
		 * ne détecte pas les buffer overflow
         */

        /* SRC INIT  && DEST INIT && SRC LEN > DEST LEN */
		{1, { "" , "UN TEST" } , { "UN TEST" }, s_out}, 
		/* SRC INIT  && DEST INIT && SRC LEN = DEST LEN */
		{2, { "" , "TEST" } , { "TEST" }, s_out},
		/* SRC INIT && DEST INIT && SRC LEN < DEST LEN */
		{3, { "" , "T" } , { "T" }, s_out},

		/* SRC INIT  && DEST INIT && DEST LEN > BUFFER */
		{4, { "UN TEST" , "" } , { "" }, s_out}, 
		/* SRC INIT  && DEST INIT && DEST LEN > BUFFER && SRC LEN < BUFFER */
		{5, { "UN TEST" , "TEST" } , { "TEST" }, s_out},
		/* SRC INIT && DEST INIT && SRC LEN < DEST LEN */
		{6, { "TEST" , "TEST" } , { "TEST" }, s_out},
    };

    int err = 0;
    size_t i;

    for (i = 0; i < TAILLE; i++) {
        
        struct test * p = a + i;
      
        p_out = memccpy1(s_out, p->in.source, '\0', strlen(p->in.source) + 1);

        /* verifications */
        if (p_out != p->ret) {
            printf ("error at test # %d (wrong returned address)\n", p->n);
            err = 1;
        }

        if (strcmp(s_out, p->out.s) != 0) {
            printf("error at test # %d (wrong destination string) : %s\n", p->n,s_out);
            err = 1;
        }
    }

    /* validation finale */
    if (!err) {
        puts ("P A S S E D");
    }

    return 0;
}


