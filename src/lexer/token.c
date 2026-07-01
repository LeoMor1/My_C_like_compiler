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

void printfToken(Token *token) 
{
    printf("Token %s", tokenTypeToStr(token->token));
    if (token->token == T_INTLIT)
        printf(", value %d", token->intValue);
    printf("\n");
}