#ifndef BLIB_LISTS_H
#define BLIB_LISTS_H

/*
 * Holds a doubly linked list item.
 * You shouldn't have to create them yourself.
 */
typedef struct blists_node {
    struct blists_node *next;
    void *value;
} blists_node;

/*
 * Holds a doubly linked list.
 */
typedef struct blists {
    blists_node *first;
    blists_node *last;
    int length;
} blists;

/* 
 * Initialize an empty list.
 * Return NULL if bmalloc fails.
 */
blists *blists_init();

/* 
 * Initialize a list from an existing array.
 * Return NULL if bmalloc fails.
 */
blists *blists_einit(void **, int);

/* 
 * Initialize a list node.
 * Return NULL if bmalloc fails.
 */
blists_node *blists_node_init(void *);

/* 
 * Clear a list, freeing each node.
 */
void blists_free(blists *);

/* 
 * Return length of the list.
 */
int blists_length(blists *);

/* 
 * Return 0 if the list is not empty.
 * Otherwise return 1.
 */
int blists_isempty(blists *);

/* 
 * Add a value to the end of the list.
 * Return the new length of the list.
 */
int blists_append(blists *, void *);

/* 
 * Remove the value at an index.
 * Returns this value.
 * Returns NULL if index is negative or greater than the list's length.
 */
void *blists_remove(blists *, int);

/* 
 * Return the value at an index.
 * Returns NULL if index is negative or greater than the list's length.
 */
void *blists_at(blists *, int);

/*
 * Return the node at an index.
 * Returns NULL if index is negative or greater than the list's length.
 */
blists_node *blists_node_at(blists *, int);

/* 
 * Push a value onto the stack.
 * Equivalent to blist_append, but with a familiar name for stacks.
 */
int blists_push(blists *, void *);

/* 
 * Pop the top value off of the stack.
 * Returns NULL if the stack is empty.
 */
void *blists_pop(blists *);

/* 
 * Return the top value without popping it.
 * Returns NULL if the stack is empty.
 */
void *blists_peek(blists *);

/* 
 * Add a value to the end of the queue.
 * Equivalent to blist_append, but with a familiar name for queues.
 */
int blists_enqueue(blists *, void *);

/* 
 * Remove and return the item at the front of the queue.
 * Returns NULL if the queue is empty.
 */
void *blists_dequeue(blists *);

/*
 * Change the value of the node at an index.
 * Return 0 if index isn't valid, otherwise 1.
 */
int blists_set(blists *, int, void *); 

/*
 * Insert a value after an index.
 * Returns 0 if index isn't valid, otherwise 1.
 */
int blists_insert_after(blists *, int, void *);

/*
 * Concatenate two lists together.
 * First list holds both.
 * Returns new length.
 */
int blists_concat(blists *, blists *);

/*
 *  Functions to deal with integer lists.
 */
int blists_sum(blists *);
int blists_max(blists *);
int blists_min(blists *);
void blists_sort();
void blists_mergesort();
void blists_quicksort();

/*
 * Functions to deal with string lists.
 */
char *blists_join(blists *, char *);

#endif
