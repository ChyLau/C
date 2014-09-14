#include <lcthw/city.h>
#include <lcthw/dbg.h>

City *City_new(char *name)
{
    City *city = malloc(sizeof(City));
    check_mem(city);

    city->name = name;
    check(city->name != NULL, "Name of city can't be NULL.");

    city->next = NULL;
    city->prev = NULL;

    return city;

error:
    if(city)
        free(city->name);
    free(city);
    return NULL;
}

void City_delete(City *city)
{
    log_info("Entering City_delete function.");
    if(city)
    {
        log_info("Entering if-statement.");
        free(city->name);
        free(city);
    }
}
