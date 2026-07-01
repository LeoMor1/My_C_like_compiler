#include "utils.h"

int chrpos(char *s, int c)
{
    char *p;
    p = strchr(s, c);
    return (p ? p - s : -1);
}