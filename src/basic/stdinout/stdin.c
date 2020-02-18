#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 256

void basic_stdin_series() {
    char buffer[ARRAY_SIZE] = {0};

    // ------------------------------------------------------------------
    // scanf -- 標準入力から読み取る
    // ------------------------------------------------------------------
    printf("[1] scanf: ");
    scanf("%s", buffer);
    scanf("%*c");
    printf("%s\n", buffer);

    // scanf はちゃんとフォーマットを指定することで指定したバイト数以上読み込まないようにできる
    // https://qiita.com/mpyw/items/aff12a6ff2c7726ed1d8
    // 以下、５バイトのみ読み取りして、残りを捨てるやり方
    memset(buffer, '\0', sizeof(char) * ARRAY_SIZE);
    char scanf_format[] = "%5[^\n]%*[^\n]";

    printf("[2] scanf(5バイトのみ読み取り): ");
    scanf(scanf_format, buffer);
    scanf("%*c");
    printf("%s\n", buffer);
}
