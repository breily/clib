#ifndef BLIB_HASH_H
#define BLIB_HASH_H

typedef struct bhash_node bhash_node;
struct bhash_node {
    bhash_node *next;
    void *key;
    void *value;
};

typedef struct bhash bhash;
struct bhash {
    bhash_node **table;
    int size;

    int table_size;
    int auto_resize;
    float resize_threshold;
    enum {
        CHAR_PTR,
        BSTR_PTR,
        VOID_PTR 
    } hash_type;

    int (*bhash_hash_func)(bhash *, void *);
    int (*bhash_cmp_func)(void *, void *);
};

int __bhash_hash_function(bhash *, void *);
int __bhash_cmp_function(void *, void *);
int __bhash_resize(bhash *b);

bhash *bhash_init();
void *bhash_lookup(bhash *, void *);
int bhash_insert(bhash *, void *, void *);
void *bhash_remove(bhash *, void *);

#endif
