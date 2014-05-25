#include "initBoard.h"

enum{EMPTY, NOUGTHS, CROSSES, BORDER};
const int convert[9] = {6, 7, 8, 11, 12, 13, 16, 17, 18};

void initBoard(int *board)
{
	int i = 25;
	
	for(i = 0; i < 25; i++)
	{
		board[i] = BORDER; 
	}

	for(i = 0; i < 9; i++)
	{
		board[convert[i]] = EMPTY;
	}
}
