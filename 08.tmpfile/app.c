#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int write_to(FILE *fp, const char *data, size_t data_size, size_t *write_size);
static int read_from(FILE *fp, char *buf, size_t buf_size, size_t *data_size);

int main(void) {
    //
    // tmpfile(3) は、ユニークな一時ファイルをオープンして (FILE *) で返してくれる。
    // モードは wb+ が指定された状態。読み書き可能な状態となっている。
    //
    // このファイルはクローズ時またはプログラム終了時に自動的に削除される。
    //

    // OPEN
    FILE *fp = tmpfile();
    if (fp == NULL) {
        perror("tmpfile");
        exit(EXIT_FAILURE);
    }

    // WRITE
    const char *data       = "helloworld";
    size_t      data_len   = strlen(data) + 1; // null終端含む
    size_t      write_size = 0;
    {
        if (write_to(fp, data, data_len, &write_size) != 0) {
            fclose(fp);

            perror("write_to");
            exit(EXIT_FAILURE);
        }
    }

    // SEEK_SET 0
    rewind(fp);

    // READ
    char   buf[1024] = {0};
    size_t buf_size  = sizeof(buf);
    size_t read_size = 0;
    {
        if (read_from(fp, buf, buf_size, &read_size) != 0) {
            fclose(fp);

            perror("read_from");
            exit(EXIT_FAILURE);
        }
    }
    printf("buf: %s (W:%zu, R:%zu)\n", buf, write_size, read_size);

    // CLOSE
    if (fclose(fp) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

static int write_to(FILE *fp, const char *data, size_t data_size, size_t *write_size) {
    *write_size = fwrite(data, 1, data_size, fp);

    if (*write_size != data_size) {
        return -1;
    }

    return 0;
}

static int read_from(FILE *fp, char *buf, size_t buf_size, size_t *read_size) {
    *read_size = fread(buf, 1, buf_size, fp);

    // freadが0を返した場合、エラーかEOFかを判定
    // freadが0を返すパターンは以下の２つ。
    //
    // - EOF (feof(3))
    // - エラー発生 (ferror(3))
    //
    if (*read_size == 0 && ferror(fp)) {
        return -1;
    }

    return 0;
}