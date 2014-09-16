#include <lcthw/map.h>
#include <lcthw/dbg.h>
#include <ctype.h>

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
Map *City_number_2()
{
    int num = 0;
    int i = 0;

    FILE *file = NULL;
    file = fopen(DATA_FILE, "r");
    check(file, "Failed to open database: %s", DATA_FILE);

    int rc = fscanf(file, "%d", &num);
    log_info("Number of cities: %d", num);
    log_info("Return value fscanf: %d", rc);

    for(i = 0; i < num; i++)
    {
        char city_name[MAX_LENGTH];

    }

    fclose(file);

    return num;
error:
    if(file)
        fclose(file);
    return 0;
}

int City_number()
{
    FILE *file = NULL;
    char c;

    file = fopen(DATA_FILE, "r");
    check(file, "Failed to open database: %s", DATA_FILE);

    c = fgetc(file);
    check(isdigit(c) != 0, "Read char is not a digit.");
    int i = c - '0';

    log_info("Number of cities: %d", i);
    fclose(file);

    return i;

error:
    if(file)
        fclose(file);
    return 0;
}
