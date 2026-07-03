#include "parser.h"

int eval(TokenList *list)
{
    ParserData data;
    initParserData(&data, list);

    ASTNode *tree;
    tree = binexpr(&data);

    int result;
    result = interpretAst(tree);

    deleteParserData(&data);
    return result;
}