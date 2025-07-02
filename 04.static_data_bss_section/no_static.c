#include <stdio.h>
#include <string.h>

#define BUFSIZE (3 * 1024 * 1024)

int main(void) {
    char  buf[BUFSIZE] = {1};
    FILE *fp           = fopen("/dev/null", "w");
    
    for (size_t i = 0; i < BUFSIZE; i++) {
        fwrite(&buf[i], 1, 1, fp);
    }

    fclose(fp);

    return 0;
}