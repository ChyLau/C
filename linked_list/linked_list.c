#include <stdio.h>

typedef struct racingcar RacingCar;

struct racingcar{
	char name[8];
	int speed;
};

const int MaxCars = 4;

void PrintList()
{
	printf("List Print...\n");
}

void AddCar()
{
	printf("Add Car...\n");
}

int main()
{
	RacingCar allCars[MaxCars];
	int numCars = 0;
	
	char command[16];
	char input[16];
	
	while(fgets(input, 15, stdin))
	{
		sscanf(input, "%s", command);
		
		if(strncmp(command, "quit", 4) == 0)
		{
			printf("\nBreaking...\n");
			break;
		}
		else if(strncmp(command, "add", 3) == 0)
		{
			AddCar();
		}
		else if(strncmp(command, "print", 5) == 0)
		{
			PrintList();
		}
	}
	
	return 0;
}