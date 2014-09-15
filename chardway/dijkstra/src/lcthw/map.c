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
    {
        free(city);
    }
    return NULL;
}

void City_delete(City *city)
{
    if(city)
    {
        free(city);
    }
}

/*
City *City_find(City *map, char *name)
{

    return city;
}
*/

Map *Map_create()
{
    FILE *data = NULL;

    data = fopen(DATA_FILE, "r");
    check(data, "Failed to open database: %s", DATA_FILE);

    fclose(data);

    /*
     * Still need to retreive data from file and link the cities together.
     */
    return map;
}
