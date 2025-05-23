#include <stdio.h>
#include <stdlib.h>

enum LAN {
    LAN_A,
    LAN_B,
    LAN_COUNT,
};

void print_lan(const char *lans[]);

int main(void) {
    printf("%d:%d:%d\n", LAN_A, LAN_B, LAN_COUNT);

    const char *lans[LAN_COUNT];
    {
        lans[LAN_A] = "192.168.149.1";
        lans[LAN_B] = "10.111.222.1";
    }
    print_lan(lans);

    return EXIT_SUCCESS;
}

void print_lan(const char *lans[]) {
    for (int i = 0; i < LAN_COUNT; i++) {
        printf("[%d]=%s\n", i, lans[i]);
    }
}
