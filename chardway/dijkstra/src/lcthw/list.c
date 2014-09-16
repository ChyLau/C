#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOR_EACH(list, first, next, cur)
    {
        if(cur->prev)
        {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_push(List *list, char *name)
{
    City *city = calloc(1, sizeof(City));
    check_mem(city);
    city->name = name;

    if(list->last == NULL)
    {
        list->first = city;
        list->last = city;
    }
    else
    {
        list->last->next = city;
        city->prev = list->last;
        list->last = city;
    }

    list->count++;

error:
    if(city)
        free(city);
    return;
}

City *City_find(List *list, char *name)
{
    City *city = calloc(1, sizeof(City));

    LIST_FOR_EACH(list, first, next, cur)
    {
        if(cur->name == name)
        {
            city = cur;
            check_mem(city);
        }
    }

    return city;

error:
    if(city)
        free(city);
    return;
}
