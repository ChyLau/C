#ifndef lcthw_list_algos_h
#define lcthw_list_algos_h

#include <stdlib.h>

typedef int (*List_compare)(char *s1, char *s2);

int sorted_order(char *s1, char *s2);

struct ListNode;

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
void List_push(List *list, void *value);
int List_bubble_sort(List *list, (List_compare) strcmp);
void List_destroy(List *list);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
