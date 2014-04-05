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
    delete_field(board);

    return board;
}
