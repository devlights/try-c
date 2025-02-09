#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LOAD_FACTOR_THRESHOLD 0.75

/*
strdup 関数は POSIX標準 の一部であり、C標準ライブラリ（C89/C99/C11/C17など） には含まれていません。
そのため、C17標準 でコンパイルする場合、strdup を使用すると宣言されていない関数として認識され、暗黙の宣言エラーが発生します。
なので、strdup の機能を自前で実装し、標準的なC関数として使用します。
*/
static char* strdup_custom(const char *s) {
    if (s == NULL) return NULL;
    size_t len = strlen(s) + 1;
    char *dup = malloc(len);
    if (dup) {
        memcpy(dup, s, len);
    }
    return dup;
}

/*
djb2ハッシュ関数

djb2ハッシュ関数の特徴
- Daniel J. Bernstein (djb) によって考案された非暗号学的ハッシュ関数です。
- シンプルな実装でありながら、効果的なハッシュ値生成能力を持っています。
- 文字列のハッシュ化に特に適しており、ハッシュテーブルのインデックス計算などで広く使用されています。

djb2の利点
- 高速な計算: シンプルな演算のみを使用しているため、計算速度が非常に速いです。
- 良好な分散: 入力の小さな変化に対して出力が大きく変化するため、ハッシュ値の分散が良好です。
- 実装の容易さ: アルゴリズムがシンプルなため、実装が簡単です

djb2ハッシュ関数は以下のような場面で使用されます：
- ハッシュテーブルのインデックス計算
- 簡易的なチェックサム生成
- データ構造での高速な文字列比較
*/
static unsigned long hash_function(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

// ハッシュマップの作成
HashMap* hashmap_create(size_t size) {
    if (size == 0) return NULL;

    HashMap *map = malloc(sizeof(HashMap));
    if (!map) return NULL;

    map->size = size;
    map->count = 0;
    map->buckets = calloc(map->size, sizeof(HashMapEntry*));
    if (!map->buckets) {
        free(map);
        return NULL;
    }

    return map;
}

// ハッシュマップの破棄
void hashmap_destroy(HashMap *map) {
    if (!map) return;

    for (size_t i = 0; i < map->size; i++) {
        HashMapEntry *entry = map->buckets[i];
        while (entry) {
            HashMapEntry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp->value); // 値のメモリも解放
            free(temp);
        }
    }

    free(map->buckets);
    free(map);
}

// ハッシュマップのリサイズ
static int hashmap_resize(HashMap *map, size_t new_size) {
    HashMapEntry **new_buckets = calloc(new_size, sizeof(HashMapEntry*));
    if (!new_buckets) return -1;

    // 再ハッシュ
    for (size_t i = 0; i < map->size; i++) {
        HashMapEntry *entry = map->buckets[i];
        while (entry) {
            HashMapEntry *next_entry = entry->next;

            unsigned long hash = hash_function(entry->key);
            size_t index = hash % new_size;

            // 挿入先バケットの先頭に追加
            entry->next = new_buckets[index];
            new_buckets[index] = entry;

            entry = next_entry;
        }
    }

    free(map->buckets);
    map->buckets = new_buckets;
    map->size = new_size;

    return 0;
}

// キーと値の挿入または更新
int hashmap_put(HashMap *map, const char *key, void *value) {
    if (!map || !key) return -1;

    // ロードファクターのチェック
    double load_factor = (double)(map->count + 1) / map->size;
    if (load_factor > LOAD_FACTOR_THRESHOLD) {
        if (hashmap_resize(map, map->size * 2) != 0) {
            return -1; // リサイズ失敗
        }
    }

    unsigned long hash = hash_function(key);
    size_t index = hash % map->size;

    HashMapEntry *entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value; // 更新
            return 0;
        }
        entry = entry->next;
    }

    // 新規エントリの作成
    HashMapEntry *new_entry = malloc(sizeof(HashMapEntry));
    if (!new_entry) return -1;

    new_entry->key = strdup_custom(key);
    if (!new_entry->key) {
        free(new_entry);
        return -1;
    }
    new_entry->value = value;
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
    map->count++;

    return 0;
}

// キーに対応する値の取得
void* hashmap_get(HashMap *map, const char *key) {
    if (!map || !key) return NULL;

    unsigned long hash = hash_function(key);
    size_t index = hash % map->size;

    HashMapEntry *entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }

    return NULL; // 見つからない場合
}

// キーに対応するエントリの削除
int hashmap_remove(HashMap *map, const char *key) {
    if (!map || !key) return -1;

    unsigned long hash = hash_function(key);
    size_t index = hash % map->size;

    HashMapEntry *entry = map->buckets[index];
    HashMapEntry *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                map->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry->value); // 値のメモリを解放
            free(entry);
            map->count--;
            return 0;
        }
        prev = entry;
        entry = entry->next;
    }

    return -1; // 見つからない場合
}