#include <stdio.h>
#include <string.h>

#define BUFSIZE (3 * 1024 * 1024)

static char buf[BUFSIZE];

int main(void) {
    FILE *fp = fopen("/dev/null", "w");

    memset(buf, 1, sizeof(buf));

    for (size_t i = 0; i < BUFSIZE; i++) {
        fwrite(&buf[i], 1, 1, fp);
    }

    fclose(fp);

    return 0;
}