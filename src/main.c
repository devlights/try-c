#include <stdio.h>
#include "commonfuncs.h"
#include "helloworld.h"
#include "forloop.h"

int main() {
    printf("||||||||||||||||| start |||||||||||||||||\n");

    /* ------------------------------------------------
     * 01.HelloWorld
     * ------------------------------------------------ */
    do_it(hello_world, "hello world");

    /* ------------------------------------------------
     * 02.For Loop
     * ------------------------------------------------ */
    do_it(for_loop, "For Loop");

    printf("|||||||||||||||||  end  |||||||||||||||||\n");

    return 0;
}

