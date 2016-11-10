/******************************************************************************
*     File Name           :     player.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:17]                            *
*     Last Modified       :     [2016-11-10 18:43]                            *
*     Description         :     Player character.                             *
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
/*****************************************************************************/
#include "../unit.h"            // Super-struct
#include "src/state/map/obj/block/block.h"
#include "src/state/input/keycodes.h"
/*****************************************************************************/
typedef struct keys_s keys_t;
typedef struct player_s player_t;
/*****************************************************************************/
struct keys_s {
    int up;
    int down;
    int left;
    int right;
    int sprint;
};
/*---------------------------------------------------------------------------*/
struct player_s {
    unit_t;
    keys_t keys;
};
/*****************************************************************************/
int player_collision(unit_t *player, map_t *map);
/*---------------------------------------------------------------------------*/
int new_mario(int x, int y, int p_num, map_t *map);
/*****************************************************************************/
#endif // PLAYER_H
