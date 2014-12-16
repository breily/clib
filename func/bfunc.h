#ifndef BLIB_FUNCTIONAL_H
#define BLIB_FUNCTIONAL_H

#include "../lists/blistd.h"

blistd *map(void *(*)(void *), blistd *);
blistd *filter(void *(*)(void *), blistd *);

#endif
