#include <lcthw/darray.h>
#include <assert.h>

DArray *DArray_create(size_t element_size, int initial_max)
{
    DArray *array = malloc(sizeof(DArray));
    check_mem(array);
    array->max = initial_max;
    check(array->max > 0, "initial_max must be > 0");

    array->contents = calloc(initial_max, sizeof(void *));

    array->end = 0;
    array->element_size = element_size;
    check(array->element_size > 0, "darray element_size must be > 0");
    array->expand_rate = DEFAULT_EXPAND_RATE;

    return array;

error:
    if(array)
        free(array);
    return NULL;
}

void DArray_destroy(DArray *array)
{
    if(array)
        if(array->contents)
            free(array->contents);
        free(array);
}

void DArray_clear(DArray *array)
{
    int i = 0;

    if(array->element_size > 0)
    {
        for(i = 0; i < array->max; i++)
        {
            if(array->contents[i] != NULL)
            {
                free(array->contents[i]);
            }
        }
    }
}

static inline int DArray_resize(DArray *array, size_t newsize)
{
    array->max = newsize;
    check(array->max > 0, "New size must be valid.");

    void *contents = realloc(array->contents, array->max * sizeof(void *));
    check_mem(contents);

    array->contents = contents;

    return 0;
error:
    return -1;
}

int DArray_expand(DArray *array)
{
    size_t old_max = array->max;
    check(DArray_resize(array, array->max + array->expand_rate) == 0, "Failed to resize array to new size: %d", array->max + (int)array->expand_rate);

    memset(array->contents + old_max, 0, array->expand_rate + 1);

    return 0;
error:
    return -1;
}
