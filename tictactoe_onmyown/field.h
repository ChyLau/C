#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

typedef struct field Field;

struct field{
    int *board[5][5];
};

Field *new_field();
void print_board(Field *field);
int converttoArray();
void delete_field (Field *field);

#endif // FIELD_H_INCLUDED
