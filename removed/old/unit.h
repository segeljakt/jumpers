#ifndef MARIO_UNIT
#define MARIO_UNIT
typedef struct unit unit;
#include "config.h"
#include "player.h"
struct unit
{
    float x;
    float y;
    float v_y;
    float v_x;
    int onGround;
    int status;
    unit *prev;
    unit *next;
    int (*movement)(char map[][MAP_WIDTH], struct unit *u, player *p);
    char type;
};
unit* new_unit(float x, float y, float v_x, float v_y, int status, int onGround, int (*movement)(char map[][MAP_WIDTH], unit *u, player *p), char type);
int free_unit(unit *u);
#endif