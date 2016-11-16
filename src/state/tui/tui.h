/******************************************************************************
*     File Name           :     tui.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:30]                            *
*     Last Modified       :     [2016-11-15 10:19]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#ifndef TUI_H
#define TUI_H
/*****************************************************************************/
#include <ncurses.h>
#include "src/state/map/map.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/obj/block/block.h"
/*****************************************************************************/
typedef struct tui_s tui_t;
/*****************************************************************************/
struct tui_s {
    WINDOW *pad;
    vecti_t draw;
    int camera;
};
/*****************************************************************************/
tui_t *init_tui(map_t *map);
int draw(map_t *map, tui_t *tui);
/*****************************************************************************/
#endif // TUI_H
