#include "token.h"

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

char* tokenToStr(Token *token) {
    char *tokenStr = NULL;
    const char *typeStr = tokenTypeToStr(token->tokenType);

    if (token->tokenType == T_INTLIT) {
        if (asprintf(&tokenStr, "Token Type: %s, Value: %d", typeStr, token->intValue) < 0) {
            return NULL;
        }
    } else {
        if (asprintf(&tokenStr, "Token Type: %s", typeStr) < 0) {
            return NULL;
        }
    }

    return tokenStr;
}
