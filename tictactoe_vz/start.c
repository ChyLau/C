#include "start.h"
#include "move.h"
#include "board.h"
#include "check.h"

enum { NOUGHTS, CROSSES, BORDER, EMPTY };

void runGame()
{
    int gameOver = 0;
    int side = NOUGHTS;
    int LastMoveMade = 0;

    Board *board = new_board();
    print_board(board);

    while(!gameOver)
    {
        if(side == NOUGHTS)
        {
            LastMoveMade = gethumanMove(board);
            makeMove(board, LastMoveMade, side);
            side=CROSSES;
        }
        else
        {
            LastMoveMade = getcomputerMove(board, side);
            makeMove(board, LastMoveMade, side);
            side = NOUGHTS;
            print_board(board);
        }

        if( find_3Row(board, LastMoveMade, side ^ 1) == 3)
        {
            printf("Game over!\n");
            gameOver = 1;
            if(side==NOUGHTS)
            {
                printf("Computer Wins\n");
            }
            else
            {
                printf("Human Wins\n");
            }
        }

        if(!hasEmpty(board))
        {
            printf("Game over!\n");
            gameOver = 1;
            printf("It's a draw\n");
        }

        delete_board(board);
    }
}
