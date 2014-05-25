#include <stdlib.h>
#include "city.h"

City_struct *new_city(char *name)
{
    City_struct *city = malloc(sizeof(City_struct));
    city->name = name;
    city->roads = NULL;
    city->next = NULL;

    return city;
}

void delete_city(City_struct *city)
{
    if(city != 0)
    {
    //delete_roads(city->roads);
    free(city->name);
    free(city);
    }
}
