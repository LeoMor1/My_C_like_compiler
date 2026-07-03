#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum TokenType {
    /**
     * @brief Token representing the '+' operator.
     */
    T_PLUS,
    /**
     * @brief Token representing the '-' operator.
     */
    T_MINUS,
    /**
     * @brief Token representing the '*' operator.
     */
    T_STAR,
    /**
     * @brief Token representing the '/' operator.
     */
    T_SLASH,
    /**
     * @brief Token representing an integer literal.
     */
    T_INTLIT,
    /**
     * @brief Token representing the end of file.
     */
    T_EOF,
    /**
     * @brief Token representing an undefined or unrecognized token.
     */
    T_UNDEFINED
} TokenType;

/**
 * @brief Structure to hold a token and its associated integer value.
 */
typedef struct Token {
    /**
     * @brief The type of the token.
     */
    TokenType tokenType;
    /**
     * @brief The integer value associated with the token.
     */
    int intValue;

    /**
     * @brief The line number where the token is located.
     */
    int line;

    /**
     * @brief The column number where the token is located.
     */
    int column;
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
char* tokenToStr(Token *token);

#endif