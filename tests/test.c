#include "lists/blistd.h"
#include "lists/blists.h"
#include "strings/bstring.h"
#include "maps/bhash.h"
#include "memory/bmem.h"

#include <stdio.h>

/*****************************************************************************/
/*                         Doubly-Linked List Functions                      */
/*****************************************************************************/

#define LIST_TESTS 24

int d_init_test() {
    blistd *b = blistd_init();
    if (b == NULL) return 0;
    free(b);
    return 1;
}

int d_einit_test() {
    char *array[] = { "ab", "cd", "ef", "gh" };
    blistd *b = blistd_einit((void **) array, 4);
    if (blistd_length(b) != 4) return 0;
    if (strcmp("ab", blistd_at(b, 0))) return 0;
    free(b);
    return 1;
}

int d_isempty_test() {
    blistd *b = blistd_init();
    if (blistd_isempty(b) != 1) return 0;
    blistd_append(b, "asdf");
    if (blistd_isempty(b) != 0) return 0;
    free(b);
    return 1;
}

int d_length_test() {
    blistd *b = blistd_init();
    if (blistd_length(b) != 0) return 0;
    blistd_append(b, "asdf");
    if (blistd_length(b) != 1) return 0;
    free(b);
    return 1;
}

int d_at_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_append(b, "b");
    if (strcmp("b", blistd_at(b, 1))) return 0;
    free(b);
    return 1;
}

int d_free_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_append(b, "b");
    blistd_free(b);
    return 1;
}

int d_remove_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_append(b, "b");
    blistd_remove(b, 1);
    if (blistd_length(b) != 1) return 0;
    return 1;
}

int d_push_test() {
    blistd *b = blistd_init();
    blistd_push(b, "a");
    blistd_push(b, "b");
    if (strcmp(blistd_peek(b), "b")) return 0;
    return 1;
}

int d_pop_test() {
    blistd *b = blistd_init();
    blistd_push(b, "a");
    blistd_push(b, "b");
    if (strcmp(blistd_pop(b), "b")) return 0;
    if (strcmp(blistd_peek(b), "a")) return 0;
    return 1;
}

int d_peek_test() {
    blistd *b = blistd_init();
    if (blistd_peek(b) != NULL) return 0;
    blistd_append(b, "a");
    blistd_append(b, "b");
    if (strcmp("b", blistd_peek(b))) return 0;
    return 1;
}

int d_enqueue_test() {
    blistd *b = blistd_init();
    blistd_enqueue(b, "a");
    blistd_enqueue(b, "b");
    if (blistd_length(b) != 2) return 0;
    if (blistd_at(b, 0) == NULL) return 0;
    if (strcmp(blistd_at(b, 0), "a")) return 0;
    return 1;
}

int d_dequeue_test() {
    blistd *b = blistd_init();
    blistd_enqueue(b, "a");
    blistd_enqueue(b, "b");
    char *x = (char *) blistd_dequeue(b);
    if (x == NULL) return 0;
    if (strcmp(x, "a")) return 0;
    if (strcmp(blistd_dequeue(b), "b")) return 0;
    return 1;
}

int d_node_init_test() {
    blistd_node *n = blistd_node_init("asdf");
    if (n == NULL) return 0;
    if (n->next != NULL) return 0;
    if (n->prev != NULL) return 0;
    if (strcmp(n->value, "asdf")) return 0;
    return 1;
}

int d_set_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_append(b, "b");
    blistd_set(b, 0, "c");
    if (blistd_length(b) != 2) return 0;
    if (blistd_at(b, 0) == NULL) return 0;
    if (strcmp(blistd_at(b, 0), "c")) return 0;
    return 1;
}

int d_insert_after_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_append(b, "b");
    blistd_insert_after(b, 0, "c");
    if (blistd_at(b, 1) == NULL) return 0;
    if (strcmp(blistd_at(b, 1), "c")) return 0;
    blistd_insert_after(b, 2, "d");
    if (blistd_at(b, 3) == NULL) return 0;
    if (strcmp(blistd_at(b, 3), "d")) return 0;
    return 1;
}

int d_node_at_test() {
    blistd *b = blistd_init();
    blistd_append(b, "a");
    blistd_node *n = blistd_node_at(b, 0);
    if (strcmp(n->value, "a")) return 0;
    return 1;
}

