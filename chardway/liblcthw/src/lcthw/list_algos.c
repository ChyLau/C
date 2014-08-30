#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOREACH(list, first, next, cur)
    {
        if(cur->prev)
        {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_push(List *list, void *value)
{
    ListNode *node = callic(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(List->last == NULL)
    {
        List->last = node;
        List->first = node;
    }
    else
    {
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
    }

    list->count++;

error:
    return;
}

int sorted_order(char *s1, char *s2)
{
    return strcmp(s1, s2);
}

int List_bubble_sort(List *list, (List_compare) strcmp)
{
    int count = list->count;
    int i = 0;

    for(i = 0; i < count; i++)
    {
        LIST_FOREACH(list, first, next, cur)
        {
            if(strcmp(cur->value, cur->next->value) > 0)
            {
                ListNode *tmp = calloc(1, sizeof(ListNode));
                tmp = cur->next;
                temp->next = cur;
                temp->prev = NULL;

                cur->prev = temp;
                cur->next = cur->next->next;
                cur->next->next->prev = cur;

                free(tmp);
            }
        }
    }
}
