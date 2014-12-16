#ifndef BLIB_TRIE_H
#define BLIB_TRIE_H

typedef struct btrie_child btrie_child;
typedef struct btrie btrie;

struct btrie_child {
    char code;
    btrie *node;
};

struct btrie_node {
    void *value;
    btrie_child **children;
};

btrie *btrie_init();
void *btrie_lookup(btrie *, char *);
void btrie_insert(btrie *, char *, void *);

#endif
