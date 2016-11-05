/******************************************************************************
*     File Name           :     unit.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 12:29]                            *
*     Last Modified       :     [2016-11-05 17:09]                            *
*     Description         :     Enemy/NPC/player interface                    *
******************************************************************************/
#ifndef UNIT_H
#define UNIT_H
/*****************************************************************************/
#include <ncurses.h>
#include "../obj.h"
#include "src/input/keycodes.h"
#include "src/map/cfg.h"
/*---------------------------------------------------------------------------*/
enum DIRECTIONS {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};
/*---------------------------------------------------------------------------*/
struct body_s {
    float x;
    float y;
    float v_x;
    float v_y;
    char d_x;
    char d_y;
    char on_ground;
};
/*---------------------------------------------------------------------------*/
typedef struct unit_s {
    obj_t;
    body_t body;
} unit_t;
/*****************************************************************************/
#endif // UNIT_H
