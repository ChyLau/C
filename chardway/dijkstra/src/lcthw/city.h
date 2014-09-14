#ifndef _lcthw_City_h
#define _lcthw_City_h

#include <lcthw/dbg.h>

struct City;

typedef struct City {
    char *name;
    struct City *next;
    struct City *prev;
    /*Road *roads;*/
} City;

City *City_new(char *name);
void City_delete(City *city);
City *City_find(City *map, char *name);

#endif
