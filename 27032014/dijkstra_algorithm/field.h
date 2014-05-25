#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

typedef struct field Field_struct;

struct field{
    City *map[5][5];
    City *mapList;
};

Field_struct *new_field();
void delete_field(Field_struct *field);

void addCity(Field_struct *field, int x, int y);
City *getCity(Field_struct *field, int x, int y);

#endif // FIELD_H_INCLUDED
