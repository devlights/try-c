#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static int open_tmp(FILE **fp, bool call_unlink);
static int write_to(FILE *fp, const char *data, size_t data_size, size_t *write_size);
static int read_from(FILE *fp, char *buf, size_t buf_size, size_t *data_size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        exit(EXIT_FAILURE);
    }

    // OPEN
    FILE *fp;
    {
        if (open_tmp(&fp, (atoi(argv[argc-1]) != 0) ? true : false) == -1) {
            perror("open_tmp");
            return EXIT_FAILURE;
        }
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

static int open_tmp(FILE **fp, bool call_unlink) {
    //
    // tmpfile(3)のようにプロセスが実行中のみ存在するファイルを手作業で作成
    //
    // (1) open(2)でファイルを作成
    // (2) 即座にunlink(2)を呼び出してディレクトリエントリ（リンク）を削除。
    //     ファイルディスクリプタが開いている間はファイルの実体は残り、
    //     アクセス可能。fclose()でファイルディスクリプタがクローズされると
    //     リンクカウントが0のため、カーネルによってファイルの実体が削除される。
    // (3) fdopen(3)で (FILE *) を得る
    //
    const char *path = "out.txt";
    int         fd   = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        return -1;
    }

    if (call_unlink) {
        if (unlink(path) == -1) {
            close(fd);
            return -1;
        }
    }

    //
    // fdopen(3) は、POSIXの拡張機能であるため、コンパイル時に -std=c11 のように
    // 厳密なC標準モードにすると見えなくなってしまう。
    // 以下のように Feature Test Macro を利用するか、コンパイル時のフラグを変更する。
    //
    //     #define _POSIX_C_SOURCE 200809L
    //
    // または
    //
    //     -std=gnu11
    //
    // とする。gnu11 は、c11にGNU/POSIX拡張を含めたモード。
    //
    *fp = fdopen(fd, "wb+");
    if (*fp == NULL) {
        close(fd);
        return -1;
    }

    return 0;
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