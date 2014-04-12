#include "field.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

Field *new_field()
{
    Field *field = malloc(sizeof(Field));

    int x, y;
    char pceChars[] = "OX|-";

    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            if (x==0 || x==4 || y==0 || y==4)
            {
                field->board[x][y] = pceChars[BORDER];
            }
            else
            {
                field->board[x][y] = pceChars[EMPTY];
            }
        }
    }
    return field;
}

void print_board(Field *field)
{
   int x, y;

    for (x = 1; x < 4; x++)
    {
        printf("\n");
        for (y = 1; y < 4; y++)
        {
            printf("%4c", field->board[x][y]);
        }
        printf("\n");
    }
}

void delete_field (Field *field)
{
        free(field);
}
