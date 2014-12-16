/*
 *  blistd.c - the doubly linked list implementation for blib
 */

#include "../lists/blistd.h"
#include "../memory/bmem.h"

blistd *blistd_init() {
    blistd *b = (blistd *) bmalloc(sizeof(blistd));
    if (b == NULL) return NULL;
    b->first = NULL, b->last = NULL, b->length = 0;
    return b;
}

blistd *blistd_einit(void **vs, int ct) {
    blistd *b = (blistd *) bmalloc(sizeof(blistd));
    if (b == NULL) return NULL;
    int i = 0;
    for (; i < ct; i++) blistd_append(b, vs[i]);
    return b;
}

blistd_node *blistd_node_init(void *v) {
    blistd_node *n = (blistd_node *) bmalloc(sizeof(blistd_node));
    if (n == NULL) return NULL;
    n->next = NULL, n->prev = NULL, n->value = v;
    return n;
}

void blistd_free(blistd *b) {
    if (b->length == 0) return;
    blistd_node *cur = b->first;
    blistd_node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->prev = NULL, cur->next = NULL;
        free(cur);
        b->length--;
        cur = nxt;
    }
    free(b);
}

int blistd_length(blistd *b) {
    return b->length;
}

int blistd_isempty(blistd *b) {
    if (b->length) return 0;
    return 1;
}

int blistd_append(blistd *b, void *v) {
    blistd_node *new = blistd_node_init(v);
    if (blistd_isempty(b)) {
        b->first = new;
        b->last = new;
    } else {
        blistd_node *end = b->last;
        new->prev = end;
        end->next = new;
        b->last = new;
    }
    return ++(b->length);
}

void *blistd_at(blistd *b, int index) {
    blistd_node *n = blistd_node_at(b, index);
    if (n != NULL) return n->value;
    return (void *) NULL;
}

blistd_node *blistd_node_at(blistd *b, int index) {
    if (index < 0 || index > b->length) return (blistd_node *) NULL;
    if (index < (b->length / 2 + 1)) {
        int i = 0;
        blistd_node *cur = b->first;
        for(; i < b->length; i++) {
            if (i == index) return cur;
            cur = cur->next;
        }
    } else {
        int i = b->length - 1;
        blistd_node *cur = b->last;
        for (; i > 0; i--) {
            if (i == index) return cur;
            cur = cur->prev;
        }
    }
    return (blistd_node *) NULL;
}

void *blistd_remove(blistd *b, int index) {
    blistd_node *x = blistd_node_at(b, index);
    if (x != NULL) {
        if (x->next != NULL) x->next->prev = x->prev;
        else b->last = x->prev;

        if (x->prev != NULL) x->prev->next = x->next;
        else b->first = x->next;

        b->length--;
        return x->value;
    }
    return (void *) NULL;
}

int blistd_push(blistd *b, void *v) {
    return blistd_append(b, v);
}

void *blistd_pop(blistd *b) {
    if (b->length == 0) return NULL;
    return blistd_remove(b, b->length - 1);
}

void *blistd_peek(blistd *b) {
    if (b->length == 0) return NULL;
    return b->last->value;
}

int blistd_enqueue(blistd *b, void *v) {
    return blistd_append(b, v);
}

void *blistd_dequeue(blistd *b) {
    if (b->length == 0) return (void *) NULL;
    return blistd_remove(b, 0);
}

int blistd_set(blistd *b, int index, void *v) {
    blistd_node *n = blistd_node_at(b, index);
    if (n != NULL) {
        n->value = v;
        return 1;
    }
    return 0;
}

int blistd_insert_after(blistd *b, int index, void *v) {
    if (index == (b->length - 1)) {
        blistd_append(b, v);
        return 1;
    }
    blistd_node *x = blistd_node_at(b, index);
    if (x != NULL) {
        blistd_node *add = blistd_node_init(v);
        if (add == NULL) return 0;
        blistd_node *next = x->next;
        add->prev = x;
        add->next = next;
        x->next = add;
        next->prev = add;
        b->length++;
    }
    return 0;
}

int blistd_concat(blistd *a, blistd *b) {
    if (a->length == 0) {
        a->first = b->first;
        a->last = b->last;
        a->length = b->length;
    } else if (b->length != 0) {
        a->last->next = b->first;
        b->first->prev = a->last;
        a->last = b->last;
        a->length = a->length + b->length;
    }
    return a->length;
}

int blistd_sum(blistd *b) {
    blistd_node *n = b->first;
    int sum = 0;
    while (n) { 
        if (n->value) sum += * (int *) n->value;
        n = n->next;
    }
    return sum;
}

int blistd_max(blistd *b) {
    blistd_node *n = b->first;
    int max = -9999999;
    while (n) { 
        if (n->value && (* (int *) (n->value)) > max) max = * (int *) n->value;
        n = n->next;
    }
    return max;
}

int blistd_min(blistd *b) {
    blistd_node *n = b->first;
    int min = 99999999;
    while (n) {
        if (n->value && (* (int *) (n->value)) < min) min = * (int *) n->value;
        n = n->next;
    }
    return min;
}

int blistd_sort(blistd *b) {

}

int blistd_mergesort(blistd *b) {

}

int blistd_quicksort(blistd *b) {

}

char *blistd_join(blistd *b, char *s) {
    int size = (b->length - 1) * strlen(s);
    blistd_node *x = b->first;
    while (x) {
        size += strlen((char *) x->value);
        x = x->next;
    }
    char *buf = (char *) bmalloc(size * sizeof(char));
    /*****\                     \\*--+--+--+-)-\/---|--+            
       * ~~~  ~~~~  ~~~  ~~~    ::|>>>>>><>>>}-})--------[x]->               
    \*****/                     //*--+--+--+-)-/\---|--+              
    return buf;
}
