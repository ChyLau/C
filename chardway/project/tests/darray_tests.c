#include "minunit.h"
#include <lcthw/darray.h>

static DArray *array = NULL;

char *test_create()
{
    array = DArray_create(sizeof(int), 100);
    mu_assert(array != NULL, "Failed to create array");
    mu_assert(array->contents != NULL, "contents wrong in darray");
    mu_assert(array->max == 100, "initial_max is wrong");
    mu_assert(array->end == 0, "end is wrong");
    mu_assert(array->element_size == sizeof(int), "element_size wrong");
    mu_assert(array->expand_rate == DEFAULT_EXPAND_RATE, "expand_rate is wrong");

    return NULL;
}

char *test_clear()
{
    DArray_clear(array);

    return NULL;
}

char *test_destroy()
{
    DArray_destroy(array);

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_clear);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
