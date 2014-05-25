#include <stdlib.h>
#include "road.h"

Road_struct *new_road(City_struct *destination, City_struct *origin, unsigned length)
{
    Road_struct *road = malloc(sizeof(Road_struct));
    road->destination = destination;
    road->origin = origin;
    road->length = length;
    road->next = NULL;
}

void delete_roads(Road_struct *road)
{
    if(road != 0)
    {
        free(road);
    }

}
