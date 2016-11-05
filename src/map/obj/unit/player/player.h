/******************************************************************************
*     File Name           :     player.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:17]                            *
*     Last Modified       :     [2016-11-05 14:41]                            *
*     Description         :     Player character.                             *
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
/*****************************************************************************/
#include <ncurses.h>
#include "../unit.h"            // Super-struct
#include "src/input/keycodes.h"
#include "src/type.h"
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
    int color;
    player_t *next;
};
/*****************************************************************************/
int new_local_player(map_t *map);
/*****************************************************************************/
#endif // PLAYER_H
