/******************************************************************************
*     File Name           :     tui.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2016-11-16 17:04]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "tui.h"
#include "src/state/map/obj/sprite.h"
#include "src/state/map/obj/block/block.h"
#include "src/state/map/fifo/fifo.h"
#include "debug/debug.h"
/*****************************************************************************/
static int draw_blocks(WINDOW *pad, map_t *map);
static int redraw_blocks(WINDOW *pad, map_t *map);
static int draw_units(WINDOW *pad, unit_t *unit);
static int focus_camera(tui_t *tui, map_t *map);
/*****************************************************************************/
tui_t *init_tui(map_t *map) {
    tui_t *tui = malloc(sizeof(tui));
    tui->pad = stdscr;//newpad(map->height*BLOCK_SPACING,
                      //map->width*BLOCK_SPACING);
    tui->draw.x = WINDOW_WIDTH*BLOCK_SPACING;
    tui->draw.y = WINDOW_HEIGHT*BLOCK_SPACING;

//    focus_camera(tui, map);
    draw_blocks(tui->pad, map);
//    prefresh(tui->pad, 0, 0, 0, 0,
//             WINDOW_HEIGHT*BLOCK_SPACING,
//             WINDOW_WIDTH*BLOCK_SPACING);

    return tui;
}
/*---------------------------------------------------------------------------*/
int draw(map_t *map, tui_t *tui) {

//    werase(tui->pad);
    redrawwin(tui->pad);
//    wrefresh(tui->pad);
//    prefresh(tui->pad,
//             0, 0,
//             0, 0,
//             WINDOW_HEIGHT*BLOCK_SPACING,
//             WINDOW_WIDTH*BLOCK_SPACING);

    draw_blocks(tui->pad, map);
//    redraw_blocks(tui->pad, map);
//    draw_empty_blocks(tui->pad, map);
    draw_units(tui->pad, (unit_t*)map->player);
    draw_units(tui->pad, map->unit);

//    prefresh(tui->pad,
//             0, 0,
//             0, 0,
//             WINDOW_HEIGHT*BLOCK_SPACING,
//             WINDOW_WIDTH*BLOCK_SPACING);
    wrefresh(tui->pad);
    return 0;
}
/*---------------------------------------------------------------------------*/
static int focus_camera(tui_t *tui, map_t *map) {
    unit_t *iter;
    int x;
    for(iter = (unit_t*)map->player; iter != NULL; iter = iter->next) {
        x += iter->pos.x;
    }
    x = x/map->num_players;
    if((x > WINDOW_WIDTH/2) || (x < map->width - WINDOW_WIDTH/2)) {
        tui->camera = x;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw_blocks(WINDOW *pad, map_t *map) {
    int i;
    int j;

    for(i = 0; i < map->height; i++) {
        for(j = 0; j < map->width; j++) {
            draw_block(pad, i, j, &map->block[i][j]);
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int redraw_blocks(WINDOW *pad, map_t *map) {
    vecti_t *pos;
    while((pos = (vecti_t*)pop_node(&map->redraw_block)) != NULL) {
        draw_block(pad, pos->y, pos->x, &map->block[pos->y][pos->x]);
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw_units(WINDOW *pad, unit_t *unit) {
    unit_t *iter;
    for(iter = unit; iter != NULL; iter = iter->next) {
        iter->draw(pad, iter);
    }
    return 0;
}
