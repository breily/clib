#include "bfunc.h"
#include <stdio.h>

int num_tests = 2;

int map_test() {
    return 0;
}

int filter_test() {
    return 0;
}

main() {
    typedef struct tuple {
        int (*func)(void);
        char *str;
    } tuple;    
    tuple data[] = { map_test,    "map", 
                     filter_test, "filter" 
                   };

    printf("# Testing bfunc.c\n");
    printf("# Running tests:\n");
    int passes = 0;
    int failures = 0;
    int i = 0;
    
    for(; i < num_tests; i++) {
        printf("\t* testing %s... ", data[i].str);
        if ((*(data[i].func))()) {
            printf("pass\n");
            passes++;
        } else {
            printf("fail\n");
            failures++;
        }
    }

    printf("# Pass: %2d | Fail: %2d | Total: %2d / %2d \n", passes, failures, 
        passes, failures);
}
