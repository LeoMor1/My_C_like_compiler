#include "ast.h"

ASTNode* mkAstNode(
    ASTNodeType type, 
    ASTNode *left, 
    ASTNode *right, 
    int value
) {
    ASTNode *newNode;
    newNode = malloc(sizeof(ASTNode));
    if(newNode == NULL) 
    {
        fprintf(stderr, "Unable to malloc in mkAstNode()\n");
        exit(1);
    }

    newNode->type = type;
    newNode->left = left;
    newNode->right = right;
    newNode->value = value;
    return newNode;
}

ASTNode* mkAstLeaf(ASTNodeType type, int value)
{
    return mkAstNode(type, NULL, NULL, value);
}

ASTNode* mkAstUnary(ASTNodeType type, ASTNode* childNode, int value)
{
    return mkAstNode(type, childNode, NULL, value);
}

ASTNodeType arithOp(Token *token)
{
    switch (token->tokenType)
    {
    case T_PLUS:
        return A_ADD;
    case T_MINUS:
        return A_SUBSTRACT;
    case T_STAR:
        return A_MULTIPLY;
    case T_SLASH:
        return A_DIVIDE;
    default:
        fprintf(stderr, "Unknown token in arithop() on line %d and column %d", token->line, token->column);
        exit(EXIT_FAILURE);
    }
}

static ASTNode* primary(Token *token)
{
    ASTNode *newNode;

    switch (token->tokenType)
    {
    case T_INTLIT:
        newNode = mkAstLeaf(A_INTLIST, token->intValue);
        return newNode;
    
    default:
      fprintf(stderr, "syntax error on line %d and column %d\n", token->line, token->column);
      exit(1);
    }
};

ASTNode *binexpr(ParserData *data)
{
    ASTNode *newNode, *left, *right;
    ASTNodeType nodeType;
    Token *token = getAndAdvanceTokenInList(data->tokenList);

    left = primary(token);

    token = getAndAdvanceTokenInList(data->tokenList);

    if(token->tokenType == T_EOF)
        return left;
    
    nodeType = arithOp(token);

    right = binexpr(data);

    newNode = mkAstNode(nodeType, left, right, 0);

    return newNode;
}
