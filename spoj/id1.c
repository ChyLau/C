#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
   char input[2];
   char command[2];

   while(fgets(input, 1, stdin))
   {
      sscanf(input, "%s", command);
      printf("%s", command);
      if(strncmp(command, "42", 2) == 0)
      {
         printf("terminate");
         break;
      }
   }

   return 0;
}
