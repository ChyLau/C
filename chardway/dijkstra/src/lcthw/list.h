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

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
