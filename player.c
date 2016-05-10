#include "player.h"
#include "unit.h"
#include "config.h"

#include <stdlib.h>

player* new_player(int (*movement)(char map[][MAP_WIDTH], int input[], player *p, unit **u, block ***blockMap))
{
    player *newPlayer = malloc(sizeof(player));
    newPlayer->movement = movement;
    newPlayer->status = 1;
    newPlayer->type = 'o';
    newPlayer->coins = 0;
    return newPlayer;
}

int free_player(player *p)
{
    p->x = 0;
    p->y = 0;
    p->v_y = 0;
    p->v_x = 0;
    p->onGround = 0;
    p->status = 0;
    p->movement = NULL;
    p->type = 0;
    p->coins = 0;
    free(p);
    return 0;
}