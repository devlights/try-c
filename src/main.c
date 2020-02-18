#include <stdio.h>
#include <string.h>
#include "examples.h"

int main() {

    for(;;) {
        char buffer[256] = "";

        // 最大で255文字まで読み取って残りは読み飛ばす
        printf("ENTER INPUT NAME: ");
        if (scanf("%255[^\n]%*[^\n]", buffer) == EOF) {
            return 1;
        }
        scanf("%*c"); // 残った改行を読み飛ばす

        printf("[INPUT] %s\n", buffer);
        if (strlen(buffer) == 0) {
            continue;
        }

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        printf("||||||||||||||||| start |||||||||||||||||\n");
        // do_it(basic_hello_world01, "hello world");
        printf("|||||||||||||||||  end  |||||||||||||||||\n");
    }

    printf("DONE\n");

    return 0;
}

