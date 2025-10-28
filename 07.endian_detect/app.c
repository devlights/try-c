#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline bool is_little_endian(void) {
    const uint16_t test = 0x1234;
    if (*(uint8_t *)&test == 0x34) {
        return true;
    }

    return false;
}

int main(void) {
    printf("HOST ENDIAN: %s\n", is_little_endian() ? "LITTLE" : "BIG");
    return EXIT_SUCCESS;
}