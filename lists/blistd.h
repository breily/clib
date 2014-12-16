#ifndef BLIB_LISTD_H
#define BLIB_LISTD_H

/*
 * Holds a doubly linked list item.
 * You shouldn't have to create them yourself.
 */
typedef struct blistd_node {
    struct blistd_node *next;
    struct blistd_node *prev;
    void *value;
} blistd_node;

/*
 * Holds a doubly linked list.
 */
typedef struct blistd {
    struct blistd_node *first;
    struct blistd_node *last;
    int length;
} blistd;

/* 
 * Initialize an empty list.
 * Return NULL if bmalloc fails.
 */
blistd *blistd_init();

/* 
 * Initialize a list from an existing array.
 * Return NULL if bmalloc fails.
 */
blistd *blistd_einit(void **, int);

/* 
 * Initialize a list node.
 * Return NULL if bmalloc fails.
 */
blistd_node *blistd_node_init(void *);

/* 
 * Clear a list, freeing each node.
 */
void blistd_free(blistd *);

/* 
 * Return length of the list.
 */
int blistd_length(blistd *);

/* 
 * Return 0 if the list is not empty.
 * Otherwise return 1.
 */
int blistd_isempty(blistd *);

/* 
 * Add a value to the end of the list.
 * Return the new length of the list.
 */
int blistd_append(blistd *, void *);

/* 
 * Remove the value at an index.
 * Returns this value.
 * Returns NULL if index is negative or greater than the list's length.
 */
void *blistd_remove(blistd *, int);

/* 
 * Return the value at an index.
 * Returns NULL if index is negative or greater than the list's length.
 */
void *blistd_at(blistd *, int);

/*
 * Return the node at an index.
 * Returns NULL if index is negative or greater than the list's length.
 */
blistd_node *blistd_node_at(blistd *, int);

/* 
 * Push a value onto the stack.
 * Equivalent to blist_append, but with a familiar name for stacks.
 */
int blistd_push(blistd *, void *);

/* 
 * Pop the top value off of the stack.
 * Returns NULL if the stack is empty.
 */
void *blistd_pop(blistd *);

/* 
 * Return the top value without popping it.
 * Returns NULL if the stack is empty.
 */
void *blistd_peek(blistd *);

/* 
 * Add a value to the end of the queue.
 * Equivalent to blist_append, but with a familiar name for queues.
 */
int blistd_enqueue(blistd *, void *);

/* 
 * Remove and return the item at the front of the queue.
 * Returns NULL if the queue is empty.
 */
void *blistd_dequeue(blistd *);

/*
 * Change the value of the node at an index.
 * Return 0 if index isn't valid, otherwise 1.
 */
int blistd_set(blistd *, int, void *); 

/*
 * Insert a value after an index.
 * Returns 0 if index isn't valid, otherwise 1.
 */
int blistd_insert_after(blistd *, int, void *);

/*
 * Concatenate two lists together.
 * First list holds both.
 * Returns new length.
 */
int blistd_concat(blistd *, blistd *);

int blistd_sum(blistd *);
int blistd_max(blistd *);
int blistd_min(blistd *);
int blistd_sort(blistd *);
int blistd_mergesort(blistd *);
int blistd_quicksort(blistd *);

char *blistd_join(blistd *, char *);

#endif
