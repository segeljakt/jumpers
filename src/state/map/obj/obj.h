/******************************************************************************
*     File Name           :     obj.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-03 15:53]                            *
*     Last Modified       :     [2016-11-21 21:32]                            *
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
    UNASSIGNED = 0x00,
    ASSIGNED   = 0x01,
    INVINCIBLE = 0x02,
    DEAD       = 0x03,
    MODIFIED   = 0x04,
    EMPTY      = 0x05,
    BIG        = 0x06,
    HAS_JUMPED = 0x07
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
    int status;
    int color_attribute;
};
/*****************************************************************************/
#endif // OBJ_H
