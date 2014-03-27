#include <stdlib.h>
#include "field.h"

Field_struct *new_field()
{
    int x, y;
    Field_struct *field = malloc(sizeof(Field_struct *field));

    for(x = 0; x < 5; x++)
    {
        for(y = 0; y < 5; y++)
        {
            field->map[x][y] = NULL;
        }
    }
    field->mapList = NULL;

    return field;
}

//Not completed
void delete_field(Field_struct *field)
{
    if(field != 0)
    {
        free(field);
    }
}

void addCity(Field_struct *field, int x, int y)
{

}
