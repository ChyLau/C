#ifndef _lcthw_City_h
#define _lcthw_City_h

#include <lcthw/dbg.h>
#include <stdlib.h>

struct City;

typedef struct City {
    char *name;
    struct City *next;
    struct City *prev;
    /*Road *roads;*/
} City;

typedef struct Map {
    City *first;
    City *last;
    int count;
} Map;

City *City_new(char *name);
void City_delete(City *city);
City *City_find(City *map, char *name);

#endif
