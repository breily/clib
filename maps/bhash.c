/*
 *  bhash.c - hash table implementation for blib
 */

#include "../maps/bhash.h"
#include "../strings/bstring.h"
#include "../memory/bmem.h"

#define DEBUG 1
#ifdef DEBUG
#include <stdio.h>
#endif

bhash *bhash_init() {
    bhash *b = (bhash *) bmalloc(sizeof(bhash));
    if (!b) return (bhash *) NULL;

    b->table_size = 1009;
    b->table = (bhash_node **) bcalloc(b->table_size, sizeof(bhash_node *));
    b->size = 0;

    b->auto_resize = 1;
    b->resize_threshold = 0.75;
    b->hash_type = VOID_PTR;

    b->bhash_hash_func = __bhash_hash_function;
    b->bhash_cmp_func = __bhash_cmp_function;

    return b;
}

void *bhash_lookup(bhash *b, void *k) {
    int hash = b->bhash_hash_func(b, k);
    return (void *) NULL;
}

int bhash_insert(bhash *b, void *k, void *v) {
    int hash = b->bhash_hash_func(b, k);
    bhash_node *cursor = b->table[hash];
    while (cursor) {
        cursor = cursor->next;
    }


    b->size++;
    if ((b->size / b->table_size) > b->resize_threshold) __bhash_resize(b);
    return b->size;
}

void *bhash_remove(bhash *b, void *k) {
    int hash = b->bhash_hash_func(b, k);
    return (void *) NULL;
}

int __bhash_resize(bhash *b) {
#ifdef DEBUG
    printf("** bhash: resize called\n");
#endif
    return 0;
}

int __bhash_hash_function(bhash *b, void *k) {
    /* Hash functions borrowed from github.com/galdor/mf/dict.c */
    int hash = 5381;
    if (b->hash_type == CHAR_PTR) {
        char *tmp = (char *) k;
        while (*tmp) hash = (hash << 5) + hash + *tmp++;
    } else if (b->hash_type == BSTR_PTR) {
        char *tmp = ((bstring *) k)->string;
        while (*tmp) hash = (hash << 5) + hash + *tmp++;
    } else if (b->hash_type == VOID_PTR) {
        char *tmp = (char *) k;
        int i = 0;
        for (; i < sizeof(void *); i++) hash = (hash << 5) + hash + *tmp++;
    }
    return hash % b->table_size;
}

int __bhash_cmp_function(void *a, void *b) {

}
