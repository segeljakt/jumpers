/******************************************************************************
*     File Name           :     block.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:12]                            *
*     Last Modified       :     [2016-11-05 12:48]                            *
*     Description         :     Block in map.                                 *
******************************************************************************/
#ifndef BLOCK_H
#define BLOCK_H
/*****************************************************************************/
#include <ncurses.h>
#include "src/map/obj/obj.h"
#include "src/map/map.h"
/*****************************************************************************/
struct collision_s {
    obj_t *obj;
    collide_t collide;
};
/*---------------------------------------------------------------------------*/
struct block_s {
    obj_t;
    collision_t collision;
};
/*****************************************************************************/
int normal_block_collide(map_t *map, int angle, obj_t *obj);
int coin_block_collide(map_t *map, int angle, obj_t *obj);
/*****************************************************************************/
#endif // BLOCK_H
