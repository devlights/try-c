#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 1000;
  int y = 2000;

  int *px = &x;
  int *py = &y;

  printf("x + y = %d\n", *px + *py);

  // 不正なポインタ演算
  // アドレスを足しているので変数の範囲外のメモリを示すようになる
  px += 3;
  py += 3;

  printf("x + y = %d\n", *px + *py);

  return EXIT_SUCCESS;
}