#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

typedef struct road Road_struct;

struct road {
City_struct *destination;
City_struct *origin;
unsigned length;
Road_struct *next;
};

Road_struct *new_road(City_struct *destination,
                      City_struct *origin,
                      unsigned length);
void delete_roads(Road_struct *road);
#endif // ROAD_H_INCLUDED
