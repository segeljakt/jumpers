/******************************************************************************
*     File Name           :     obj.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-03 15:53]                            *
*     Last Modified       :     [2016-11-12 23:01]                            *
*     Description         :     Object in map.                                *
******************************************************************************/
#ifndef OBJ_H
#define OBJ_H
/*****************************************************************************/
#include <stdlib.h>
#include <ncurses.h>
#include "src/cfg.h"
#include "src/state/map/map.h"
#include "src/state/map/obj/sprite.h"
/* Forward declarations ******************************************************/
typedef struct block_s block_t;
typedef struct unit_s unit_t;
/*---------------------------------------------------------------------------*/
typedef struct vectf_s vectf_t;
typedef struct vectc_s vectc_t;
typedef struct vecti_s vecti_t;
typedef struct obj_s obj_t;
typedef int (*update_f)(unit_t *, map_t *);
/*****************************************************************************/
enum STATUS {
    INVINCIBLE = 0x01,
    DEAD       = 0x02,
    MODIFIED   = 0x03,
    EMPTY      = 0x04,
    BIG        = 0x05
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
struct vecti_s {
    int x;
    int y;
};
/*---------------------------------------------------------------------------*/
struct obj_s {
    char type;
    char status;
    int color_attribute;
};
/*****************************************************************************/
#endif // OBJ_H
