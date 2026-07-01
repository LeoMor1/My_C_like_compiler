#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

typedef enum TokenType {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT,
    T_EOF,
    T_UNDEFINED
} TokenType;

typedef struct Token {
    TokenType token;
    int intValue;
} Token;

/** 
 * Converts a token type to a string.
 * @param type The token type to convert.
 * @return A string representing the token type.
 */
char* tokenTypeToStr(TokenType type);

/** 
 * Prints the details of a token.
 * @param token The token to print.
 */
void printfToken(Token *token);

#endif