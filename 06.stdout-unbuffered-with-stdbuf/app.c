#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h> // glibcが提供する標準I/Oの拡張機能を定義したヘッダファイル (glibc固有)
#include <stdlib.h>
#include <unistd.h>

static void print_msg(const size_t count);

int main(int argc, char *argv[]) {
    // glibcはバッファを遅延割当するため、実際に出力が行われるまでバッファを割り当てない。
    // (ラインバッファやフルバッファの場合に、一度も出力していないとバッファサイズが0バイトで表示される)
    // 本サンプルではバッファサイズを見たいので、意図的に一度出力を行っておく。
    printf("[start]\n");

    bool use_stdbuf = (argc >= 2) ? true : false;
    if (use_stdbuf) {
        // 標準出力をアンバッファリングに設定
        setbuf(stdout, NULL);
    }

#ifdef __GLIBC__
    // バッファリング設定を確認
    {
        size_t buf_size = __fbufsize(stdout);
        printf("バッファサイズ: %zu bytes\n", buf_size);

        bool is_line_buffer = __flbf(stdout) != 0;
        printf("ラインバッファ?: %s\n", is_line_buffer ? "はい" : "いいえ");

        bool is_unbuffered = (buf_size <= 1 && !is_line_buffer);
        if (is_unbuffered) {
            printf("状態: アンバッファ (_IONBF)\n");
        } else if (is_line_buffer) {
            printf("状態: ラインバッファ (_IOLBF)\n");
        } else {
            printf("状態: フルバッファ (_IOFBF)\n");
        }
    }
#endif

    // 確認
    {
        const int count = 5;
        print_msg(count);
    }
}

static void print_msg(const size_t count) {
    for (size_t i = 0; i < count; i++) {
        //
        // バッファリング有りの場合、高確率で即座に表示されないことが多い.
        // アンバッファリングの場合、即座に表示される
        //
        // つまり、以下の場合だと大抵の環境では
        //   - バッファリング　　： ５秒後にまとめて出力
        //   - アンバッファリング： 即座に出力
        // となる
        //
        fprintf(stdout, "[%ld]", i);
        sleep(1);
    }

    printf("\n");
}