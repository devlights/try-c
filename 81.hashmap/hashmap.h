#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

// ハッシュマップのエントリ
typedef struct HashMapEntry {
    char *key;
    void *value;
    struct HashMapEntry *next;
} HashMapEntry;

// ハッシュマップの構造体
typedef struct HashMap {
    size_t size;            // テーブルのサイズ
    size_t count;           // 現在のエントリ数
    HashMapEntry **buckets; // バケット配列
} HashMap;

// ハッシュマップの作成
HashMap* hashmap_create(size_t size);

// ハッシュマップの破棄
void hashmap_destroy(HashMap *map);

// キーと値の挿入または更新
int hashmap_put(HashMap *map, const char *key, void *value);

// キーに対応する値の取得
void* hashmap_get(HashMap *map, const char *key);

// キーに対応するエントリの削除
int hashmap_remove(HashMap *map, const char *key);

#endif // HASHMAP_H