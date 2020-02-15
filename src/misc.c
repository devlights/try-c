#include <stdio.h>

void detect_c_lang_version() {
    // 自分が使うコンパイラが、どのバージョンに対応しているのかを確認できる
    //
    // __STDC_VERSION__ の値が
    //     201112: C11 対応
    //     199901: C99 対応
    //     コンパイルエラー： C99 未満
    //
    printf("C LANG VER: %ld\n", __STDC_VERSION__);
}
