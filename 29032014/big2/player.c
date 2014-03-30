#include <stdlib.h>
#include "player.h"

Player *new_player(char *name)
{
    Player *player = malloc(sizeof(Player));
    player->name = name;
    player->points = 0;
    player->wins = 0;
    player->losses = 0;
}

void addPlayer(int num)
{
      int i = 0;
      char *name;
      Player *curPlayer;

      for(i = 0; i < num; i++)
      {
          scanf("%s", &name);
          curPlayer = new_player(&name);
      }
}

void delete_player(Player *player)
{
    if (player != NULL)
    {
        free(player->name);
        free(player);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}
