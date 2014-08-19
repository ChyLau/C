#include <stdio.h>

int main()
{
    FILE *fp = NULL;  //sets pointer of type FILE to NULL

    short x[10] = {1, 2, 3, 4, 5, 6, 5000, 6, -10, 11};
    short result[10];
    int i = 0;

    fp = fopen("temp.bin", "w+");  //create file called temp.bin and set it to read-write

    if(fp != NULL)  //if there exists a file
    {
        fwrite(x, sizeof(short), 10, fp);  //pointer to array of elements to be written - size of each element - how many elements - pointer to FILE object/output stream
        rewind(fp);  //sets pointer back to beginning of file
        fread(result, sizeof(short), 10, fp);  //pointer to block of memory - size of each element to be read - number of elements - input stream
    }
    else
    {
        return 1;  //error in function
    }

    printf("Result\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d = %d\n", i, (int)result[i]);
    }

    fclose(fp);

    return 0;
}
