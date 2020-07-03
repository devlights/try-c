#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // sizeof() は、size_t を返す
    size_t intSize = sizeof(int);

    // size_t は unsigned long なので %lu を指定
    printf("sizeof(int): %lu bytes, %lu bits\n", intSize, intSize*8);

    return EXIT_SUCCESS;
}
