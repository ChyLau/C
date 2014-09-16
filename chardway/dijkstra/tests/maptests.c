#include "minunit.h"
#include <lcthw/map.h>
#include <assert.h>

char *test_city_number()
{
    int rc = City_number_2();
    mu_assert(rc != 0, "Failed to read data file.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_city_number);

    return NULL;
}

RUN_TESTS(all_tests);
