#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

typedef int (*compare)(int a, int b);

int *bubble_sort(int count, int *numbers)
{
    int i  = 0;
    int j = 0;
    int temp = 0;

    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count - 1; j++)
        {
            if(numbers[j] - numbers[j + 1] > 0)
            {
                temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
                //log_info("%d", numbers[j]);
            }
        }
    }

    return numbers;
}

int main(int argc, char *argv[])
{
    check(argc >= 2, "USAGE: enter a sequence");
    int count = argc - 1;
    char **inputs = argv + 1;
    int i = 0;

    int *numbers = malloc(count * sizeof(int)); //allocate memory for arguments
    check(numbers != NULL, "Memory error");

    for(i = 0; i < count; i++)
    {
        numbers[i] = atoi(inputs[i]); //convert string to int
        //log_info("%d ", numbers[i]);
    }

    bubble_sort(count, numbers);
    for(i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

    return 0;

    error:
    return -1;

}
