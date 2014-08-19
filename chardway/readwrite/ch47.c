#include <stdio.h>

//Read in character by character using fgetc

int main(int argc, char *argv[])
{
    FILE *pfile = fopen("text.txt", "r");

    char single;

    while((single = fgetc(pfile)) != EOF)
    {
        printf("%c", single);
    }

    printf("\n\nEnd of program\n");

    fclose(pfile);

    return 0;
}
