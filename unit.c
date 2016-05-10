#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"

#include <stdlib.h>

unit* new_unit(float x, float y, float v_x, float v_y, int status, int onGround, int (*movement)(char map[][MAP_WIDTH], unit *u, player *p), char type)
{
    unit *newUnit = malloc(sizeof(unit));
    newUnit->x = x;
    newUnit->y = y;
    newUnit->v_x = v_x;
    newUnit->v_y = v_y;
    newUnit->status = status;
    newUnit->onGround = onGround;
    newUnit->movement = movement;
    newUnit->type = type;
    return newUnit;
}

int free_unit(unit *u)
{
    u->x = 0;
    u->y = 0;
    u->v_y = 0;
    u->v_x = 0;
    u->onGround = 0;
    u->status = 0;
    u->prev = NULL;
    u->next = NULL;
    u->movement = NULL;
    u->type = 0;
    free(u);
    return 0;
}