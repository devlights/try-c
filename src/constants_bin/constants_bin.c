#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ----------------------------------------------------
    // C言語では 2進数定数 は標準ではサポートされていない。
    // しかし、最近の gcc および clang ではサポートされている。
    // 拡張機能扱い。
    //
    // 2進数定数は 0b で始まる。
    //
    // 以下、本コードを試した環境
    //
    // [Linux]
    // $ gcc --version
    // gcc (Ubuntu 9.3.0-10ubuntu2) 9.3.0
    //
    // [macOS]
    // $ gcc --version
    // Apple clang version 11.0.3 (clang-1103.0.32.62)
    // $ clang --version
    // Apple clang version 11.0.3 (clang-1103.0.32.62)
    // ----------------------------------------------------
    int x = 0b0111;
    printf("[x] %d\n", x);  // => 7

    x = 0b11111111;
    printf("[x] %d\n", x);  // => 255

    return EXIT_SUCCESS;
}
