#include "lexer.h"

void scanfile(LexerData *data, TokenList *tokenList)
{
    if(tokenList == NULL)
    {
        fprintf(stderr, "TokenList pointer is NULL in scanfile\n");
        exit(EXIT_FAILURE);
    }

    Token token;

    do 
    {
        scan(data, &token);
        appendTokenInList(tokenList, token);
    } while (token.tokenType != T_EOF);
}
