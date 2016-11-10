/******************************************************************************
*     File Name           :     unit.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 12:29]                            *
*     Last Modified       :     [2016-11-10 21:42]                            *
*     Description         :     Enemy/NPC/player interface                    *
******************************************************************************/
#ifndef UNIT_H
#define UNIT_H
/*****************************************************************************/
#include "../obj.h"
#include "src/state/map/obj/block/block.h"
/*****************************************************************************/
typedef struct body_s body_t;
typedef struct vectf_s vectf_t;
typedef struct vectc_s vectc_t;
typedef int (*unit_collision_f)(unit_t *player, unit_t *self, map_t *map);
typedef int (*draw_unit_f)(WINDOW *pad, unit_t *self);
/*****************************************************************************/
enum DIRECTIONS {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};
/*---------------------------------------------------------------------------*/
enum COLLISION {
    TOP,
    BOTTOM,
    SIDE,
    LOSE,
    WIN,
    TIE
};
/*---------------------------------------------------------------------------*/
struct vectf_s {
    float x;
    float y;
};
/*---------------------------------------------------------------------------*/
struct vectc_s {
    char x;
    char y;
};
/*---------------------------------------------------------------------------*/
struct body_s {
    vectf_t pos;
    vectf_t vel;
    vectf_t cen;
    vectf_t pre;
    vectc_t dir;
    vectf_t len;
    char on_ground; // on ground = 1, in air = 0
};
/*---------------------------------------------------------------------------*/
typedef struct unit_s {
    obj_t;
    body_t;
    update_f update;
    unit_collision_f ctop;
    unit_collision_f cside;
    unit_collision_f cbot;
    draw_unit_f draw;
    unit_t *next;
} unit_t;
/*****************************************************************************/
int unit_collision(unit_t *player, map_t *map);
int cdamage(unit_t *player, unit_t *self, map_t *map);
int cnone(unit_t *player, unit_t *self, map_t *map);
/*---------------------------------------------------------------------------*/
int new_goomba(int x, int y, int dir_x, map_t *map);
int new_koopa(int x, int y, int dir_x, map_t *map);
int new_piranha(int x, int y, int dir_x, map_t *map);
int new_red_shroom(int y, int x, int dir_x, map_t *map);
/*****************************************************************************/
#endif // UNIT_H
