#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "dbg.h"

typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp) //returns pointer of type int
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    memcpy(target, numbers, count * sizeof(int)); //copy n bytes from numbers to target

    for(i = 0; i < count; i++)
    {
        for(j = 0; j < count - 1; j++)
        {
            if(cmp(target[j], target[j+1]) > 0) //target[i] - target[j+1] > 0
            {
                //this block switches target[i] with the smaller number
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }


    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if(!sorted)
    {
        log_err("Failed to sort as requested");
    }

    for(i = 0; i < count; i++)
    {
        printf("%d ", sorted[i]);
    }

    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[])
{
    check(argc >= 2, "USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    check(numbers != NULL, "Memory error");

    for(i = 0; i < count; i++)
    {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);

    free(numbers);
    return 0;

    error:
    return -1;
}
