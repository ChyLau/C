#include <stdio.h>

// Reads data from a file
// I did not review this code yet
// Getting errors

#define NUMDATA 3

typedef struct {
    int numOne;
    char name[16];
    double numTwo;
} MY_DATA;

void PrintData(MY_DATA *data)
{

    int index = 0;

    for(index = 0; index < NUMDATA; ++index)
    {
        printf("%s %d %.3f\n",data[index].name,data[index].numOne,data[index].numTwo);
    }

}

void WriteDataToFile(MY_DATA *data)
{
    FILE *pFile = fopen("myData.bin","wb");

    if(pFile != NULL)
    {
        fwrite(data, sizeof(MY_DATA), NUMDATA, pFile );
        fclose(pFile);
    }
    else
    {
        printf("ERROR WRITING\n");
    }
}

void ReadSomeData()
{
    MY_DATA dataArray[NUMDATA];

    FILE *pFile = fopen("myData.bin","rb");

    fseek(pFile, 0, SEEK_END);
    long fileSize = ftell(pFile);
    rewind(pFile);
    printf("ReadSomeData(): fileSize:%ld\n",fileSize);

    int numStructures = (int)(fileSize / (sizeof(MY_DATA)));
    printf("ReadSomeData(): numStructures:%d\n",numStructures);

    size_t returnValue;
    returnValue = fread(dataArray, sizeof(MY_DATA), numStructures, pFile );
    printf("ReadSomeData(): returnValue:%ld\n",returnValue);

    PrintData(dataArray);
}

void ReadOneData(int index)
{
    MY_DATA data;

    FILE *pFile = fopen("myData.bin","rb");

    fseek(pFile, (sizeof(MY_DATA)*index), SEEK_SET);
    //size_t returnValue;
    //returnValue = fread(&data, sizeof(MY_DATA), 1, pFile );
    printf("ReadOneData(%d): %s %d %.3f\n",index,data.name,data.numOne,data.numTwo);
}

int main(int argc, char *arg[])
{
    int index = 0;

    for(index = 0; index < NUMDATA; index++)
    {
        ReadOneData(index);
    }

    return 0;
}
