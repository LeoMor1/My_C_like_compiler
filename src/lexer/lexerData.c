#include "lexerData.h"


void initLexerData(LexerData *newData, char *filename)
{

    newData->column = 1;
    newData->line = 0;
    newData->putback = '\n';

    newData->infile = fopen(filename, "r");

    if (newData->infile == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void deleteLexerData(LexerData *data)
{
    data->column = 1;
    data->line = 0;
    data->putback = '\n';
    fclose(data->infile);
    data->infile = NULL;
}