#ifndef SCAN_H
#define SCAN_H

#include <ctype.h>
#include "token.h"
#include "lexerData.h"
#include "utils.h"

/** 
 * Scans the input and returns the next token.
 * @param data The lexer data.
 * @param token The tokenType to populate.
 * @return 1 if a token was found, 0 otherwise.
 */
int scan(LexerData *data, Token *token);

#endif