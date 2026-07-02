#include "tokenList.h"

#define TOKENLIST_INITIAL_CAPACITY 16

void initTokenList(TokenList *list)
{
    list->items = malloc(sizeof(Token) * TOKENLIST_INITIAL_CAPACITY);
    if(list->items == NULL)
    {
        fprintf(stderr, "Failed to allocate TokenList\n");
        exit(EXIT_FAILURE);
    }
    list->capacity = TOKENLIST_INITIAL_CAPACITY;
    list->count = 0;
}

void deleteTokenList(TokenList *list)
{
    free(list->items);
    list->items = NULL;
    list->count = 0;
    list->capacity = 0;
}

void static growTokenList(TokenList *list)
{
    size_t newCapacity = list->capacity * 2;
    Token *newItems = realloc(list->items, sizeof(Token) * newCapacity);
    if(newItems == NULL)
    {
        fprintf(stderr, "Failed to reallocate TokenList\n");
        exit(EXIT_FAILURE);
    }
    list->items = newItems;
    list->capacity = newCapacity;
}

void appendToken(TokenList *list, Token token)
{
    if(list->count >= list->capacity)
    {
        growTokenList(list);
    }
    list->items[list->count] = token;
    list->count++;
}

Token* getToken(TokenList *list, size_t index)
{
    if(index >= list->count)
    {
        fprintf(stderr, "Index out of bounds in getToken\n");
        exit(EXIT_FAILURE);
    }
    return &list->items[index];
}

size_t getTokenListCount(TokenList *list)
{
    return list->count;
}

char* tokenListToStr(TokenList *list)
{
    size_t bufferSize = TOKENLIST_INITIAL_CAPACITY; // Initial buffer size
    char *buffer = malloc(bufferSize);
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for token list string\n");
        exit(EXIT_FAILURE);
    }
    buffer[0] = '['; // Start of the list representation
    buffer[1] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < list->count; i++) {
        char *tokenStr = tokenTypeToStr(getToken(list, i)->tokenType);
        if (tokenStr == NULL) {
            free(buffer);
            fprintf(stderr, "Failed to convert token to string\n");
            exit(EXIT_FAILURE);
        }

        // Check if we need to resize the buffer
        size_t requiredSize = strlen(buffer) + strlen(tokenStr) + 2;
        if (requiredSize > bufferSize) {
            bufferSize *= 2;
            char *newBuffer = realloc(buffer, bufferSize);
            if (newBuffer == NULL) {
                free(buffer);
                fprintf(stderr, "Failed to reallocate memory for token list string\n");
                exit(EXIT_FAILURE);
            }
            buffer = newBuffer;
        }

        strcat(buffer, tokenStr);
        strcat(buffer, (i < list->count - 1) ? ", " : ""); // Add comma for all but the last token
    }
    strcat(buffer, "]"); // Close the list representation after the last token

    return buffer;
}

void printTokenList(TokenList *list) {
    char *listStr = tokenListToStr(list);
    if (listStr == NULL) {
        fprintf(stderr, "Failed to convert token list to string\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", listStr);
    free(listStr);
}