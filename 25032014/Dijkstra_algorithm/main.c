#include <stdio.h>
#include <stdlib.h>
#include "road.h"
#include "city.h"

int main()
{
    Road A;
    A.length = 10;
    City B;
    B.name = 'C';

    printf("%d\n%c", A.length, B.name);
    return 0;
}
