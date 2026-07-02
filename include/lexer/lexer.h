#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include "lexerData.h"
#include "token.h"
#include "tokenList.h"
#include "scan.h"

/** 
 * Scans a file and populates the lexer data.
 * @param data The lexer data to populate.
 * @return A pointer to the populated TokenList.
 */
void scanfile(LexerData *data, TokenList *tokenList);

#endif