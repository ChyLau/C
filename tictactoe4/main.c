#include <stdio.h>
#include "initBoard.h"
#include "printBoard.h"

int main()
{
	int board[25];
	initBoard(&board[0]);
	printBoard(&board[0]);

	return 0;
}

