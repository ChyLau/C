#ifndef _lcthw_list_h
#define _lcthw_list_h

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

typedef struct List {
    City *first;
    City *last;
    int count;
} List;


List *List_create();
void List_destroy(List *list);
void List_push(List *list, char *name);
City *City_find(List *list, char *name);

#define List_last(A) ((A)->last != NULL ? (A)->last->name : NULL)

#define LIST_FOREACH(L, S, M, V) City *_city = NULL;\
    City *V = NULL;\
    for(V = _city = L->S; _city != NULL; V = _city = _city->M)

#endif