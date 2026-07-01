#ifndef DATA_H
#define DATA_H

# include <stdio.h>

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



#endif