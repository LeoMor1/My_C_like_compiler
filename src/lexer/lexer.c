#include "lexer.h"
#include "token.h"
#include "scan.h"

void scanfile(LexerData *data)
{
    Token token;

    do 
    {
        scan(data, &token);
        printfToken(&token);
    } while (token.token != T_EOF);
}