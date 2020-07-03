// ------------------------------------------------------
// ヘッダーファイルのインクルードについて
//
// include の際に <stdio.h> のように < と > で囲むものは「標準ディレクトリ」から検索される。
// include の際に "hoge.h" のように "" で囲むものは ユーザ定義のヘッダファイルを表す。
//   --> まず、ソースファイルと同じ場所が検索され、なければ標準ディレクトリから検索される.
//   --> 独自の場所に ヘッダーファイル　を置いている場合はコンパイラに教える必要がある.
//       --> cmake の場合は、 target_include_directories() で指定する
// ------------------------------------------------------

// このヘッダーファイルは、標準ヘッダーファイルなので、何もしなくても最初から見えている。
// CMakeLists.txt でも特に設定しなくても見えている。
#include <stdio.h>
#include <stdlib.h>

// このヘッダーファイルは、ソースファイルと同一ディレクトリにあるので、何もしなくてもサーチパスに入っている。
// CMakeLists.txt でも特に設定しなくても見えている。
#include "header1.h"

// このヘッダーファイルは include の下にあるが、CMakeLists.txt にて target_include_directories(${PROJECT_NAME} PRIVATE include)
// と指定しているので、ヘッダーファイルの検索パスに include ディレクトリが含まれた状態となっている。
// なので、直接 header2.h と記述できる.
#include "header2.h"

// このヘッダーファイルは include2 の下にあるが、CMakeLists.txt にて target_include_directories には含めていない。
// なので、ヘッダファイルの場所を相対パスで指定する必要がある。
#include "include2/header3.h"

int main(void) {
    printf("stdio.h は、標準ディレクトリ /usr/include の下にある\n");

    point1 p = {
            .x = 1,
            .y = 2
    };

    printf("[point1] x=%d\ty=%d\n", p.x, p.y);

    point2 p2 = {
            .x = 3,
            .y = 4
    };

    printf("[point2] x=%d\ty=%d\n", p2.x, p2.y);

    point3 p3 = {
            .x = 5,
            .y = 6
    };

    printf("[point3] x=%d\ty=%d\n", p3.x, p3.y);

    return EXIT_SUCCESS;
}
