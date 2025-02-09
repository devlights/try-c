#include <stdio.h>
#include <stdlib.h>

// 関数ローカル内で宣言したポインタを返す関数（これをしては駄目）
// 以下の警告がでる
//    > Address of stack memory associated with local variable 'z' returned
//    (clang(-Wreturn-stack-address))
int *wrong_func(int x, int y) {
  int z = x + y;
  return &z;
}

void collect_func(int x, int y, int *z) { *z = x + y; }

int main() {
  int *z = wrong_func(10, 20);
  printf("%d\n", *z);

  // そのままprintfで出力するだけなら、値が表示できる場合がある
  // が、その間に処理を挟んでやるとおかしな値となる
  // これは wrong_func() の処理を終えた後に他の関数呼び出しなどにより
  // メモリが上書きされてしまうため。
  printf("hello world\n");
  printf("%d\n", *z);

  // 通常は、OUT用の変数を受け取るようになどして処理する
  int z2;
  collect_func(10, 20, &z2);
  printf("%d\n", z2);

  return EXIT_SUCCESS;
}