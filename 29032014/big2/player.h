#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct player Player;

struct player {
    char *name;
    unsigned int points;
    unsigned int wins;
    unsigned int losses;
};

Player *new_player (char *name);
void delete_player(Player *player);
void addPlayer(int num);

#endif // PLAYER_H_INCLUDED
