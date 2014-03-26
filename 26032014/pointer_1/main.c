#include <stdio.h>
#include <stdlib.h>

void increment(int x);
void increment_pointer(int *ptr);

int main()
{
    int var = 0;
    //int *ptr = &var;

    increment(var);
    //increment_pointer(ptr);

    printf("%d", var);

    return 0;
}

void increment(int x)
{
    x++;
}

void increment_pointer(int *ptr)
{
    (*ptr)++;
}
