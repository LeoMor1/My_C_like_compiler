#ifndef UTILS_H
#define UTILS_H

#include <string.h>

/** 
 * Returns the position of the first occurrence of character c in string s.
 * @param s The string to search.
 * @param c The character to find.
 * @return The index of the first occurrence of c in s, or -1 if not found.
 */
int chrpos(char *s, int c);

#endif