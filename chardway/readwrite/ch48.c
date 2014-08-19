#include <stdio.h>

// Writing strings to a file using fprintf
// "w" replaces the content with the given string
// "a" keeps the content and adds a string on a newline

int main(int argc, char *argv[])
{
    FILE *pfile = fopen("text.txt", "a");

    int num = 40;
    char single = 'C';
    char myWord[4] = "Cat";

    if(pfile != NULL)
    {
        fprintf(pfile, "%d %c %s\n", num, single, myWord);
        fclose(pfile);
    }
    else
    {
        printf("File not found.\n");
    }

    return 0;
}
