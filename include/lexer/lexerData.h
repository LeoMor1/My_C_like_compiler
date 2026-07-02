#ifndef LEXERDATA_H
#define LEXERDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * @brief Structure to hold lexer data.
 */
typedef struct LexerData {
    /**
     * @brief The current line number in the input file.
     */
    int line; 
    /**
     * @brief The current column number in the input file.
     */
    int column;
    /**
     * @brief A character to be put back into the input stream.
     */
    char putback;
    /**
     * @brief A pointer to the input file.
     */
    FILE *infile;
} LexerData;

/** 
 * Initializes the lexer data.
 * @param newData The lexer data to initialize.
 * @param filename The name of the file to open.
 */
void initLexerData(LexerData *newData, char *filename);

/** 
 * Deletes the lexer data.
 * @param data The lexer data to delete.
 */
void deleteLexerData(LexerData *data);

#endif