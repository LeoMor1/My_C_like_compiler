#ifndef PARSERDATA_H
#define PARSERDATA_H

#include "token.h"
#include "tokenList.h"

typedef struct ParserData {
    TokenList *tokenList;
    int current_pos;
} ParserData;

void initParserData(ParserData *data, TokenList *list);

void deleteParserData(ParserData *data);

#endif