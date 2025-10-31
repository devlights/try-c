#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // OPEN (エラー処理は割愛)
    FILE *fp = tmpfile();

    // WRITE (エラー処理は割愛)
    const char msg[] = "helloworld";
    size_t msg_size = sizeof(msg);
    fwrite(msg, 1, msg_size, fp);

    // rewind(3)
    // 
    // 以下、man 3 rewind より引用
    // 
    // > rewind()  関数は stream によって指定されたストリームにおいて、ファイル位置表示子 をファイルの先頭にセットする。この関数は以下と等価である。
    // > (void) fseek(stream, 0L, SEEK_SET)
    // > ただし rewind()  ではストリームに対するエラー表示子 (error indicator) も同時に クリアされる
    //
    // オフセットを先頭に戻す
    rewind(fp);

    // READ (エラー処理は割愛)
    char buf[msg_size];
    memset(buf, 0, msg_size);
    fread(buf, 1, msg_size, fp);
    buf[msg_size - 1] = '\0';

    printf("%s\n", buf);

    fclose(fp);

    return EXIT_SUCCESS;
}