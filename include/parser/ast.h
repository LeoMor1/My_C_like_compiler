#ifndef AST_H
#define AST_H

typedef enum ASTNodeType 
{
    A_ADD,
    A_SUBSTRACT,
    A_MULTIPLY,
    A_DIVIDE,
    A_INTLIST
} ASTNodeType;

typedef struct ASTNode 
{
    ASTNodeType type;
    ASTNode *left;
    ASTNode *right;
    int value;
} ASTNode;

#endif