#include "btrie.h"
#include "../memory/bmem.h"

btrie *btrie_init() {
    btrie *b = (btrie *) bmalloc(sizeof(btrie));
    return b;
}

void btrie_insert(btrie *b, char *k, void *v) {
    
}

void *btrie_lookup(btrie *b, char *k) {

}
