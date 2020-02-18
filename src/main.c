#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "examples.h"

static void show_example_names();

static void show_help();

int main() {

    make_mappings();

    for (;;) {
        char buffer[256] = "";

        // 最大で255文字まで読み取って残りは読み飛ばす
        printf("ENTER INPUT NAME: ");
        if (scanf("%255[^\n]%*[^\n]", buffer) == EOF) {
            return 1;
        }
        scanf("%*c"); // 残った改行を読み飛ばす

        printf("[INPUT] %s\n", buffer);

        size_t len = strlen(buffer);
        if (strlen(buffer) == 0) {
            continue;
        }

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        if (strncmp(buffer, "list", 4) == 0) {
            show_example_names();
            continue;
        }

        if (strncmp(buffer, "help", 4) == 0) {
            show_help();
            continue;
        }

        int found = false;
        for (int i = 0; i < example_count; i++) {
            example e = examples[i];
            if (strncmp(e.name, buffer, len) == 0) {
                printf("===== [%s] =====\n", e.name);
                e.func();
                printf("===== [%s] =====\n\n", e.name);

                found = true;
                break;
            }
        }

        if (found == true) {
            break;
        } else {
            printf("not found...try again\n");
            continue;
        }
    }

    printf("DONE\n");

    return 0;
}

void show_help() {
    printf("list -- show all example names\n");
    printf("quit -- exit program\n");
}

void show_example_names() {
    for (int i = 0; i < example_count; i++) {
        example e = examples[i];
        printf("%s\n", e.name);
    }
}

