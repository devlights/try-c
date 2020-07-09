#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ------------------------------------
    // C言語で 8進数定数 は 0xから始まる数値で表す
    // ------------------------------------
    int x = 0x01;
    printf("[x] %d\n", x);  // => 1

    x = 0x10;
    printf("[x] %d\n", x);  // => 16

    x = 0xFF;
    printf("[x] %d\n", x);  // => 255

    return EXIT_SUCCESS;
}
