#include <stdio.h>

int main()
{
    FILE *file = fopen("text.txt", "r");

    int line = 0;
    char input[512];

    while(fgets(input, 512, file))
    {
        line++;
        printf("Line:%d -> %s", line, input);
    }

    printf("\n\nEOF\n");

    fclose(file);

    return 0;
}
