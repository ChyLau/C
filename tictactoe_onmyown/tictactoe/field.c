#include "field.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

Field *new_field()
{
    Field *field = malloc(sizeof(Field));

    int x, y;

    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            if (x==0 || x==4 || y==0 || y==4)
            {
                field->board[x][y] = BORDER;
            }
            else
            {
                field->board[x][y] = EMPTY;
            }
        }
    }
    return field;
}

int converttoArray(Field *field)
{
    int x, y;
    int i = 0;
    int *convert[9];

    for (x = 1; x < 4; x++)
    {
        for (y = 1; y < 4; y++)
        {
            convert[i] = field->board[x][y];
            i++;
        }
    }

//    for(i = 0; i < 9; i++)
//    {
//        printf("%d %d  ", convert[i], i);
//    }

    return convert;
}

void print_board(Field *field)
{
    int x, y;

    for (x = 1; x < 4; x++)
    {
        printf("\n");
        for (y = 1; y < 4; y++)
        {
            printf("%4d", field->board[x][y]);
        }
        printf("\n");
    }
}

void delete_field (Field *field)
{
    free(field);
}
