/******************************************************************************
*     File Name           :     obj.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-03 15:53]                            *
*     Last Modified       :     [2016-11-09 22:14]                            *
*     Description         :     Object in map.                                *
******************************************************************************/
#ifndef OBJ_H
#define OBJ_H
/*****************************************************************************/
#include <stdlib.h>
#include <ncurses.h>
#include "src/cfg.h"
#include "src/state/map/obj/sprite.h"
/* Forward declarations ******************************************************/
typedef struct block_s block_t;
typedef struct unit_s unit_t;
/*---------------------------------------------------------------------------*/
typedef struct obj_s obj_t;
typedef int (*update_f)(unit_t *, unit_t *, unit_t *, block_t **);
/*****************************************************************************/
enum STATUS {
    INVULNERABLE,
    DEAD
};
/*---------------------------------------------------------------------------*/
struct obj_s {
    char type;
    char status;
};
/*****************************************************************************/
#endif // OBJ_H
