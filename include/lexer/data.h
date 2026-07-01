#ifndef DATA_H
#define DATA_H

# include <stdio.h>

typedef struct LexerData {
    int line;
    int column;
    char putback;
    FILE *infile;
} LexerData;



#endif