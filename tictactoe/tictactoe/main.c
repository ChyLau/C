#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
B,B ,B ,B ,B
B,6 ,7 ,8 ,B
B,11,12,14,B
B,16,17,18,B
B,B, B, B, B
*/

enum{NOUGHTS, CROSSES, BORDER, EMPTY};
enum{HUMANWIN, COMPWIN, DRAW};

const int convertto25[9] = {
    6, 7, 8,
    11, 12, 13,
    16, 17, 18
};
void initialiseBoard(int *board)
{
    int index = 0;
    for(index = 0; index < 25; ++index)
    {
        board[index] = BORDER;
    }

    for(index = 0; index < 9; ++index)
    {
        board[convertto25[index]] = EMPTY;
    }
}

void printBoard(const int *board)
{
    int index = 0;
    char pceChars[] = "OX|-";
    printf("\nBoard:\n\n");
    for(index = 0; index < 9; ++index)
    {
        if(index != 0 && index%3==0)
        {
            printf("\n\n");
        }
        printf("%4c", pceChars[board[convertto25[index]]]);
    }
    printf("\n");
}

int hasEmpty(const int *board)
{
    int index = 0;
    for(index = 0; index < 9; ++index)
    {
        if(board[convertto25[index]] == EMPTY)
        return 1;
    }
    return 0;
}

void makeMove(int *board, int const int sq, const side)
{
    board[sq] = side;
}

void runGame()
{
    int gameOver = 0;
    int side = NOUGHTS;
    int lastmoveMade = 0;
    int board[25];

    initialiseBoard(&board[0]);
    printBoard(&board[0]);

    while(!gameOver)
    {
        if(side==NOUGHTS)
        {

        }
    }

}

int main()
{
    srand(time(NULL));
    runGame();

    return 0;
}
