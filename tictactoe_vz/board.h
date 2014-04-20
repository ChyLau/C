#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef struct board Board;

struct board{
    int *board[25];
};

Board *new_board();
void print_board(Board *board);
void delete_board(Board *board);

#endif // BOARD_H_INCLUDED
