#ifndef _lcthw_map_h
#define _lcthw_map_h

#include <lcthw/dbg.h>
#include <stdlib.h>

#define DATA_FILE "bin/data"
#define MAX_LENGTH 512

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
int City_number();
int City_number_2();

#endif
