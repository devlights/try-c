# これは何？

C言語でのstatic変数や大容量バッファを扱う際に重要な、.dataセクションと.bssセクションの違いについてのサンプルです。

## .dataセクション

初期化済みグローバル変数・static変数が格納される領域

```c
// .dataセクションに配置される例
static int initialized_value = 42;
static char message[] = "Hello World";
static char buffer[1024] = {0x01, 0x02, 0x03};  // 明示的初期化
static char large_buffer[10 * 1024 * 1024] = {1}; // 10MBすべて1で初期化
```

- 実行ファイル内に初期値データが埋め込まれる
- プログラム起動時にディスクから初期値をメモリに読み込み
- 実行ファイルサイズが初期化データ分だけ増大
- 起動時にディスクI/Oが発生

## .bssセクション

未初期化または0初期化されたグローバル変数・static変数が格納される領域

```c
// .bssセクションに配置される例
static int uninitialized_value;           // 未初期化
static char buffer[10 * 1024 * 1024];     // 未初期化
static int zero_value = 0;                // 0初期化（コンパイラ最適化）
static char zero_buffer[1024] = {0};      // 0初期化（最適化される）
```

- 実行ファイルにはデータが埋め込まれない
- プログラム起動時にOSが自動的に0でクリア
- 実行ファイルサイズ増加なし
- 起動時のディスクI/O最小限

## 実行結果

```sh
$ task
task: [size] size no_static local_static global_static_with_init global_static_no_init
   text    data     bss     dec     hex filename
   1670     608       8    2286     8ee no_static
   1541 3146328       8 3147877  300865 local_static
   1541 3146328       8 3147877  300865 global_static_with_init
   1636     608 3145744 3147988  3008d4 global_static_no_init
task: [size] ls -lh no_static local_static global_static_with_init global_static_no_init | awk '{print $5,$9}'
16K global_static_no_init
3.1M global_static_with_init
3.1M local_static
16K no_static
```
