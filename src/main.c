#include <stdio.h>
#include "commonfuncs.h"
#include "helloworld.h"
#include "forloop.h"
#include "chararray.h"

int main() {
    printf("||||||||||||||||| start |||||||||||||||||\n");

    /* ------------------------------------------------
     * 01.HelloWorld
     * ------------------------------------------------ */
    do_it(hello_world01, "hello world");

    /* ------------------------------------------------
     * 02.For Loop
     * ------------------------------------------------ */
    do_it(for_loop01, "For Loop");

    /* ------------------------------------------------
     * 03.Char Array
     * ------------------------------------------------ */
    do_it(char_array01, "Char Array (initialize)");
    do_it(char_array02, "Char Array (memset)");

    printf("|||||||||||||||||  end  |||||||||||||||||\n");

    return 0;
}

