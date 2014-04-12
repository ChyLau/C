#include <stdio.h>

int main()
{
    FILE *file = fopen("text.m", "a");

    int num = 40;
    char single = 'C';
    char myWord[4] = "Cat";

    if(file != NULL)
    {
        fprintf(file, "%d %c %s %s\n", num, single, myWord, myWord);
        fclose(file);
    }
    else
    {
        printf("File not found");
    }

    return 0;
}
