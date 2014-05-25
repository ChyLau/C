#include <stdio.h>
#include "printBoard.h"

void printBoard(int *board)
{
	int i = 0;
	printf("\nBoard:\n");

	for(i = 0; i < 25; i++)
	{
		if(i!=0 && i%5 == 0)
		{
			printf("\n");
		}
		
		printf("%4d", board[i]);	
	}
	printf("\n");

}
