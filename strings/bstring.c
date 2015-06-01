/*
 *  bstring.c - blib helper functions for strings
 */

#include "../strings/bstring.h"
#include "../memory/bmem.h"

int __str_length(char *s) {
    int len = 0;
    if (s != NULL) while (s[len]) len++;
    return len;
}

bstring *bstring_init(char *str) {
    bstring *ret = (bstring *) bmalloc(sizeof(bstring));
    ret->string = str;
    ret->length = __str_length(str);
    return ret;
}

int bstring_length(bstring *str) {
    return str->length;
}

int bstring_contains_char(bstring *str, char search) {
    for (int i = 0; i < str->length; i++) {
        if (str->string[i] == search) return i;
    }
    return 0;
}

char bstring_at(bstring *str, int index) {
    if (index >= str->length) return 0;
    return str->string[index];
}

int bstring_equals(bstring *a, bstring *b) {
    if (a->length != b->length) return 0;
    int i = 0;
    for (; i < a->length; i++)
        if (a->string[i] != b->string[i]) return 0;
    return 1;
}

int bstring_requals(bstring *a, char *b) {
    return bstring_equals(a, bstring_init(b));
}

bstring *bstring_concat(bstring *a, bstring *b) {
    int len = a->length + b->length;
    char *join = (char *) bmalloc(len * sizeof(char));
    int i = 0;
    for (; i < a->length; i++) {
        join[i] = a->string[i];
    }
    int j = 0;
    for (; j < b->length; j++) {
        join[i] = b->string[j];
        i++;
    }
    a->string = join;
    a->length = len;
    return a;
}

bstring *bstring_nconcat(bstring *a, bstring *b, int n) {
    int len = a->length + n;
    char *join = (char *) bmalloc(len * sizeof(char));
    int i = 0;
    for (; i < a->length; i++) {
        join[i] = a->string[i];
    }
    int j = 0;
    for (; j < n; j++) {
        join[i] = b->string[j];
        i++;
    }
    a->string = join;
    a->length = len;
    return a;
}

bstring *bstring_rconcat(bstring *a, char *b) {
    return bstring_concat(a, bstring_init(b));
}

bstring *bstring_rnconcat(bstring *a, char *b, int n) {
    return bstring_nconcat(a, bstring_init(b), n);
}

bstring *bstring_substr(bstring *s, int start, int end) {
    char *sub = bstring_rsubstr(s, start, end);
    if (sub == NULL) return 0;
    return bstring_init(sub);
}

char *bstring_rsubstr(bstring *s, int start, int end) {
    int len = end - start;
    char *ret = (char *) bmalloc(len * sizeof(char));
    if (ret != NULL) {
        int i = 0;
        for (; i < len; i++) ret[i] = s->string[start + i];
    }
    return ret;
}

int bstring_contains(bstring *big, bstring *small) {
    if (small->length > big->length) return 0;
    if (small->length == big->length) return bstring_equals(big, small);
    return bstring_rcontains(big, small->string);
}

int bstring_rcontains(bstring *super, char *sub) {
    int len = __str_length(sub);
    if (len > super->length) return 0;
    if (len == super->length) return bstring_requals(super, sub);
    int i = 0;
    for (; i < super->length - len; i++) {
        if (super->string[i] != sub[0]) i += len;
        int j = 0;
        for (; j < len; j++) if (super->string[j] != sub[j]) break;
        return 1;
    }
    return 0;
}
