#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int32_t i1 = 1234;

    // 16進数で表示する場合は %#x or %#X で 0x 付きで表示される
    printf("%#x, %#X, 0x%04x, 0X%04X\n", i1, i1, i1, i1);

    return EXIT_SUCCESS;
}