#include "minunit.h"
#include <lcthw/map.h>
#include <assert.h>

static City *city = NULL;
char *name = "test1";

char *test_new()
{
    city = City_new(name);
    mu_assert(city != NULL, "Failed to create city.");
    mu_assert(city->name == name, "Wrong city name.");
    mu_assert(city->next == NULL, "next has a value != NULL.");
    mu_assert(city->prev == NULL, "prev has a value != NULL.");

    return NULL;
}

char *test_delete()
{
    City_delete(city);

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_new);
    mu_run_test(test_delete);

    return NULL;
}

RUN_TESTS(all_tests);
