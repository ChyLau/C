#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "string.h"

int main()
{
      unsigned int num;

      printf("Number of players: ");
      scanf("%d", &num);
      printf("Player names: ");

      addPlayer(num);


    return 0;
}
