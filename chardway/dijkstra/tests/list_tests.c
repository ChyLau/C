#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
static Road *road = NULL;
/*static City *city = NULL;*/
char *test1 = "A";
char *test2 = "B";
char *test3 = "C";


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

char *test_read()
{
    List_city(list);
    mu_assert(list->count == 3, "Wrong count.");
    log_info("test1 length: %zu", strlen(test1));
    log_info("test2 length: %zu", strlen(test2));
    log_info("test3 length: %zu", strlen(test3));
    return NULL;
}

char *test_push()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");
    mu_assert(list->count == 1, "Wrong count.");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value.");
    mu_assert(list->count == 2, "Wrong count.");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    mu_assert(list->count == 3, "Wrong count.");

    List_push(list, test3);

    return NULL;
}

char *test_road_create()
{
    road = Road_create()

    return NULL;
}

/*
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
*/

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_read);
    //mu_run_test(test_push);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
