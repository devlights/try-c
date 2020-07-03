#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

extern int add(int x, int y);
static bool concat(char* result, size_t len, const char* x, const char* y);

// extern_function -- 外部で宣言された関数を利用するためにプロトタイプ宣言が必要であることを示すサンプルです.
//
// REFERENCES:
//   - https://www.hiramine.com/programming/c_cpp/constcharconst.html
//   - https://stackoverflow.com/questions/4570147/safe-string-functions-in-mac-os-x-and-linux
//   - http://www.c-tipsref.com/reference/stdio/snprintf.html
//   - https://stackoverflow.com/questions/51353648/const-qualification-of-parameters-in-function-declaration
//   - https://www.jpcert.or.jp/sc-rules/c-int01-c.html
//   - https://stackoverflow.com/questions/50399090/use-of-a-signed-integer-operand-with-a-binary-bitwise-operator-when-using-un
int main(void) {
    int x = 1;
    int y = 2;

    // -----------------------------------------------
    // add() は、 sub.c 側で定義されている関数
    // 最終的に実行ファイルが生成される手前でリンカによって
    // main.o と sub.o が結合されるので、動作はするが
    // C99 以降のコンパイラでは以下の警告が出る.
    //
    // warning: implicit declaration of function 'add' is invalid in C99
    //
    // これを防ぐためには、関数プロトタイプを宣言しておく必要がある.
    // -----------------------------------------------
    int r = add(x, y);
    printf("result: %d\n", r);

    // const char*      : 定数データへのポインタ。中身の変更不可、アドレス変更可能
    // char* const      : 定数ポインタ。中身の変更可能。アドレス変更不可
    // const char* const: 定数データへの定数ポインタ。中身の変更不可、アドレス変更不可
    const char* const m1 = "hello";
    const char* const m2 = "world";
    const size_t BUF_SIZE = 128;

    char buf[BUF_SIZE];
    for (size_t i = 0; i < BUF_SIZE; i++) {
        buf[i] = 0;
    }

    // concat() は、自身の中で定義されている関数であるが main() よりも
    // 後に記載されている。そのため、コンパイル時に発見できないためプロトタイプ宣言が必要
    if (!concat(buf, BUF_SIZE, m1, m2)) {
        printf("[concat] error\n");
        return 1;
    }

    printf("%s\n", buf);

    return EXIT_SUCCESS;
}

static bool concat(char* result, size_t len, const char* x, const char* y) {
    if (len < 0 || len > (SIZE_MAX >> 1u)) {
        return false;
    }

    int r = snprintf(result, len, "%s [%s]", x, y);
    if (r < 0 || len <= r) {
        return false;
    }

    return true;
}
