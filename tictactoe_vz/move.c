#include "move.h"
#include "board.h"
#include "check.h"
#include <stdio.h>

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

int gethumanMove(int *board)
{
    char userInput[4];

    int moveOk = 0;
    int move = -1;
    int a = 0;

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
            move = -1;
            printf("Invalid sscanf()\n");
            continue;
        }

        if( move < 1 || move > 9)
        {
            move = -1;
            printf("Invalid range\n");
            continue;
        }

        move--; // Zero indexing

        a = convert(move);

        if( board[a] != EMPTY)
        {
            move=-1;
            printf("Square not available\n");
            continue;
        }
        moveOk = 1;
    }

    return convert(move);
}

int getcomputerMove(int *board, int side)
{
    int i = 0;
    int numFree = 0;
    int availableMoves[9];
    int randMove = 0;
    int a = 0;

    randMove = getwinningMove(board, side);
	if(randMove != -1) {
		return randMove;
	}

	randMove = 0;

    for(i = 0; i < 9; ++i)
    {
        a = convert(i);
        if( board[a] == EMPTY)
        {
            availableMoves[numFree++] = convert(i);
        };
    }

    randMove = (rand() % numFree);

    return availableMoves[randMove];
}

int hasEmpty(int *board)
{
    int i = 0;
    int a = 0;

    for(i = 0; i < 9; i++)
    {
        a = convert(i);
        if( board[a] == EMPTY)
            return 1;
    }

    return 0;
}

void makeMove(int *board, int sq, int side)
{
    board[sq] = side;
}

int getwinningMove(int *board, int side)
{
    int ourMove = -1;
	int winFound = 0;
	int i = 0;
	int a = 0;

	for(i = 0; i < 9; ++i) {
	    a = convert(i);
		if( board[a] == EMPTY) {
			ourMove = a;
			board[ourMove] = side;

			if(find_3Row(board, ourMove, side) == 3) {
				winFound = 1;
			}
			board[ourMove] = EMPTY;
			if(winFound == 1) {
				break;
			}
			ourMove = -1;
		};
	}
	return ourMove;
}
