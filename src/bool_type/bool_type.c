#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool always_return_true();
static bool always_return_false();

int main(void) {
    // --------------------------------------------------------
    // C99 から bool 型が導入されている.
    // 定義は stdbool.h にある.
    //
    // C における bool 型は _Bool という名前で定義されている.
    // stdbool.h には、定数マクロとして true と false が定義されている
    // ので、それが利用できる.
    //
    // また、_Bool は bool という名前でエイリアスされている。
    // --------------------------------------------------------
    printf("[stdbool/true ] %d\n", true);
    printf("[stdbool/false] %d\n", false);

    if (always_return_true()) {
        printf("true\n");
    }

    if (!always_return_false()) {
        printf("false\n");
    }

    return EXIT_SUCCESS;
}

bool always_return_true() {
    return true;
}

bool always_return_false() {
    return false;
}