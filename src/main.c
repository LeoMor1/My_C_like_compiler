#define extern_
#include "lexer/data.h"
#undef extern_
#include "lexer/token.h"
#include "lexer/scan.h"
#include <stdio.h>
#include <errno.h>

static void init()
{
    Line = 0;
    Column = 1;
    Putback = '\n';
}

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s infile\n", prog);
} 

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

static void scanfile() 
{
    struct Token T;

    while (scan(&T))
    {
        printf("Token %s", tokstr[T.token]);
        if (T.token == T_INTLIT)
            printf(", value %d", T.intValue);
        printf("\n");
    }
}

int main(int argc, char **argv){
    if (argc != 2)
    {
        usage(argv[0]);
        return 0;
    }

    init();
    
    if ((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        return 1;
    }
    
    scanfile();
    return 0;
}
