#include "token.h"
#include <stdlib.h>
#include <string.h>

char* tokenTypeToStr(TokenType type)
{
    switch (type)
    {
        case T_PLUS:
            return "+";
            
        case T_MINUS:
            return "-";
            
        case T_SLASH:
            return "/";

        case T_STAR:
            return "*";
            
        case T_INTLIT:
            return "intlist";

        case T_EOF:
            return "EOF";
            
        default:
            return "UNKMOWN";
    }
}

char* tokenToStr(Token *token)
{
    char *tokenStr = malloc(50 * sizeof(char));
    if (tokenStr == NULL) {
        return NULL; // Handle memory allocation failure
    }

    snprintf(tokenStr, 50, "Token Type: %s", tokenTypeToStr(token->token));
    if (token->token == T_INTLIT) {
        snprintf(tokenStr + strlen(tokenStr), 50 - strlen(tokenStr), ", Value: %d", token->intValue);
    }
    return tokenStr;
}
