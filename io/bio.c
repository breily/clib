#include "../io/bio.h"
#include "../memory/bmem.c"

/* Default input buffer */
int BUFFER_SIZE = 1024;
/* Count buffers allocated/freeed */
int MEMORY_ALLOCATED = 0;
/* Error code */
int ERROR_BUFFER_SIZE_EXCEEDED = -1;
/* breadline_map exit code */
int BREADLINE_MAP_EXIT_CODE = -2;

/* Allocate an input buffer */
char *bio_calloc() {
    char *t = (char *) bcalloc(BUFFER_SIZE, sizeof(char));
    MEMORY_ALLOCATED += malloc_size(t);
    return t;
}

/* Free an input buffer */
void bio_free(char *s) {
    MEMORY_ALLOCATED -= malloc_size(s);
    free(s);
}

/* Return one line of input, including trailing '\n' */
int breadline(char *str) {
    int len = 0;
    int cur;
    while ((cur = getchar()) > 0) {
        if (len == BUFFER_SIZE - 2) return ERROR_BUFFER_SIZE_EXCEEDED;
        str[len++] = cur;
        if (cur == '\n')  break;
    }
    str[len++] = '\0';
    return len;
}

/* Repeated call a function with the output of breadline */
int breadline_map(int (*func)(char *), char *prompt) {
    char *str;
    int code;
    for (;;) {
        str = bio_calloc();
        printf("%s", prompt);
        int length = breadline(str);
        if (length == ERROR_BUFFER_SIZE_EXCEEDED) return length;
        if (length == 1) break;
        code = func(str);
        bio_free(str);
        if (code == BREADLINE_MAP_EXIT_CODE) return code;
    }
    bio_free(str);
    return code;
}
