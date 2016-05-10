#ifndef MARIO_PLAYER
#define MARIO_PLAYER
typedef struct player player;
#include "config.h"
#include "unit.h"
#include "block.h"
struct player
{
    float x;
    float y;
    float v_y;
    float v_x;
    int onGround;
    int status;
    int (*movement)(char map[][MAP_WIDTH], int input[], player *p, unit **u, block ***blockMap);
    char type;
    int coins;
};
player* new_player(int (*movement)(char map[][MAP_WIDTH], int input[], player *p, unit **u, block ***blockMap));
int free_player(player *p);
#endif