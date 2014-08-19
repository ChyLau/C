#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *ptoFile = fopen("text.txt", "r");

    int line = 0;

    char input[512];

    while(fgets(input, 512, ptoFile))
    {
        line++;
        printf("Line: %d -> %s", line, input);
    }

    printf("\n\n End of file.\n");

    fclose(ptoFile);

    return 0;
}
