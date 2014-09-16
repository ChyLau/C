#include "minunit.h"
#include <lcthw/map.h>
#include <assert.h>

char *test_map_load()
{
    int rc = Map_load();
    mu_assert(rc == 0, "Failed to read data file.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_map_load);

    return NULL;
}

RUN_TESTS(all_tests);
