#include <stdio.h>

#define NUMDATA 3

typedef struct{
    int numOne;
    char name[16];
    double numTwo;
} MY_DATA;

void printData(MY_DATA *data)
{
    int i = 0;

    for(i = 0; i < NUMDATA; i++)
    {
        printf("%s %d %.3f\n", data[i].name, data[i].numOne, data[i].numTwo);
    }
}

void writeData(MY_DATA *data)
{
    FILE *pfile = fopen("data.bin", "wb");

    if(pfile != NULL)
    {
         fwrite(data, sizeof(MY_DATA), NUMDATA, pfile);
         fclose(pfile);
    }
    else
    {
        printf("Error writing.");
    }

}

int main(int argc, char *argv[])
{
    MY_DATA dataArray[NUMDATA] = {
        {10, "Dog", 111.123},
        {20, "Beer", 222.456},
        {30, "Iguana", 333.789}
    };

    printData(dataArray);
    writeData(dataArray);
    return 0;
}
