/******************************************************************************
*     File Name           :     gfx.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2016-11-10 19:08]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "gfx.h"
#include "src/state/map/obj/sprite.h"
/*****************************************************************************/
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
            draw_block(&map->block[i][j]);
        }
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
/*****************************************************************************/
gfx_t *init_gfx(map_t *map) {
    gfx_t *gfx = malloc(sizeof(gfx));
    gfx->pad = newpad(map->height, map->width);

    return gfx;
}
/*****************************************************************************/
int draw(map_t *map, gfx_t *gfx) {

    draw_blocks(gfx->pad, map);
    draw_units(gfx->pad, (unit_t*)map->player);
    draw_units(gfx->pad, map->unit);

    return 0;
}
