#include "interpreter.h"
#include "ast.h"

int interpretAst(ASTNode *node)
{
    int leftval, rightval;
    if(node->left)
        leftval = interpretAst(node->left);
    if(node->right)
        rightval = interpretAst(node->right);
    
    switch (node->type)
    {
    case A_ADD:
        return leftval + rightval;
    case A_SUBSTRACT:
        return leftval - rightval;
    case A_MULTIPLY:
        return leftval * rightval;
    case A_DIVIDE:
        return leftval / rightval;
    case A_INTLIST:
        return node->value;
    default:
      fprintf(stderr, "Unknown AST operator %d\n", node->type);
      exit(1);
    }
}