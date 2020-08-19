#include <stdio.h>
#include <stdlib.h>
#include <byteswap.h>

void nouse_bswap(void);
void use_bswap(void);

int main(void) {
    // ------------------------------------------------
    // エンディアン変換のサンプル
    // ------------------------------------------------

    // ライブラリ関数を利用しないバージョン
    nouse_bswap();

    printf("%s\n", "-----------------------------------------------");

    // ライブラリ関数を利用するバージョン
    use_bswap();

    return EXIT_SUCCESS;
}

void nouse_bswap(void) {
    u_int32_t i = 0x08040201;
    u_int32_t r;

    char *little = (char*) &i;
    char *big    = (char*) &r;

    // ビッグエンディアンに入れ替え
    big[0] = little[3];
    big[1] = little[2];
    big[2] = little[1];
    big[3] = little[0];

    printf("[Original     ] %#08x\n", i);
    printf("[Little Endian] %02x %02x %02x %02x\n", little[0], little[1], little[2], little[3]);
    printf("[Big    Endian] %02x %02x %02x %02x\n", big[0], big[1], big[2], big[3]);
}

void use_bswap(void) {
    u_int32_t i = 0x08040201;
    u_int32_t r;

    r = bswap_32(i);
    
    char *little = (char*) &i;
    char *big    = (char*) &r;

    printf("[Original     ] %#08x\n", i);
    printf("[Little Endian] %02x %02x %02x %02x\n", little[0], little[1], little[2], little[3]);
    printf("[Big    Endian] %02x %02x %02x %02x\n", big[0], big[1], big[2], big[3]);
}

