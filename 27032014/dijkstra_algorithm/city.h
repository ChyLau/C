#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

typedef struct city City_struct;

struct city {
char *name;
Road *roads;
City_struct *next;
};

City_struct *new_city(char *name);
void delete_city(City_struct *city);
City_struct *find_city(City_struct *map, char *name);
#endif // CITY_H_INCLUDED
