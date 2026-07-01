#include "lexer.h"
#include <stdlib.h>

void scanfile(LexerData *data)
{
    Token token;

    do 
    {
        scan(data, &token);
        char* str = tokenToStr(&token);
        printf("%s\n", str);
        free(str);
    } while (token.token != T_EOF);
}