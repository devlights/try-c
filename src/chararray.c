#include <stdio.h>
#include <mem.h>
#include "chararray.h"

void char_array01() {
    /* -------------------------------------------------
     * 宣言と同時に代入
     * C言語の文字列は、ただの char[] 。
     * さらに末尾に終端文字 (\0) が必要なので、実際の文字数よりも１多く確保が必要。
     * ------------------------------------------------- */
    char strings[12] = "hello world";
    printf("%s\n", strings);
}

void char_array02() {
    char strings[12];

    /* --------------------------------------------------
     * 利用する前に必ずバッファをゼロクリア
     * これをしないと、終端文字がないためおかしな出力となる.
     * -------------------------------------------------- */
    memset(strings, 0, sizeof(strings));

    /* --------------------------------------------------
     * 対象となる文字列をコピー
     * 文字配列の最後の１バイトは、終端文字が入る部分なので -1 が必要.
     * -------------------------------------------------- */
    strncpy(strings, "hello world", (sizeof(strings) - 1));
    printf("%s\n", strings);
}