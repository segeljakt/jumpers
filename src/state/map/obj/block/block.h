/******************************************************************************
*     File Name           :     block.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:12]                            *
*     Last Modified       :     [2016-11-09 22:27]                            *
*     Description         :     Block in map.                                 *
******************************************************************************/
#ifndef BLOCK_H
#define BLOCK_H
/*****************************************************************************/
#include "../obj.h"
#include "src/state/map/obj/unit/unit.h"
/*****************************************************************************/
typedef int (*block_collision_f)(unit_t *player, block_t *self);
typedef int (*draw_block_f)(WINDOW *pad, block_t *self);
/*****************************************************************************/
struct block_s {
    obj_t;
    block_collision_f ctop;
    block_collision_f cside;
    block_collision_f cbot;
    draw_block_f draw;
    char has_collision;
};
/*****************************************************************************/
block_t init_empty_block();
block_t init_normal_block();
block_t init_coin_block();
/*****************************************************************************/
#endif // BLOCK_H
