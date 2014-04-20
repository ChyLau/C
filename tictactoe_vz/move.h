#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

int gethumanMove(int *board);
int getcomputerMove(int *board, int side);
int hasEmpty(int *board);
void makeMove(int *board, int sq, int side);
int getwinningMove(int *board, int side);

#endif // MOVE_H_INCLUDED
