/******************************************************************************
*     File Name           :     player.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:17]                            *
*     Last Modified       :     [2016-11-09 00:25]                            *
*     Description         :     Player character.                             *
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
/*****************************************************************************/
#include "../unit.h"            // Super-struct
#include "src/input/keycodes.h"
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
int new_player(int p_num, int x, int y, player_t **head);
/*****************************************************************************/
#endif // PLAYER_H
