#include "parserData.h"

void initParserData(ParserData *data, TokenList *list)
{
    data->tokenList = list;
    data->current_pos = 0;
}

void deleteParserData(ParserData *data)
{
    // We don't own the token list, so we don't free it here.
    data->tokenList = NULL;
    data->current_pos = 0;
}


