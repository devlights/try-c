#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH (32)
#define LIST_COUNT (10)

typedef struct {
    char    key[KEY_LENGTH];
    int32_t value;
} Data;

static Data data_list[LIST_COUNT];

static void init_data_list(void);
static void print_item(const Data *item);

int main(void) {
    init_data_list();

    Data     *first = data_list;                // 先頭要素へのポインタ
    Data     *last  = first + (LIST_COUNT - 1); // 最終要素へのポインタ
    ptrdiff_t count = last - first + 1;         // ポインタ同士を引くことで要素数を取得できる

    print_item(first);
    print_item(last);
    printf("count: %ld\n", count);

    return EXIT_SUCCESS;
}

static void init_data_list(void) {
    for (size_t i = 0; i < LIST_COUNT; i++) {
        Data *item = &data_list[i];

        snprintf(item->key, KEY_LENGTH, "key-%02ld", i);
        item->value = i;
    }
}

static void print_item(const Data *item) {
    printf("key: %s, value: %d\n", item->key, item->value);
}
