#ifndef TRY_C_EXAMPLES_H
#define TRY_C_EXAMPLES_H

/*
 * define
 */
#define MAX_EXAMPLE_COUNT 1000

/*
 * consts
 */

/*
 * structs
 */
typedef struct example {
    char name[50];

    void (*func)();
} example;

/*
 * data
 */
extern int     example_count;
extern example examples[MAX_EXAMPLE_COUNT];

/*
 * common
 */
void make_mappings();

/*
 * basic
 */
void basic_helloworld01();

void basic_char_array01();

void basic_char_array02();

void basic_char_array03();

void basic_char_array04();

void basic_for_loop01();

void basic_detect_c_lang_version();

void basic_stdout_series();

void basic_stdin_series();

#endif //TRY_C_EXAMPLES_H