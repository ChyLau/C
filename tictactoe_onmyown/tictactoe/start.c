#include "start.h"
#include "field.h"

enum {NOUGHTS, CROSSES, BORDER, EMPTY};

void runGame()
{
    int gameOver = 0;
	int side = NOUGHTS;
	int lastmovemade = 0;

	Field *board;
    board  = new_field();
    print_board(board);

    while(!gameOver)
    {
        if(side==NOUGHTS)
        {
            //get move from human, make move on board, change side

        }
        else
        {
            //get move from computer, make move on board, change side

        }
    }

    delete_field(board);

    return 0;
}
