#ifndef LEXER_H
#define LEXER_H

#include "data.h"
#include "token.h"
#include "scan.h"

/** 
 * Scans a file and populates the lexer data.
 * @param data The lexer data to populate.
 */
void scanfile(LexerData *data);

#endif