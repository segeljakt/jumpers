/******************************************************************************
*     File Name           :     unit.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-05 12:29]                            *
*     Last Modified       :     [2017-01-09 15:57]                            *
*     Description         :     Enemy/NPC/player interface                    *
******************************************************************************/
#ifndef UNIT_H
#define UNIT_H
/*****************************************************************************/
#include "../obj.h"
#include "src/state/map/obj/block/block.h"
#include "src/state/tui/tui.h"
/*****************************************************************************/
typedef struct block_s block_t;
/*---------------------------------------------------------------------------*/
typedef struct body_s body_t;
typedef int (*unit_collision_f)(unit_t *player, unit_t *self, map_t *map);
typedef int (*draw_unit_f)(tui_t *tui, unit_t *self, map_t *map);
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
int kill_unit(unit_t **unit);
/*---------------------------------------------------------------------------*/
int unit_collision(unit_t *player, map_t *map);
int cdamage(unit_t *player, unit_t *self, map_t *map);
int cnone(unit_t *player, unit_t *self, map_t *map);
/*---------------------------------------------------------------------------*/
int parse_goomba(int y, int x, char **raw_map, map_t *map);
int parse_koopa(int y, int x, char **raw_map, map_t *map);
int parse_piranha(int y, int x, char **raw_map, map_t *map);
int parse_red_shroom(int y, int x, char **raw_map, map_t *map);
/*---------------------------------------------------------------------------*/
int new_goomba(int y, int x, int dir_x, map_t *map);
int new_koopa(int y, int x, int dir_x, map_t *map);
int new_piranha(int y, int x, int dir_x, map_t *map);
int new_red_shroom(int y, int x, int dir_x, map_t *map);
int new_green_shroom(int y, int x, int dir_x, map_t *map);
int new_star(int y, int x, int dir, map_t *map);
/*---------------------------------------------------------------------------*/
int drawch(tui_t *tui, map_t *map, float y, float x, char ch);
/*****************************************************************************/
#endif // UNIT_H
