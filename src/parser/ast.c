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

static ASTNode *primary(ParserData *data)
{
    
}
