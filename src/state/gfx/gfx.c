/******************************************************************************
*     File Name           :     gfx.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2016-11-13 20:53]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "gfx.h"
#include "src/state/map/obj/sprite.h"
#include "src/state/map/obj/block/block.h"
#include "src/state/map/fifo/fifo.h"
/*****************************************************************************/
static int draw_blocks(WINDOW *pad, map_t *map);
static int redraw_blocks(WINDOW *pad, map_t *map);
static int draw_units(WINDOW *pad, unit_t *unit);
/*****************************************************************************/
gfx_t *init_gfx(map_t *map) {
    gfx_t *gfx = malloc(sizeof(gfx));
    gfx->pad = newpad(map->height, map->width);
    gfx->draw.x = WINDOW_WIDTH;
    gfx->draw.y = WINDOW_HEIGHT;
    draw_blocks(gfx->pad, map);
    prefresh(gfx->pad, 0, 0, 0, 0, WINDOW_HEIGHT, WINDOW_WIDTH);
    return gfx;
}
/*---------------------------------------------------------------------------*/
int draw(map_t *map, gfx_t *gfx) {

    redraw_blocks(gfx->pad, map);
    draw_units(gfx->pad, (unit_t*)map->player);
    draw_units(gfx->pad, map->unit);

    prefresh(gfx->pad, 0, 0, 0, 0, WINDOW_HEIGHT, WINDOW_WIDTH);
    return 0;
}
/*---------------------------------------------------------------------------*/
int setup_scr() {
    initscr();
    start_color();
    init_pair(COLOR_RED_NONE, COLOR_RED, -1);
    init_pair(COLOR_BLUE_NONE, COLOR_BLUE, -1);
    return 0;
}
/*---------------------------------------------------------------------------*/
int teardown_scr() {
    endwin();
    return 0;
}
/*---------------------------------------------------------------------------*/
int draw_blocks(WINDOW *pad, map_t *map) {
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
int redraw_blocks(WINDOW *pad, map_t *map) {
    vecti_t *pos;
    while((pos = (vecti_t*)pop_node(&map->redraw_block)) != NULL) {
        draw_block(pad, pos->y, pos->x, &map->block[pos->y][pos->x]);
    }
    return 0;
}
/*****************************************************************************/
int draw_units(WINDOW *pad, unit_t *unit) {
    unit_t *iter;
    for(iter = unit; iter != NULL; iter = iter->next) {
        iter->draw(pad, iter);
    }
    return 0;
}
