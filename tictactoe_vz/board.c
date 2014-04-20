#include "board.h"
#include "convert.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

//const int convert[9] =
//{
//	6,7,8,
//	11,12,13,
//	16,17,18
//};

Board *new_board()
{
    Board *board = malloc(sizeof(Board));
    int i = 0;

    for(i = 0; i < 25; i++)
    {
        board->board[i] = BORDER;
    }

    for(i = 0; i < 9; i++)
    {
        int a = convert(i);
        board->board[a] = EMPTY;
    }
}

void print_board(Board *board)
{
    int i = 0;
    int a = 0;
    int b = 0;
    char pceChars[] = "OX|-";

    for(i = 0; i < 9; i++)
    {
        if(i != 0 && i%3 == 0)
        {
            printf("\n\n");
        }
        a = convert(i);
        b = board->board[a];
        printf("%4c", pceChars[b]);
    }
    printf("\n");
}

void delete_board(Board *board)
{
    free(board);
}
