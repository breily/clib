/*
 *  bmem.c - memory management functions for blib
 */

#include "../memory/bmem.h"

#include <stdlib.h>
#include <stdio.h>

void *bmalloc(size_t n) {
    void *p = NULL;
    if ((p = malloc(n)) == NULL)
        fprintf(stderr, "# error: bmalloc out of space\n");
    return p;
}

void *bcalloc(size_t n, size_t size) {
    void *p = NULL;
    if ((p = calloc(n, size)) == NULL)
        fprintf(stderr, "# error: bcalloc out of space\n");
    return p;
}

void *brealloc(void *v, size_t size) {
    void *p = NULL;
    if ((p = realloc(v, size)) == NULL)
        fprintf(stderr, "# error: brealloc out of space\n");
    return p;
}
