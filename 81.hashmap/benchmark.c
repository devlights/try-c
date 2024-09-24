#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ENTRIES 1000000    // 挿入するエントリ数
#define INITIAL_MAP_SIZE 1<<12 // ハッシュマップの初期サイズ
#define KEY_SIZE 20            // キーのサイズ

// キーを生成
void generate_key(char *key, int index) {
    snprintf(key, KEY_SIZE, "key_%d", index);
}

int main() {
    // ベンチマーク用変数
    clock_t start, end;
    double insert_time, search_time, delete_time;

    // ハッシュマップの作成
    HashMap *map = hashmap_create(INITIAL_MAP_SIZE);
    if (!map) {
        fprintf(stderr, "ハッシュマップの作成に失敗しました。\n");
        return 1;
    }

    // 挿入テスト
    start = clock();
    for (int i = 0; i < NUM_ENTRIES; i++) {
        char key[KEY_SIZE];
        generate_key(key, i);
        int *value = malloc(sizeof(int));
        if (!value) {
            fprintf(stderr, "メモリ割り当てに失敗しました。\n");
            hashmap_destroy(map);
            return 1;
        }
        *value = i;
        if (hashmap_put(map, key, value) != 0) {
            fprintf(stderr, "エントリの挿入に失敗しました。\n");
            free(value);
            hashmap_destroy(map);
            return 1;
        }
    }
    end = clock();
    insert_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("挿入時間: %.6f 秒 (%d) \n", insert_time, NUM_ENTRIES);

    // 検索テスト
    start = clock();
    int found = 0;
    for (int i = 0; i < NUM_ENTRIES; i++) {
        char key[KEY_SIZE];
        generate_key(key, i);
        int *value = hashmap_get(map, key);
        if (value) {
            found++;
        }
    }
    end = clock();
    search_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("検索時間: %.6f 秒 (%d/%d 見つかりました)\n", search_time, found, NUM_ENTRIES);

    // 削除テスト
    start = clock();
    int deleted = 0;
    for (int i = 0; i < NUM_ENTRIES; i++) {
        char key[KEY_SIZE];
        generate_key(key, i);
        if (hashmap_remove(map, key) == 0) { // 修正済みの関数を使用
            deleted++;
        }
    }
    end = clock();
    delete_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("削除時間: %.6f 秒 (%d/%d 削除されました)\n", delete_time, deleted, NUM_ENTRIES);

    // ハッシュマップの破棄
    hashmap_destroy(map);

    return 0;
}