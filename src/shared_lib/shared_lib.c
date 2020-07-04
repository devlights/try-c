#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define VALUES_LEN 3

extern void hello_from_external_lib();
static void init_values(int values[]);

int main(void) {
    int values[VALUES_LEN];
    init_values(values);

    int result = add(values, VALUES_LEN);
    printf("[add] %d\n", result);

    hello_from_external_lib();

    return EXIT_SUCCESS;
}

static void init_values(int values[]) {
    for (int i = 0; i < VALUES_LEN; i++) {
        values[i] = (i + 1);
    }
}
