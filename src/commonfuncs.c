#include <stdio.h>
#include "examples.h"

int     example_count = 0;
example examples[MAX_EXAMPLE_COUNT];

void make_mappings() {

    for (int i = 0; i < MAX_EXAMPLE_COUNT; i++) {
        examples[i] = (example) {"end", NULL};
    }

    /*
     * basic
     */
    int index = 0;
    examples[index++] = (example) {"basic_helloworld", basic_helloworld01};
    examples[index++] = (example) {"basic_chararray_01", basic_char_array01};
    examples[index++] = (example) {"basic_chararray_02", basic_char_array02};
    examples[index++] = (example) {"basic_chararray_03", basic_char_array03};
    examples[index++] = (example) {"basic_chararray_04", basic_char_array04};
    examples[index++] = (example) {"basic_forloop_01", basic_for_loop01};
    examples[index++] = (example) {"basic_detect_c_version", basic_detect_c_lang_version};
    examples[index++] = (example) {"basic_printf_series", basic_printf_series};

    example_count = index;
}