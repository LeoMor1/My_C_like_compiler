#ifndef SCAN_H
#define SCAN_H
#include "token.h"
#include "data.h"
#include <ctype.h>

/** 
 * Scans the input and returns the next token.
 * @param data The lexer data.
 * @param t The token to populate.
 * @return 1 if a token was found, 0 otherwise.
 */
int scan(LexerData *data, Token *t);

#endif