#include <stdio.h>
#include <mem.h>
#include <malloc.h>
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

void char_array03() {
    char strings[12];
    char first[6] = "world";
    char second[7] = " hello";

    memset(strings, 0, sizeof(strings));

    strncat(strings, first, (sizeof(first) - 1));
    strncat(strings, second, (sizeof(second) - 1));

    printf("%s\n", strings);
}

void char_array04() {
    char strings[12] = "hello world";

    /* --------------------------------------------------
     * strlen関数は指定した char* の文字数を返す
     * 返ってくる文字数は、最後の終端文字を除いたカウントとなる
     * -------------------------------------------------- */
    printf("length=%d\n", strlen(strings));

    /* --------------------------------------------------
     * 動的に確保したメモリをポインタで受取り
     * そこに文字列をコピーする
     * -------------------------------------------------- */
    char *ptr;

    /* メモリ確保 (必ずエラーチェックをする必要がある) */
    ptr = (char *)malloc(sizeof(strings));
    if (ptr == NULL) {
        /* メモリ確保に失敗した */
        printf("error at malloc");
        exit(-1);
    }

    /* 確保したメモリ領域をゼロクリア */
    memset(ptr, 0, (sizeof(strings)));

    /* 文字列をコピー */
    strncpy(ptr, "hello world", sizeof(strings) - 1);

    printf("ptr = %s\n", ptr);
    printf("ptr length=%d\n", strlen(ptr));

    /* 確保したメモリは必ず開放が必要。malloc書いた際にペアで書くほうがよい */
    free(ptr);
}