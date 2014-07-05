#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct car Car;

struct car
{
   char name[16];
   int speed;
   Car *next;
   Car *previous;
};

Car *addCar(Car *previous)
{
   printf("Name and Speed: ");
   char input[16];
   fgets(input, 15, stdin);

   Car *newCar = malloc(sizeof(Car));
   sscanf(input, "%s %d", newCar->name, &newCar->speed);
   printf("Added: %s Speed: %d\n", newCar->name, newCar->speed);

   newCar->next = NULL;
   newCar->previous = NULL;

   if(previous != NULL)
   {
      previous->next = newCar;
      newCar->previous = previous;
   }

   return newCar;
}

void printList(Car *start)
{
   Car *curCar = start;
   int count = 0;

   Car *ahead = NULL;
   Car *behind = NULL;

   while(curCar != NULL)
   {
      count = count + 1;

      ahead = curCar->next;
      behind = curCar->previous;

      printf("Car: %d Name: %s Speed: %d Ahead: %s Behind: %s\n", count, curCar->name, curCar->speed, (ahead == NULL) ? "None": ahead->name, (behind == NULL) ? "None": behind->name);
      curCar = curCar->next;
      ahead = NULL;
      behind = NULL;
   }

}

void deleteCar(Car *start)
{
   Car *freeme = start;
   Car *holdme = NULL;

   while(freeme != NULL)
   {
      holdme = freeme->next;
      printf("Free~/ Name: %s\n",freeme->name);
      free(freeme);
      freeme = holdme;
   }
}

int main()
{
   char input[16];
   char command[16];

   Car *start = NULL;
   Car *newest = NULL;

   while(fgets(input, 15, stdin))
   {
      sscanf(input, "%s", command);
      if(strncmp(command, "quit", 4) == 0)
      {
         printf("\n\nBreaking\n");
         break;
      }
      else if (strncmp(command, "print", 5) == 0)
      {
         printList(start);
      }
      else if (strncmp(command, "add", 3) == 0)
      {
         if(start == NULL)
         {
            start = addCar(NULL);
            newest = start;
         }
         else
            newest = addCar(newest);
      }
   }

   deleteCar(start);

   return 0;
}
