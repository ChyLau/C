#include <stdio.h>
#include  "string.h"
#include "start.h"
#include "field.h"
#include "move.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

int gethumanMove (int *board)
{
    char userInput[4];
    int moveOk = 0;
    int move = 1;

    while (moveOk == 0)
    {
        printf("Please enter a move from 1 to 9:");
        fgets(userInput, 3, stdin);
        fflush(stdin);

        if(strlen(userInput) != 2)
        {
            printf("Invalid strlen()\n");
            continue;
        }

        if( sscanf(userInput, "%d", &move) != 1)
        {
            move = 1;
            printf("Invalid sscanf()\n");
            continue;
        }

        if( move < 1 || move > 9)
        {
            move = 1;
            printf("Invalid range\n");
            continue;
        }

        if( board[move]!=EMPTY)
        {
            move= 1;
            printf("Square not available\n");
            continue;
        }
        moveOk = 1;
    }
    printf("Making Move...%d\n",(move));

    return board[move];
}

int hasEmpty(int *board)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if(board[i] == EMPTY)
        {
            return 1;
        }
    }

    return 0;
}

void makeMove(int *board, int sq, int side)
{
    board[sq] = side;
}
