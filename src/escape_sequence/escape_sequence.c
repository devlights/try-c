#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// escape_sequence -- エスケープシーケンスのサンプルです.
//
// REFERECES:
//   - https://marycore.jp/prog/objective-c/sleep-process/#sleep%E9%96%A2%E6%95%B0
//   - https://www.javadrive.jp/cstart/num/index5.html
//   - http://wisdom.sakura.ne.jp/programming/c/Cdata1.html
int main(void) {
    // ----------------------------------------------------
    // C言語では以下のエスケープシーケンスが利用できる
    // 代表的なもののみ記載
    //
    // \t: タブ
    // \n: 改行
    // \b: 後退
    // \': '
    // \": "
    // \0: 文字定数 0. C言語における終端文字を示す. ナル文字とも言う.
    // ----------------------------------------------------
    const int PERCENT_MAX = 100;
    const int SLEEP_TIME  = 50 * 1000; // 50ms
    for (int  i           = 0; i < PERCENT_MAX; i++) {
        int percent = i + 1;

        fprintf(stderr, "%02d", percent);
        usleep(SLEEP_TIME);
        fprintf(stderr, percent == PERCENT_MAX ? "\n" : "\b\b");
    }

    printf("aaa\tbbb\nccc\\\'\"\n");

    // C では 文字列型 存在せず、文字の配列として表現する
    // 文字列の終わりは \0 (null文字、ナル文字ともいう）を終端文字として
    // 認識する。なので、文字列の最後は必ず 終端文字 で終わらないといけない.
    char s1[] = {
            [0] = 'h',
            [1] = 'e',
            [2] = 'l',
            [3] = 'l',
            [4] = '0',
            [5] = '\0'
    };

    size_t len = strnlen(s1, 10);
    printf("[strnlen] len=%d\n", (int) len); // len=5 (strnlen は最後の終端を含まないサイズを返す)

    // 上記の配列の途中に 終端文字 を入れると結果が変わる
    // 終端文字が見えたら、そこで文字列は終わりだと認識しているため
    s1[2] = '\0';
    len = strnlen(s1, 10);
    printf("[strnlen] len=%d\n", (int) len); // len=2 [2]で終端文字が現れるため

    // 逆に終端文字がない場合、Cのランタイムからすると文字列の終わりが分からないという
    // 状態になる。脆弱性が生まれる部分でもあるので、気をつけないといけない
    // C では、他の言語にあるような バウンスチェック が一切ない
    s1[2] = 'l';
    s1[5] = 'z';

    len = strnlen(s1, 10);
    printf("[strnlen] len=%d\n", (int) len); // lenの値は 6 以上 10 以下 となる

    return EXIT_SUCCESS;
}
