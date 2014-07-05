#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct person Person;

struct person
{
   //char *name;
   char name[16];
   int height;
   Person *next;
};

Person *addPerson(Person *previous)
{
   printf("Name and Height: ");
   char input[16];

   fgets(input, 15, stdin);

   Person *newPerson = malloc(sizeof(Person));

   sscanf(input, "%s %d", newPerson->name, &newPerson->height);
   printf("Name: %s Height: %d\n", newPerson->name, newPerson->height);

  newPerson->next = NULL;

   if(previous != NULL)
   {
      previous->next = newPerson;
   }

   return newPerson;
}

void printList(Person *start)
{
   Person *curPerson = start;
   int count = 0;
   while(curPerson != NULL)
   {
      count = count + 1;
      printf("Name: %s Height: %d", curPerson->name, curPerson->height);
      curPerson = curPerson->next;
   }
}

void deletePerson(Person *start)
{
   Person *freeme = start;
   Person *holdme =  NULL;

   while(freeme != NULL)
   {
      holdme = freeme->next;
      printf("Free ~/Name: %s\n", freeme->name);
     // free(freeme->name);
      free(freeme);
      freeme = holdme;
   }
}


int main()
{
   char command[16];
   char input[16];

   Person *start = NULL;
   Person *newest = NULL;


   while(fgets(input, 15, stdin))
   {
      sscanf(input, "%s", command);

      if(strncmp(command, "quit", 4) == 0)
      {
         printf("Terminate...\n");
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
               start = addPerson(start);
               newest = start;
            }
            else
               newest = addPerson(newest);
      }
   }

   deletePerson(start);

   return 0;
}
