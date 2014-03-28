#include <stdio.h>
#include <stdlib.h>
#include "player.h"

int main()
{
    char *name = "Chy";
    Player *newPlayer;
    newPlayer = new_player ("Chy");
    newPlayer->losses = 10;
    printf("%d %s", newPlayer->losses, newPlayer->name);
    delete_player(newPlayer);
    return 0;
}
