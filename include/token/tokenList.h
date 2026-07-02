#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "token.h"

typedef struct TokenList
{
    Token* items;
    size_t count;
    size_t capacity;
}TokenList;

/**
 * @brief Initializes a TokenList structure.
 * @param list Pointer to the TokenList structure to initialize.
 * @note This function allocates memory for the items array and sets the initial capacity and count.
 *       If memory allocation fails, the program will print an error message and exit.
 */
void initTokenList(TokenList *list);

/**
 * @brief Deletes a TokenList structure.
 * @param list Pointer to the TokenList structure to delete.
 * @note This function frees the memory allocated for the items array and resets the count and capacity to zero.
 */
void deleteTokenList(TokenList *list);

/**
 * @brief Appends a token to the TokenList.
 * @param list Pointer to the TokenList structure.
 * @param token The token to append.
 */
void appendToken(TokenList *list, Token token);

/**
 * @brief Retrieves a token from the TokenList.
 * @param list Pointer to the TokenList structure.
 * @param index The index of the token to retrieve.
 * @return A pointer to the requested token, or NULL if the index is out of bounds.
 */
Token* getToken(TokenList *list, size_t index);

/**
 * @brief Gets the number of tokens in the TokenList.
 * @param list Pointer to the TokenList structure.
 * @return The number of tokens in the list.
 */
size_t getTokenListCount(TokenList *list);

char* tokenListToStr(TokenList *list);
void printTokenList(TokenList *list);

#endif 