#include "check.h"
#include "board.h"

enum { NOUGHTS, CROSSES, BORDER, EMPTY };

int getnumforDir(int startSq, int dir, int *board, int us)
{
	int found = 0;
	while(board[startSq] != BORDER) {
		if(board[startSq] != us) {
			break;
		}
		found++;
		startSq += dir;
	}
	return found;
}

int find_3Row(int *board, int ourindex, int us)
{
    int DirIndex = 0;
	int Dir = 0;
	int threeCount = 1;
	int Directions[4] = { 1, 5, 4, 6 };

	for(DirIndex = 0; DirIndex < 4; ++DirIndex) {
		Dir = Directions[DirIndex];
		threeCount += getnumforDir(ourindex + Dir, Dir, board, us);
		threeCount += getnumforDir(ourindex + Dir * -1, Dir * -1, board, us);
		if(threeCount == 3) {
			break;
		}
		threeCount = 1;
	}
	return threeCount;
}