int d_list_concat_test() {
    blistd *a = blistd_init();
    blistd_append(a, "a");
    blistd *b = blistd_init();
    if (blistd_concat(a, b) != 1) return 0;
    if (blistd_concat(b, a) != 1) return 0;
    blistd_append(b, "b");
    if (blistd_concat(a, b) != 3) return 0;
    if (blistd_concat(b, a) != 5) return 0;
    return 1;
}

int d_sum_test() { 
    int a = 1, b = 2, c = 3, d = 4;
    blistd *s = blistd_init();
    blistd_append(s, &a);
    blistd_append(s, &b);
    blistd_append(s, &c);
    blistd_append(s, &d);
    if (blistd_sum(s) != 10) return 0;
    return 1;
}

int d_max_test() { 
    int a = 1, b = 2, c = 3, d = 4;
    blistd *s = blistd_init();
    blistd_append(s, &a);
    blistd_append(s, &b);
    blistd_append(s, &c);
    blistd_append(s, &d);
    if (blistd_max(s) != 4) return 0;
    return 1;
}

int d_min_test() { 
    int a = 1, b = 2, c = 3, d = 4;
    blistd *s = blistd_init();
    blistd_append(s, &a);
    blistd_append(s, &b);
    blistd_append(s, &c);
    blistd_append(s, &d);
    if (blistd_min(s) != 1) return 0;
    return 1;
}

int d_sort_test() { return 2; }
int d_mergesort_test() { return 2; }
int d_quicksort_test() { return 2; }
int d_join_test() { return 2; }

/*****************************************************************************/
/*                         Singly-Linked List Functions                      */
/*****************************************************************************/

#define SLIST_TESTS 24

int s_init_test() {
    blists *b = blists_init();
    if (b == NULL) return 0;
    return 1;
}

int s_einit_test() {
    char *array[] = { "ab", "cd", "ef", "gh" };
    blists *b = blists_einit((void **) array, 4);
    if (blists_length(b) != 4) return 0;
    if (strcmp("ab", blists_at(b, 0))) return 0;
    return 1;
}

int s_isempty_test() {
    blists *b = blists_init();
    if (blists_isempty(b) != 1) return 0;
    blists_append(b, "asdf");
    if (blists_isempty(b) != 0) return 0;
    return 1;
}

int s_length_test() {
    blists *b = blists_init();
    if (blists_length(b) != 0) return 0;
    blists_append(b, "asdf");
    if (blists_length(b) != 1) return 0;
    return 1;
}

int s_at_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_append(b, "b");
    if (strcmp("b", blists_at(b, 1))) return 0;
    return 1;
}

int s_free_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_append(b, "b");
    blists_free(b);
    return 1;
}

int s_remove_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_append(b, "b");
    blists_remove(b, 1);
    if (blists_length(b) != 1) return 0;
    return 1;
}

int s_push_test() {
    blists *b = blists_init();
    blists_push(b, "a");
    blists_push(b, "b");
    if (strcmp((char *) blists_peek(b), "b")) return 0;
    return 1;
}

int s_pop_test() {
    blists *b = blists_init();
    blists_push(b, "a");
    blists_push(b, "b");
    if (strcmp(blists_pop(b), "b")) return 0;
    if (strcmp(blists_peek(b), "a")) return 0;
    return 1;
}

int s_peek_test() {
    blists *b = blists_init();
    if (blists_peek(b) != NULL) return 0;
    blists_append(b, "a");
    blists_append(b, "b");
    if (strcmp("b", blists_peek(b))) return 0;
    return 1;
}

int s_enqueue_test() {
    blists *b = blists_init();
    blists_enqueue(b, "a");
    blists_enqueue(b, "b");
    if (blists_length(b) != 2) return 0;
    if (blists_at(b, 0) == NULL) return 0;
    if (strcmp(blists_at(b, 0), "a")) return 0;
    return 1;
}

int s_dequeue_test() {
    blists *b = blists_init();
    blists_enqueue(b, "a");
    blists_enqueue(b, "b");
    char *x = (char *) blists_dequeue(b);
    if (x == NULL) return 0;
    if (strcmp(x, "a")) return 0;
    if (strcmp(blists_dequeue(b), "b")) return 0;
    return 1;
}

