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

static inline int City_find(List *list, char *name)
{
    LIST_FOREACH(list, first, next, cur)
    {
        log_info("cur name: %s", cur->name);
        if(strcmp(cur->name, name) == 0)
        {
            return 0;
        }
    }

    return -1;
}

void List_push(List *list, char *name)
{
    City *city = calloc(1, sizeof(City));

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
    FILE *db = NULL;
    int i = 0;
    int num_cities = 0;
    char *city_name = NULL;
    size_t len = 0;
    ssize_t read;

    db = db_open(DB_FILE, "r");
    check(db, "Failed to open database: %s", DB_FILE);

    check((read = getline(&city_name, &len, db)) != -1, "Failed to read line.");
    num_cities = atoi(city_name);
    log_info("Number of cities: %d", num_cities);

    for(i = 0; i < num_cities; i++)
    {
        check((read = getline(&city_name, &len, db)) != -1, "Failed to read line.");
        log_info("City name: %s", city_name);
        log_info("City length: %zu", strlen(city_name));
        List_push(list, city_name);
    }

    db_close(db);

    return list;
error:
    if(db)
        fclose(db);
    return NULL;
}
