#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <stdio.h>
#include "parserData.h"

typedef enum ASTNodeType 
{
    /**
     * @brief AST node representing an addition operation.
     */
    A_ADD,
    /**
     * @brief AST node representing a subtraction operation.
     */
    A_SUBSTRACT,
    /**
     * @brief AST node representing a multiplication operation.
     */
    A_MULTIPLY,
    /**
     * @brief AST node representing a division operation.
     */
    A_DIVIDE,
    /**
     * @brief AST node representing a list of integers.
     */
    A_INTLIST
} ASTNodeType;

/**
 * @brief Structure to hold an AST node.
 */
typedef struct ASTNode 
{
    /**
     * @brief The type of the AST node.
     */
    ASTNodeType type;
    /**
     * @brief Pointer to the left child node.
     */
    struct ASTNode *left;
    /**
     * @brief Pointer to the right child node.
     */
    struct ASTNode *right;
    /**
     * @brief The integer value associated with the node.
     */
    int value;
} ASTNode;

/**
 * @brief Creates a new AST node with the given type, left and right children, and value.
 *
 * @param type The type of the AST node.
 * @param left Pointer to the left child node (can be NULL).
 * @param right Pointer to the right child node (can be NULL).
 * @param value The integer value associated with the node (used for leaf nodes).
 * @return Pointer to the newly created ASTNode.
 */
ASTNode* mkAstNode(ASTNodeType type, ASTNode *left, ASTNode *right, int value);

/**
 * @brief Creates a new AST unary node with the given type, child node, and value.
 *
 * @param type The type of the AST node.
 * @param childNode Pointer to the child node (can be NULL).
 * @param value The integer value associated with the node (used for leaf nodes).
 * @return Pointer to the newly created ASTNode.
 */
ASTNode* mkAstUnary(ASTNodeType type, ASTNode* childNode, int value);

/**
 * @brief Creates a new AST leaf node with the given type and value.
 *
 * @param type The type of the AST node.
 * @param value The integer value associated with the leaf node.
 * @return Pointer to the newly created ASTNode.
 */
ASTNode* mkAstLeaf(ASTNodeType type, int value);

ASTNode *binexpr(ParserData *data);

#endif