int s_node_init_test() {
    blists_node *n = blists_node_init("asdf");
    if (n == NULL) return 0;
    if (n->next != NULL) return 0;
    if (strcmp(n->value, "asdf")) return 0;
    return 1;
}

int s_set_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_append(b, "b");
    blists_set(b, 0, "c");
    if (blists_length(b) != 2) return 0;
    if (blists_at(b, 0) == NULL) return 0;
    if (strcmp(blists_at(b, 0), "c")) return 0;
    return 1;
}

int s_insert_after_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_append(b, "b");
    blists_insert_after(b, 0, "c");
    if (blists_at(b, 1) == NULL) return 0;
    if (strcmp(blists_at(b, 1), "c")) return 0;
    blists_insert_after(b, 2, "d");
    if (blists_at(b, 3) == NULL) return 0;
    if (strcmp(blists_at(b, 3), "d")) return 0;
    return 1;
}

int s_node_at_test() {
    blists *b = blists_init();
    blists_append(b, "a");
    blists_node *n = blists_node_at(b, 0);
    if (strcmp(n->value, "a")) return 0;
    return 1;
}

int s_list_concat_test() {
    blists *a = blists_init();
    blists_append(a, "a");
    blists *b = blists_init();
    if (blists_concat(a, b) != 1) return 0;
    if (blists_concat(b, a) != 1) return 0;
    blists_append(b, "b");
    if (blists_concat(a, b) != 3) return 0;
    if (blists_concat(b, a) != 5) return 0;
    return 1;
}

int s_sum_test() {
    int a = 1, b = 2, c = 3, d = 4;
    blists *s = blists_init();
    blists_append(s, &a);
    blists_append(s, &b);
    blists_append(s, &c);
    blists_append(s, &d);
    if (blists_sum(s) != 10) return 0;
    return 1;
}

int s_max_test() {
    int a = 1, b = 2, c = 3, d = 4;
    blists *s = blists_init();
    blists_append(s, &a);
    blists_append(s, &b);
    blists_append(s, &c);
    blists_append(s, &d);
    if (blists_max(s) != 4) return 0;
    return 1;
}

int s_min_test() {
    int a = 1, b = 2, c = 3, d = 4;
    blists *s = blists_init();
    blists_append(s, &a);
    blists_append(s, &b);
    blists_append(s, &c);
    blists_append(s, &d);
    if (blists_min(s) != 1) return 0;
    return 1;
}

int s_sort_test() {
    return 2;
}

int s_mergesort_test() {
    return 2;
}

int s_quicksort_test() {
    return 2;
}

int s_join_test() {
    return 2;
}

/*****************************************************************************/
/*                             End List Functions                            */
/*                           Start String Functions                          */
/*****************************************************************************/

#define STRING_TESTS 15

int str_init_test() {
    bstring *str = bstring_init("asdf");
    if (str->length != 4) return 0;
    if (strcmp(str->string, "asdf")) return 0;
    return 1;
}

int str_length_test() {
    bstring *str = bstring_init("asdf");
    if (bstring_length(str) != 4) return 0;
    return 1;
}

int str_at_test() {
    bstring *str = bstring_init("asdf");
    if (bstring_at(str, 0) != 'a') return 0;
    if (bstring_at(str, 3) != 'f') return 0;
    if (bstring_at(str, 10) != 0) return 0;
    return 1;
}

int contains_char_test() {
    bstring *str = bstring_init("asdf");
    if (!bstring_contains_char(str, 'a')) return 0;
    if (bstring_contains_char(str, 'e')) return 0;
    return 1;
}

int equals_test() {
    bstring *a = bstring_init("asdf");
    bstring *b = bstring_init("asdf");
    bstring *c = bstring_init("hjkl");
    if (!bstring_equals(a, b)) return 0;
    if (bstring_equals(a, c)) return 0;
    return 1;
}

int requals_test() {
    bstring *a = bstring_init("asdf");
    if (!bstring_requals(a, "asdf")) return 0;
    return 1;
}

