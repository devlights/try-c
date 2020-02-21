#include <stdio.h>

#ifdef _WIN32
    #include <mem.h>
    #include <malloc.h>
#else
    #include <memory.h>
    #include <stdlib.h>
#endif

#define HELLOWORLD_STR_LEN 12

void basic_char_array01() {
    /* -------------------------------------------------
     * 宣言と同時に代入
     * C言語の文字列は、ただの char[] 。
     * さらに末尾に終端文字 (\0) が必要なので、実際の文字数よりも１多く確保が必要。
     *
     * 宣言と同時に初期化する場合のみ要素数を書かなくてよい。
     * ------------------------------------------------- */
    char strings[] = "hello world";
    printf("%s\n", strings);
}

void basic_char_array02() {
    char strings[HELLOWORLD_STR_LEN];

    /* --------------------------------------------------
     * 利用する前に必ずバッファをゼロクリア
     * これをしないと、終端文字がないためおかしな出力となる.
     * -------------------------------------------------- */
    memset(strings, 0, sizeof(strings));

    /* --------------------------------------------------
     * 対象となる文字列をコピー
     * 文字配列の最後の１バイトは、終端文字が入る部分なので -1 が必要.
     * -------------------------------------------------- */
    size_t len_strings = strlen(strings);
    size_t len_helloworld = strlen("hello world");

    if (len_helloworld <= len_strings) {
        strncpy(strings, "hello world", (sizeof(strings) - 1));
    }

    printf("%s\n", strings);
}

void basic_char_array03() {
    char strings[HELLOWORLD_STR_LEN];
    char first[] = "world";
    char second[] = " hello";

    memset(strings, 0, sizeof(strings));

    /* ---------------------------------------------------------------------------------------
     * strncat(strings, first, (sizeof(first) - 1)); という風に記述していると以下の警告が出た。
     * size argument in 'strncat' call appears to be size of the source [-Wstrncat-size]
     *
     * ネットで調べると、sizeofじゃなくてちゃんとstrlenしてサイズ指定しろってことらしい。
     * --------------------------------------------------------------------------------------- */
    strncat(strings, first, (strlen(first) - 1));
    strncat(strings, second, (strlen(second) - 1));

    printf("%s\n", strings);
}

void basic_char_array04() {
    char strings[] = "hello world";

    /* --------------------------------------------------
     * strlen関数は指定した char* の文字数を返す
     * 返ってくる文字数は、最後の終端文字を除いたカウントとなる
     * -------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------
     * printf("length=%d\n", strlen(strings)); って記述していると以下の警告がでた。
     * format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]
     *
     * 書式の方は %d で int としているのに、strlen() の結果は unsigned long なので、ちゃんと %lu ってしろってことらしい。
     * -------------------------------------------------------------------------------------------------------- */
    printf("length=%lu\n", strlen(strings));

    /* --------------------------------------------------
     * 動的に確保したメモリをポインタで受取り
     * そこに文字列をコピーする
     * -------------------------------------------------- */
    char *ptr;

    /* メモリ確保 (必ずエラーチェックをする必要がある) */
    ptr = (char *) malloc(sizeof(strings));
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
    printf("ptr length=%lu\n", strlen(ptr));

    /* 確保したメモリは必ず開放が必要。malloc書いた際にペアで書くほうがよい */
    free(ptr);
}