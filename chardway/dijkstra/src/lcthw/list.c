#include <lcthw/list.h>
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

static inline City *City_find(List *list, char *name)
{
    LIST_FOREACH(list, first, next, cur)
    {
        if(strcmp(cur->name, name) == 0)
        {
            return cur;
        }
    }

    return NULL;
}

void List_push(List *list, char *name)
{
    City *city = calloc(1, sizeof(City));
    check_mem(city);

    city->name = name;
    check(City_find(list, city->name) == NULL, "City  %s already exists.", city->name);

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
    return;
}

static FILE *db_open(const char *path, const char *mode)
{
    return fopen(path, mode);
}

static void db_close(FILE *db)
{
    fclose(db);
}

List *List_city(List *list)
{
    /*
    FILE *db = NULL;
    int i = 0;
    int num_cities = 0;
    char city_name[MAX_LENGTH];

    db = db_open(DB_FILE, "r");
    check(db, "Failed to open database: %s", DB_FILE);

    fscanf(db, "%d", &num_cities);
    log_info("Numer of cities: %d", num_cities);

    for(i = 0; i < num_cities; i++)
    {
        fscanf(db, "%s", city_name);
        log_info("List_city name: %s", city_name);
        List_push(list, city_name);
        log_info("List_city first: %s", list->first->name);
        log_info("List_city last: %s", list->last->name);
    }
    */

    char *city1 = "A";
    char *city2 = "B";
    char *city3 = "C";

    List_push(list, city1);
    List_push(list, city2);
    List_push(list, city3);

    //db_close(db);

    return list;

    /*
error:
    if(db)
        fclose(db);
    return NULL;
    */
}

Road *Road_create(City *origin, City *destination, unsigned length)
{
    Road *road = calloc(1, sizeof(Road));
    check_mem(road);
    road->origin = origin;
    road->destination = destination;
    road->length = length;
    road->next = NULL;

    return road;

error:
    if(road)
        free(road);
    return NULL;
}
