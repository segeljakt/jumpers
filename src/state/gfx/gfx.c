/******************************************************************************
*     File Name           :     gfx.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2016-11-09 23:15]                     *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "gfx.h"
/*****************************************************************************/
int setup_scr() {
    initscr();
    return 0;
}
/*---------------------------------------------------------------------------*/
int teardown_scr() {
    endwin();
    return 0;
}
/*---------------------------------------------------------------------------*/
int draw_blocks(WINDOW *pad, block_t **block, int width, int height) {
    int i;
    int j;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            block[i][j].draw(pad, &block[i][j]);
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

    draw_blocks(gfx->pad, map->block, map->height, map->width);
    draw_units(gfx->pad, (unit_t*)map->player);
    draw_units(gfx->pad, map->unit);

    return 0;
}
