#include "lexer/lexer.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

/** 
 * Prints the usage message for the program.
 * @param prog The name of the program.
 */
static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s infile\n", prog);
}

int main(int argc, char **argv){
    if (argc != 2)
    {
        usage(argv[0]);
        return 0;
    }

    LexerData data;

    initLexerData(&data, argv[1]);
    
    scanfile(&data);

    deleteLexerData(&data);
    return 0;
}
