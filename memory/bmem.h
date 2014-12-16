#ifndef BLIB_MEM_H
#define BLIB_MEM_H

#include <stdlib.h>

void *bmalloc(size_t n);
void *bcalloc(size_t n, size_t size);
void *brealloc(void *v, size_t size);

#endif
