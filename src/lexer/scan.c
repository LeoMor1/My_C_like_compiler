#include "scan.h"
#include "utils.h"

/** 
 * Returns the next character from the input stream.
 * @param data The lexer data.
 * @return The next character.
 */
static char next(LexerData *data) 
{
    char c;

    data->column++;
    if (data->putback) 
    {
        c = data->putback;
        data->putback = 0;
        return c;
    }

    c = fgetc(data->infile);
    if(c =='\n') 
    {
        data->column = 1;
        data->line++;
    }
    return c;
}

/** 
 * Puts a character back into the input stream.
 * @param data The lexer data.
 * @param c The character to put back.
 */
static void putback(LexerData *data, char c) 
{
    data->putback = c;
}

/** 
 * Skips whitespace characters from the input stream.
 * @param data The lexer data.
 * @return The first non-whitespace character.
 */
static int skip(LexerData *data)
{
    int c;

    c = next(data);
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')
    {
        c = next(data);
    }
    return c;
}

/** 
 * Scans an integer literal from the input stream.
 * @param data The lexer data.
 * @param c The first character of the integer literal.
 * @return The scanned integer value.
 */
static int scanint(LexerData *data, char c)
{
    int k, val=0;

    k = chrpos("0123456789", c);
    while (k >= 0)
    {
        val = val * 10 + k;
        c = next(data);
        k = chrpos("0123456789", c);
    }

    putback(data, c);
    return val;
}

int scan(LexerData *data, Token *t)
{
    char c;

    c = skip(data);

    switch (c)
    {
    case EOF:
        t->token = T_EOF;
        return 0;
    
    case '+':
        t->token = T_PLUS;
        break;

    case '-':
        t->token = T_MINUS;
        break;

    case '/':
        t->token = T_SLASH;
        break;

    case '*':
        t->token = T_STAR;
        break;
    
    default:
        if(isdigit(c)) {
            t->token = T_INTLIT;
            t->intValue = scanint(data, c);
            break;
        }
        printf("Unreconized charactere %c on line %d and char %d\n", c, data->line, data->column);
        t->token = T_UNDEFINED;
    }

    return 1;
}