#include <stdio.h>

void do_it(void (*func)(), char *message) {
    printf("[START] ------- %s -------\n", message);
    func();
    printf("[ END ] ------- %s -------\n", message);
}
