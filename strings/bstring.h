#ifndef BLIB_STRING_H
#define BLIB_STRING_H

typedef struct bstring {
    char *string;
    int length;
} bstring;

/* Return the length of a char* */
int __str_length(char *);

/* Initialize a bstring */
bstring *bstring_init(char *str);

/* Return the length of str */
int bstring_length(bstring *str);

/* Return 0 if search is not in str */
int bstring_contains_char(bstring *str, char search);

/* Return the character at index */
char bstring_at(bstring *str, int index);

/* Return 0 if the bstrings are not equal */
int bstring_equals(bstring *a, bstring *b);

/* Return 0 if the strings are not equal */
int bstring_requals(bstring *a, char *b);

/* Concatenate two bstrings */
bstring *bstring_concat(bstring *a, bstring *b);

/* Concatenate n chars of the second bstring to the first */
bstring *bstring_nconcat(bstring *a, bstring *b, int n);

/* Concatenate a raw char* to a bstring */
bstring *bstring_rconcat(bstring *a, char *b);

/* Concatenate n chars of a char* to a bstring */
bstring *bstring_rnconcat(bstring *a, char *b, int n);

/* Return a non-inclusive substring */
bstring *bstring_substr(bstring *, int, int);

/* Return a char* non-inclusive substring */
char *bstring_rsubstr(bstring *, int, int);

/* Return 1 if bstring contains the sub bstring */
int bstring_contains(bstring *, bstring *);

/* Return 1 if bstring contains the sub string */
int bstring_rcontains(bstring *, char *);

#endif
