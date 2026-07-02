#include <stdlib.h>
#include <stdbool.h>

static bool malloc_should_fail = false;
static bool realloc_should_fail = false;

void set_malloc_should_fail(bool value) { malloc_should_fail = value; }
void set_realloc_should_fail(bool value) { realloc_should_fail = value; }

extern void *__real_malloc(size_t size);
extern void *__real_realloc(void *ptr, size_t size);

void *__wrap_malloc(size_t size)
{
    if (malloc_should_fail) {
        malloc_should_fail = false;
        return NULL;
    }
    return __real_malloc(size);
}

void *__wrap_realloc(void *ptr, size_t size)
{
    if (realloc_should_fail) {
        realloc_should_fail = false;
        return NULL;
    }
    return __real_realloc(ptr, size);
}