int concat_test() {
    bstring *a = bstring_init("asdf");
    bstring *b = bstring_init("asdf");
    bstring *c = bstring_init("asdfasdf");
    bstring_concat(a, b);
    if (!bstring_equals(a, c)) return 0;
    return 1;
}

int nconcat_test() {
    bstring *a = bstring_init("asdf");
    bstring *b = bstring_init("asdf");
    bstring *c = bstring_init("asdfas");
    a = bstring_nconcat(a, b, 2);
    if (!bstring_equals(a, c)) return 0;
    return 1;
}

int rconcat_test() {
    bstring *a = bstring_init("asdf");
    bstring *b = bstring_init("asdfasdf");
    a = bstring_rconcat(a, "asdf");
    if (!bstring_equals(a, b)) return 0;
    return 1;
}

int rnconcat_test() {
    bstring *a = bstring_init("asdf");
    bstring *b = bstring_init("asdfas");
    a = bstring_rnconcat(a, "asdf", 2);
    if (!bstring_equals(a, b)) return 0;
    return 1;
}

int substr_test() {
    bstring *a = bstring_init("asdfasdf");
    bstring *s = bstring_substr(a, 4, 8);
    if (s == NULL) return 0;
    if (strcmp(s->string, "asdf")) return 0;
    return 1;
}

int rsubstr_test() {
    bstring *a = bstring_init("asdfasdf");
    char *s = bstring_rsubstr(a, 4, 8);
    if (s == NULL) return 0;
    if (strcmp(s, "asdf")) return 0;
    return 1;
}

int contains_test() {
    bstring *a = bstring_init("asdfasdf");
    bstring *b = bstring_init("asdf");
    if (!bstring_contains(a, b)) return 0;
    return 1;
}

int rcontains_test() {
    bstring *a = bstring_init("asdfasdf");
    if (!bstring_rcontains(a, "asdf")) return 0;
    return 1;
}

int __str_length_test() {
    if (__str_length("asdf") != 4) return 0;
    if (__str_length((char *) NULL) != 0) return 0;
    return 1;
}

/*****************************************************************************/
/*                            End String Functions                           */
/*                            Start Hash Functions                           */
/*****************************************************************************/

#define HASH_TESTS 7

int hash_init_test() {
    bhash *b = bhash_init();
    return 1;
}

int lookup_test() {
    return 0;
}

int insert_test() {
    bhash *b = bhash_init();
    bhash_insert(b, "a", "apple");
    bhash_insert(b, "b", "bear");
    bhash_insert(b, "c", "cougar");
    bhash_insert(b, "d", "diorama");
    if (b->size != 4) return 0;
    return 1;
}

int hash_remove_test() {
    return 0;
}

int hash_function_test() {
    return 0;
}

int cmp_function_test() {
    return 0;
}

int resize_function_test() {
    return 0;
}

/*****************************************************************************/
/*                             End Hash Functions                            */
/*****************************************************************************/

