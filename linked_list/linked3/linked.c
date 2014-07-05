#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct item Item;

struct item
{
   char name[16];
   Item *next;
   Item *previous;
};

Item *addItem(Item *previous)
{
   char input[16];

   printf("Add item: ");
   fgets(input, 15, stdin);

   Item *newItem = malloc(sizeof(Item));
   sscanf(input, "%s", newItem->name);
   printf("Item: %s\n", newItem->name);

   newItem->next = NULL;
   newItem->previous = NULL;

   while(previous != NULL)
   {
      previous->next = newItem;
      newItem->previous = previous;
   }

   return newItem;
}

void printList(Item *start)
{
   Item *curItem = start;
   while(curItem != NULL)
   {
      printf("Item %s", curItem->name);
      curItem = curItem->next;
   }
}

int main()
{
   char input [16];
   char command [16];

   Item *start = NULL;
   Item *newest = NULL;

   while(fgets(input, 15, stdin))
   {
      sscanf(input, "%s", command);

      if(strncmp(command, "quit", 4) == 0)
      {
         printf("Terminate...\n");
         break;
      }
      else if(strncmp(command, "print", 5) == 0)
      {
         printList(start);
      }
      else if(strncmp(command, "add", 3) == 0)
      {
         if(start == NULL)
         {
            start = addItem(NULL);
            newest = start;
         }

         newest = addItem(newest);
      }
   }
   return 0;
}
