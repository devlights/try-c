#include <stdio.h>
#include "examples.h"

int main() {
    printf("||||||||||||||||| start |||||||||||||||||\n");

    /* ------------------------------------------------
     * 00.HelloWorld
     * ------------------------------------------------ */
    do_it(basic_hello_world01, "hello world");

    /* ------------------------------------------------
     * 10.For Loop
     * ------------------------------------------------ */
    do_it(basic_for_loop01, "For Loop");

    /* ------------------------------------------------
     * 20.Char Array
     * ------------------------------------------------ */
    do_it(basic_char_array01, "Char Array (initialize)");
    do_it(basic_char_array02, "Char Array (memset, strncpy)");
    do_it(basic_char_array03, "Char Array (strncat)");
    do_it(basic_char_array04, "Char Array (strlen)");

    /* ------------------------------------------------
     * 99.Misc
     * ------------------------------------------------ */
    do_it(basic_detect_c_lang_version, "Detect C Lang Version");

    printf("|||||||||||||||||  end  |||||||||||||||||\n");

    return 0;
}

