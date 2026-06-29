#ifndef TOKEN_H
#define TOKEN_H

struct Token {
    int token;
    int intValue;
};

enum {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT
};

#endif