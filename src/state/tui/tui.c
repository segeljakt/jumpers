/******************************************************************************
*     File Name           :     tui.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2016-11-23 15:14]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "tui.h"
#include "src/state/map/obj/sprite.h"
#include "src/state/map/obj/block/block.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/fifo/fifo.h"
#include "src/state/map/map.h"
#include "debug/debug.h"
/*****************************************************************************/
static int draw_blocks(tui_t *tui, map_t *map);
static int draw_units(tui_t *tui, unit_t *unit);
static int focus_camera(tui_t *tui, map_t *map);
/*****************************************************************************/
tui_t *init_tui(map_t *map) {
    tui_t *tui = malloc(sizeof(tui));
    tui->win = newwin(WINDOW_HEIGHT*TILE_SIZE, WINDOW_WIDTH*TILE_SIZE, 0, 0);
    tui->camera = 0;

    return tui;
}
/*---------------------------------------------------------------------------*/
int draw_win(tui_t *tui, map_t *map) {
    focus_camera(tui, map);
    redrawwin(tui->win);

    draw_blocks(tui, map);
    draw_units(tui, (unit_t*)map->player);
    draw_units(tui, map->unit);

    wrefresh(tui->win);
    return 0;
}
/*---------------------------------------------------------------------------*/
static int focus_camera(tui_t *tui, map_t *map) {
    unit_t *iter;
    int mean = 0;
    for(iter = (unit_t*)map->player; iter != NULL; iter = iter->next) {
        mean += iter->pos.x;
    }
    mean = mean/map->num_players;
    if((mean - WINDOW_WIDTH >= 0) && (mean + WINDOW_WIDTH < map->width)) {
        tui->camera = mean - WINDOW_WIDTH;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw_blocks(tui_t *tui, map_t *map) {
    int i;
    int j;

    for(i = 0; i < WINDOW_HEIGHT; i++) {
        for(j = 0; j < WINDOW_WIDTH; j++) {
            draw_block(tui, i, j, &map->block[i][j+tui->camera]);
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
//static int redraw_blocks(WINDOW *pad, map_t *map) {
//    vecti_t *pos;
//    while((pos = (vecti_t*)pop_node(&map->redraw_block)) != NULL) {
//        draw_block(pad, pos->y, pos->x, &map->block[pos->y][pos->x]);
//    }
//    return 0;
//}
/*---------------------------------------------------------------------------*/
static int draw_units(tui_t *tui, unit_t *unit) {
    unit_t *iter;
    for(iter = unit; iter != NULL; iter = iter->next) {
        iter->draw(tui, iter);
    }
    return 0;
}
