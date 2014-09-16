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
        if(cur->name == name)
        {
            return 0;
        }
    }

    return -1;
}

void List_push(List *list, char *name)
{
    City *city = calloc(1, sizeof(City));
    check_mem(city);

    city->name = name;

    check(City_find(list, city->name) != 0, "City %s already exists.", city->name);

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
    FILE *db = NULL;
    int i = 0;
    int num_cities = 0;
    char city_name[MAX_LENGTH];

    db = db_open(DB_FILE, "r");
    check(db, "Failed to open database: %s", DB_FILE);

    int rc = fscanf(db, "%d", &num_cities);
    check(rc != 0, "Failed to read number of cities.");
    log_info("Number of cities: %d", num_cities);
    log_info("File pointer position: %d", ftell(db));

    for(i = 0; i < num_cities; i++)
    {
        fgets(city_name, MAX_LENGTH, db);
        log_info("File pointer position: %d", ftell(db));
        log_info("City name: %s", city_name);

        List_push(list, city_name);
    }

    db_close(db);

    return list;
error:
    if(db)
        fclose(db);
    return NULL;
}
