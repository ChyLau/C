#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
static City *city = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";


char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}

char *test_destroy()
{
    List_destroy(list);

    return NULL;
}

char *test_push()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value.");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");

    return NULL;
}

char *test_find()
{
    city = City_find(list, test1);
    mu_assert(city != NULL, "Failed to find city.");

    city = City_find(list, test2);
    mu_assert(city != NULL, "Failed to find city.");

    city = City_find(list, test2);
    mu_assert(city != NULL, "Failed to find city.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push);
    mu_run_test(test_find);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
