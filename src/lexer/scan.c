#include "lexer/scan.h"
#include "lexer/data.h"
#include "lexer/token.h"
#include "lexer/utils.h"

static int next(void) 
{
    int c;

    Column++;
    if (Putback) 
    {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if(c =='\n') 
    {
        Column = 1;
        Line++;
    }
    return c;
}

static void putback(int c) 
{
    Putback = c;
}

static int skip(void)
{
    int c;

    c = next();
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')
    {
        c = next();
    }
    return c;
}

static int scanint(int c)
{
    int k, val=0;

    k = chrpos("0123456789", c);
    while (k >= 0)
    {
        val = val * 10 + k;
        c = next();
        k = chrpos("0123456789", c);
    }

    putback(c);
    return val;
}

int scan(struct Token *t)
{
    int c;

    c = skip();

    switch (c)
    {
    case EOF:
        return (0);
    
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
            t->intValue = scanint(c);
            break;
        }
        printf("Unreconized charactere %c on line %d and char %d", c, Line, Column);
        return 1;
    }

    return 1;
}