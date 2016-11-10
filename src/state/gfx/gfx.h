/******************************************************************************
*     File Name           :     gfx.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:30]                            *
*     Last Modified       :     [2016-11-10 19:08]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#ifndef GFX_H
#define GFX_H
/*****************************************************************************/
#include <ncurses.h>
#include "src/state/map/map.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/obj/block/block.h"
/*****************************************************************************/
typedef struct gfx_s gfx_t;
/*****************************************************************************/
struct gfx_s {
    WINDOW *pad;
    int draw_width;
    int draw_height;
    int camera;
};
/*****************************************************************************/
gfx_t *init_gfx(map_t *map);
int draw(map_t *map, gfx_t *gfx);
/*****************************************************************************/
#endif // GFX_H
