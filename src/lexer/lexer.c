#include "lexer.h"

void scanfile(LexerData *data)
{
    Token token;

    do 
    {
        scan(data, &token);
        printf("%s\n", tokenToStr(&token));
    } while (token.token != T_EOF);
}