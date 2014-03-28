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
