#ifndef MALLOC_MOCK_H
#define MALLOC_MOCK_H

#include <stdbool.h>

void set_malloc_should_fail(bool value);
void set_realloc_should_fail(bool value);

#endif