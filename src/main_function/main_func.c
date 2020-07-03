#include <stdio.h>
#include <stdlib.h>

// main_function -- main 関数のサンプルです.
//
// REFERENCES:
//   - https://qiita.com/raccy/items/b59bd7fa9f4eacabca79
//   - http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
int main(void) {
    // C言語 において 現状の最新仕様 C11 で有効な main 関数の書式は
    //
    // - int main(void)
    // - int main(int argc, char *argv[])
    // - int main(int args, char **argv)
    //
    // のどれかとならなけばいけない。
    printf("有効な main 関数は\n");
    printf("\tint main(void)\n");
    printf("\tint main(int argc, char *argv[])\n");
    printf("\tint main(int argc, char **argv)\n");
    printf("のどれかで無いといけない");

    return EXIT_SUCCESS;
}

