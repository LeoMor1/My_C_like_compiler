#include "utils.h"

int chrpos(char *s, char c)
{
    char *p;
    p = strchr(s, c);
    return (p ? p - s : -1);
}