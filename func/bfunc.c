/*
 * bfunc.c - trying to add functional programming to c
 */

#include "../func/bfunc.h"
#include "../lists/blistd.h"

blistd *map(void *(*func)(void *), blistd *vals) {
    blistd *news = blistd_init();
    blistd_node *cursor = vals->first;
    while (cursor) {
        blistd_append(news, func(cursor));
        cursor = cursor->next;
    }
    return news;
}

blistd *filter(void *(*func)(void *), blistd *vals) {
    blistd *news = blistd_init();
    blistd_node *cursor = vals->first;
    while (cursor) {
        if (func(cursor->value)) blistd_append(news, cursor->value);
        cursor = cursor->next;
    }
    return news;
}
