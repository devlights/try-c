#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ------------------------------------
    // C言語で 8進数定数 は 0から始まる数値で表す
    // ------------------------------------
    int x = 07;
    printf("[x] %d\n", x); // => 7

    x = 010;
    printf("[x] %d\n", x); // => 8

    x = 011;
    printf("[x] %d\n", x); // => 9

    x = 020;
    printf("[x] %d\n", x); // => 16

    return EXIT_SUCCESS;
}