main() {
    int passes = 0, fails = 0, test = 0;
    
    printf("| ******************************** |\n");
    printf("| **     testing blistd.c       ** |\n");
    printf("| ******************************** |\n");
    int (*listd_fns[])(void) = { d_init_test, d_isempty_test, d_length_test, d_at_test,
                                 d_free_test, d_remove_test, d_push_test, d_pop_test,
                                 d_enqueue_test, d_dequeue_test, d_node_init_test,
                                 d_einit_test, d_peek_test, d_set_test, d_node_at_test,
                                 d_insert_after_test, d_list_concat_test, d_sum_test,
                                 d_max_test, d_min_test, d_sort_test, d_mergesort_test,
                                 d_quicksort_test, d_join_test };
    char *listd_names[] = { "init", "isempty", "length", "at", "free", "remove",
                            "push", "pop", "enqueue", "dequeue", "node_init",
                            "einit", "peek", "set", "node_at", "insert_after",
                            "concat", "sum", "max", "min", "sort", "mergesort",
                            "quicksort", "join" };

    for (; test < LIST_TESTS; test++) {
        printf("|\t* %-16s=> ", listd_names[test]);
        switch ((*listd_fns[test])()) {
            case 1:
                printf("pass  |\n");
                passes++;
                break;
            case 0:
                printf("fail  |\n");
                fails++;
                break;
            case 2:
                printf("n/a   |\n");
                break;
        }
    }
    printf("| ******************************** |\n");
    printf("| **     %2d / %2d tests pass     ** |\n", passes, passes + fails);
    printf("| ******************************** |\n");
    printf("| ******************************** |\n");

    passes = fails = test = 0;

    printf("| ******************************** |\n");
    printf("| **     testing blists.c       ** |\n");
    printf("| ******************************** |\n");
    int (*lists_fns[])(void) = { s_init_test, s_isempty_test, s_length_test, s_at_test,
                                 s_free_test, s_remove_test, s_push_test, s_pop_test,
                                 s_enqueue_test, s_dequeue_test, s_node_init_test,
                                 s_einit_test, s_peek_test, s_set_test, s_node_at_test,
                                 s_insert_after_test, s_list_concat_test, s_sum_test,
                                 s_max_test, s_min_test, s_sort_test, s_mergesort_test,
                                 s_quicksort_test, s_join_test };
    char *lists_names[] = { "init", "isempty", "length", "at", "free", "remove",
                            "push", "pop", "enqueue", "dequeue", "node_init",
                            "einit", "peek", "set", "node_at", "insert_after",
                            "concat", "sum", "max", "min", "sort", "mergesort",
                            "quicksort", "join" };

    for (; test < SLIST_TESTS; test++) {
        printf("|\t* %-16s=> ", lists_names[test]);
        switch ((*lists_fns[test])()) {
            case 1:
                printf("pass  |\n");
                passes++;
                break;
            case 0:
                printf("fail  |\n");
                fails++;
                break;
            case 2:
                printf("n/a   |\n");
                break;
        }
    }
    printf("| ******************************** |\n");
    printf("| **     %2d / %2d tests pass     ** |\n", passes, passes + fails);
    printf("| ******************************** |\n");
    printf("| ******************************** |\n");

    passes = fails = test = 0;

    printf("| ******************************** |\n");
    printf("| **     testing bstring.c      ** |\n");
    printf("| ******************************** |\n");
    int (*str_fns[])(void) = { str_init_test, str_length_test, str_at_test, 
                               contains_char_test,
                               equals_test, requals_test, concat_test, nconcat_test, 
                               rconcat_test, rnconcat_test, substr_test, rsubstr_test, 
                               contains_test, rcontains_test, __str_length_test };
    char *str_names[] = { "init", "length", "at", "contains_char", "equals", "requals",
                          "concat", "nconcat", "rconcat", "rnconcat", "substr",
                          "rsubstr", "contains", "rcontains", "str_length" };
    
    for (; test < STRING_TESTS; test++) {
        printf("|\t* %-16s=> ", str_names[test]);
        switch ((*str_fns[test])()) {
            case 1:
                printf("pass  |\n");
                passes++;
                break;
            case 0:
                printf("fail  |\n");
                fails++;
                break;
            case 2:
                printf("n/a   |\n");
                break;
        }
    }
    printf("| ******************************** |\n");
    printf("| **     %2d / %2d tests pass     ** |\n", passes, passes + fails);
    printf("| ******************************** |\n");
    printf("| ******************************** |\n");

    passes = fails = test = 0;

    printf("| ******************************** |\n");
    printf("| **      testing bhash.c       ** |\n");
    printf("| ******************************** |\n");
    int (*hash_fns[])(void) = { hash_init_test, lookup_test, insert_test, 
                                hash_remove_test,
                                hash_function_test, cmp_function_test,
                                resize_function_test };
    char *hash_names[] = { "init", "lookup", "insert", "remove", "hash_function",
                           "cmp_function", "resize_function" };

    for (; test < HASH_TESTS; test++) {
        printf("|\t* %-16s=> ", hash_names[test]);
        switch ((*hash_fns[test])()) {
            case 1:
                printf("pass  |\n");
                passes++;
                break;
            case 0:
                printf("fail  |\n");
                fails++;
                break;
            case 2:
                printf("n/a   |\n");
                break;
        }
    }
    printf("| ******************************** |\n");
    printf("| **     %2d / %2d tests pass     ** |\n", passes, passes + fails);
    printf("| ******************************** |\n");
    printf("| ******************************** |\n");

    return 0;
}
