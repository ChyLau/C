#include <stdio.h>
#include  "string.h"
#include "start.h"
#include "field.h"
#include "move.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

void runGame()
{
    int gameOver = 0;
    int side = NOUGHTS;
    int lastmovemade = 0;
    int i = 0;

    Field *board;
    board  = new_field();
    print_board(board);

    int *a = converttoArray(board);

    for(i = 0; i < 9; i++)
    {
        printf("%d %d", *(a+i), i);
    }
    delete_field(board);

    return 0;
}
