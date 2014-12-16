#include "bio.h"

extern int MEMORY_ALLOCATED;

int foo(char *str) {
    if (strlen(str) == 3) return -2;
    if (strlen(str) > 1) str[0] = 'x';
    printf(" => %s", str);
}

int main() {
    breadline_map(foo, "");
    printf("mem alloced: %d\n", MEMORY_ALLOCATED);
}
