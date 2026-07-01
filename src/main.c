#include "lexer/lexer.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

/** 
 * Initializes the lexer data.
 * @param newData The lexer data to initialize.
 */
static void init(LexerData *newData)
{

    newData->column = 1;
    newData->line = 0;
    newData->putback = '\n';
    newData->infile = NULL;
}

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

    init(&data);
    
    if ((data.infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        return 1;
    }
    
    scanfile(&data);
    return 0;
}
