#include <stdio.h>
#include <stdlib.h>

// return_exit_success -- stdlib.h に 定義されている EXIT_SUCCESS の サンプルです.
int main(void) {
    // -----------------------------------------------------------
    // stdlib.h には、プログラムからOSに返す戻り値として利用できる。
    // 定数マクロが定義されている。
    //
    // - EXIT_SUCCESS - 成功時 (0)
    // - EXIT_FAILURE - 失敗時 (1)
    // -----------------------------------------------------------
    printf("[EXIT_SUCCESS] %d\n", EXIT_SUCCESS);
    printf("[EXIT_FAILURE] %d\n", EXIT_FAILURE);

    return EXIT_SUCCESS;
}