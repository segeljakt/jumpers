/******************************************************************************
*     File Name           :     obj.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-03 15:53]                            *
*     Last Modified       :     [2016-11-05 17:09]                            *
*     Description         :     Object in map.                                *
******************************************************************************/
#ifndef OBJ_H
#define OBJ_H
/*****************************************************************************/
#include "src/map/map.h"
#include "src/type.h"
#include "src/map/cfg.h"
/*****************************************************************************/
struct obj_s {
    gfx_t gfx;
    collision_t *collision;
    update_f update;
    draw_f draw;
    serialize_f serialize;
    collide_f collide;
};
/*****************************************************************************/
#endif // OBJ_H
