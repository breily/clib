/*
 *  blists.c - the singly linked list implementation for blib
 */

#include "../lists/blists.h"
#include "../memory/bmem.h"

blists *blists_init() {
    blists *b = (blists *) bmalloc(sizeof(blists));
    if (b) {
        b->first = (blists_node *) NULL;
        b->last = (blists_node *) NULL;
        b->length = 0;
    }
    return b;
}

blists *blists_einit(void **vs, int ct) {
    blists *b = blists_init();
    if (b) {
        int i = 0;
        for (; i < ct; i++) blists_append(b, vs[i]);
    }
    return b;
}

blists_node *blists_node_init(void *v) {
    blists_node *n = (blists_node *) bmalloc(sizeof(blists_node));
    if (n) {
        n->next = NULL, n->value = v;
    }
    return n;
}

void blists_free(blists *b) {
    if (b->length == 0) return;
    blists_node *cur = b->first;
    blists_node *nxt;
    while (cur) {
        nxt = cur->next;
        free(cur);
        b->length--;
        cur = nxt;
    }
    b->first = NULL;
    b->last = NULL;
    free(b);
}

int blists_length(blists *b) {
    return b->length;
}

int blists_isempty(blists *b) {
    if (b->length > 0) return 0;
    return 1;
}

int blists_append(blists *b, void *v) {
    blists_node *new = blists_node_init(v);
    if (blists_isempty(b)) {
        b->first = new;
        b->last = new;
    } else {
        b->last->next = new;
        b->last = new;
    }
    return ++(b->length);
}

void *blists_at(blists *b, int index) {
    blists_node *n = blists_node_at(b, index);
    if (n) return n->value;
    return (void *) NULL;
}

blists_node *blists_node_at(blists *b, int index) {
    if (index < 0 || index > b->length) return (blists_node *) NULL;

    blists_node *cursor = b->first;
    int i = 0;
    for (; i < b->length; i++) {
        if (!cursor) break;
        if (i == index) return cursor;
        cursor = cursor->next;
    }
    return (blists_node *) NULL;
}

void *blists_remove(blists *b, int index) {
    if (index < 0 || index > b->length) return (blists_node *) NULL;
    blists_node *x = b->first;
    blists_node *e = (blists_node *) NULL;
    int i = 0;
    for (; i < b->length; i++) {
        if (i == index) {
            if (e) {
                if (x->next) e->next = x->next;
                else e->next = NULL;
            } else {
                b->first = NULL;
            }
            if (i == (b->length - 1)) b->last = e;
            b->length--;
            return x->value;
        } else { 
            e = x; 
            x = x->next;
        }
    }
    return (void *) NULL;
}

int blists_push(blists *b, void *v) {
    return blists_append(b, v);
}

void *blists_pop(blists *b) {
    if (b->length > 1) {
        return blists_remove(b, b->length - 1);
    } 
    if (b->length == 1) {
        blists_node *ret = b->first;
        b->first = NULL;
        b->last = NULL;
        b->length = 0;
        return ret->value;
    }
    return (void *) NULL;
}

void *blists_peek(blists *b) {
    if (b->length == 0) return NULL;
    return b->last->value;
}

int blists_enqueue(blists *b, void *v) {
    return blists_append(b, v);
}

void *blists_dequeue(blists *b) {
    blists_node *ret = b->first;
    if (b->length == 1) {
        b->first = NULL;
        b->last = NULL;
        b->length = 0;
    } else if (b->length) {
        b->first = b->first->next;
        b->length--;
    }
    if (ret) return ret->value;
    return (void *) NULL;
}

int blists_set(blists *b, int index, void *v) {
    blists_node *n = blists_node_at(b, index);
    if (n) {
        n->value = v;
        return 1;
    }
    return 0;
}

int blists_insert_after(blists *b, int index, void *v) {
    if (index == (b->length - 1)) return blists_append(b, v);
    blists_node *x = blists_node_at(b, index);
    if (x) {
        blists_node *add = blists_node_init(v);
        if (add) {
            add->next = x->next;
            x->next = add;
            return (b->length++);
        }
    } else if (index == -1) {
        blists_node *add = blists_node_init(v);
        add->next = b->first;
        b->first = add;
        return (b->length++);
    }
    return 0;
}

int blists_concat(blists *a, blists *b) {
    if (a->length == 0) {
        a->first = b->first;
        a->last = b->last;
        a->length = b->length;
    } else if (b->length != 0) {
        a->last->next = b->first;
        a->last = b->last;
        a->length = a->length + b->length;
    }
    return a->length;
}

int blists_sum(blists *b) {
    blists_node *n = b->first;
    int sum = 0;
    while (n) { 
        if (n->value) sum += * (int *) n->value;
        n = n->next;
    }
    return sum;
}

int blists_max(blists *b) {
    blists_node *n = b->first;
    int max = -999999;
    while (n) { 
        if (n->value && (* (int *) (n->value)) > max) max = * (int *) n->value;
        n = n->next;
    }
    return max;
}

int blists_min(blists *b) {
    blists_node *n = b->first;
    int min = 99999999;
    while (n) {
        if (n->value && (* (int *) (n->value)) < min) min = * (int *) n->value;
        n = n->next;
    }
    return min;
}

void blists_sort();
void blists_mergesort();
void blists_quicksort();

char *blists_join(blists *b, char *s) {
    int size = (b->length - 1) * strlen(s);
    blists_node *x = b->first;
    while (x) {
        size += strlen((char *) x->value);
        x = x->next;
    }
    char *buf = (char *) bmalloc(size * sizeof(char));

    return buf;
}
