/******************************************************************************
*     File Name           :     player.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:17]                            *
*     Last Modified       :     [2016-11-02 18:37]                            *
*     Description         :     Player character.                             *
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
/*****************************************************************************/
#include "src/map/map.h"
/*****************************************************************************/
typedef struct map_s map_t;
typedef struct player_s player_t;
typedef struct keys_s keys_t;
typedef struct body_s body_t;
typedef void (*player_action_f)(map_t*, player_t*);
/*****************************************************************************/
struct keys_s {
    int up;
    int down;
    int left;
    int right;
    int sprint;
};
/*---------------------------------------------------------------------------*/
struct body_s {
    double x;
    double y;
    int x_axis;
    int y_axis;
};
/*---------------------------------------------------------------------------*/
struct player_s {
    char ch;
    void *data;
    float x;
    float y;
    char color;
    keys_t keys;
    body_t body;
    player_action_f action;
    player_t *next;
};
/*****************************************************************************/
int new_player(map_t *map, int x, int y);
/*****************************************************************************/
#endif // PLAYER_H
