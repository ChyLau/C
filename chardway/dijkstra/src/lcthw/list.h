#ifndef _lcthw_list_h
#define _lcthw_list_h

#include <lcthw/dbg.h>
#include <stdlib.h>

#define DB_FILE "bin/data"
#define MAX_LENGTH 512

struct City;
struct Road;

typedef struct City {
    char *name;
    struct City *next;
    struct City *prev;
    struct Road *roads;
} City;

typedef struct List {
    City *first;
    City *last;
    int count;
} List;


typedef struct Road {
    City *origin;
    City *destination;
    unsigned length;
    struct Road *next;
} Road;


List *List_create();
void List_destroy(List *list);
void List_push(List *list, char *name);
List *List_city(List *list);
void List_print(List *list);
Road *Road_create(City *origin, City *destination, unsigned length);


#define List_last(A) ((A)->last != NULL ? (A)->last->name : NULL)
#define List_first(A) ((A)->first != NULL ? (A)->first->name : NULL)

#define LIST_FOREACH(L, S, M, V) City *_city = NULL;\
    City *V = NULL;\
    for(V = _city = L->S; _city != NULL; V = _city = _city->M)

#endif
