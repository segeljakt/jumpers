/******************************************************************************
*     File Name           :     tui.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-09 10:29]                            *
*     Last Modified       :     [2017-01-11 21:35]                            *
*     Description         :     Ncurses graphics.                             *
******************************************************************************/
#include "tui.h"
#include "src/state/map/obj/sprite.h"
#include "src/state/map/obj/block/block.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/fifo/fifo.h"
#include "src/state/map/map.h"
#include "debug/debug.h"
#include "src/state/map/obj/unit/player/player.h"
/*****************************************************************************/
static int draw_blocks(tui_t *tui, map_t *map);
static int draw_units(tui_t *tui, unit_t *unit, map_t *map);
static int draw_border();
/*****************************************************************************/
tui_t *init_tui(map_t *map) {
    tui_t *tui = malloc(sizeof(tui));
    tui->win = subwin(stdscr,
                      WINDOW_HEIGHT*TILE_SIZE, WINDOW_WIDTH*TILE_SIZE+1,
                      2, 1);
//    tui->dbg = newwin(WINDOW_HEIGHT*TILE_SIZE, WINDOW_WIDTH*TILE_SIZE,
//                      0, WINDOW_WIDTH*TILE_SIZE+4);
    draw_border();
    refresh();

    return tui;
}
/*****************************************************************************/
int draw_border() {
    mvaddch(0, 0, '$');
    mvaddch(0, WINDOW_WIDTH*TILE_SIZE+2, '&');
    mvaddch(WINDOW_WIDTH*TILE_SIZE+2, 0, '|');
    mvaddch(WINDOW_WIDTH*TILE_SIZE+2, WINDOW_WIDTH*TILE_SIZE+2, '~');
    mvhline(0, 1, '%', WINDOW_WIDTH*TILE_SIZE+1);
    mvhline(WINDOW_WIDTH*TILE_SIZE+2, 1, '}', WINDOW_WIDTH*TILE_SIZE);
    mvvline(1, 0, ';', WINDOW_WIDTH*TILE_SIZE+1);
    mvvline(1, WINDOW_WIDTH*TILE_SIZE+2, '=', WINDOW_WIDTH*TILE_SIZE+1);

    return 0;
}
/*---------------------------------------------------------------------------*/
int draw_win(tui_t *tui, map_t *map) {
    werase(tui->win);
    redrawwin(tui->win);

    focus_camera(map);
    draw_blocks(tui, map);
    draw_units(tui, (unit_t*)map->player, map);
    draw_units(tui, map->unit, map);

    draw_border();
    wrefresh(tui->win);

//    werase(tui->dbg);
//    mvwprintw(tui->dbg, 0, 0, "map->camera  : %g", map->camera);
//    mvwprintw(tui->dbg, 1, 0, "player (x,y) : (%g, %g)",
//              map->player->pos.x, map->player->pos.y);
//    wrefresh(tui->dbg);
    return 0;
}
/*---------------------------------------------------------------------------*/
static int draw_blocks(tui_t *tui, map_t *map) {
    int i;
    int j;
    int xaligned = ((int)(map->camera*TILE_SIZE)%TILE_SIZE == 0);
//    werase(tui->dbg);
//    mvwprintw(tui->dbg, 0, 0, "map->camera  : %g", map->camera);
//    mvwprintw(tui->dbg, 1, 0, "player (x,y) : (%g, %g)",
//              map->player->pos.x, map->player->pos.y);
//    mvwprintw(tui->dbg, 2, 0, "xaligned     : %d", xaligned);
//    wrefresh(tui->dbg);
    for(i = 0; i < WINDOW_HEIGHT; i++) {
        for(j = 0; j < WINDOW_WIDTH + !xaligned; j++) {
            mvwaddch(tui->win, i*TILE_SIZE, j*TILE_SIZE+xaligned,
                    map->block[i][j+(int)map->camera].ch);
        }
    }
    return 0;
}
//static int draw_blocks(tui_t *tui, map_t *map) {
//    int i;
//    int j;
//    float dif =  map->camera - (int)map->camera;
//    int odd = dif*TILE_SIZE;
//    for(i = 0; i < WINDOW_HEIGHT; i++) {
//        for(j = odd; j < WINDOW_WIDTH-odd; j++) {
//            mvwaddch(tui->win,
//                     i*TILE_SIZE,
//                     (j - dif)*TILE_SIZE,
//                     map->block[i][j+(int)map->camera].ch);
//            draw_block(tui, i, (j-map->camera)*TILE_SIZE,
//                    &map->block[i][j], map->camera);
//        }
//    }
//    return 0;
//}
/*---------------------------------------------------------------------------*/
//static int redraw_blocks(WINDOW *pad, map_t *map) {
//    vecti_t *pos;
//    while((pos = (vecti_t*)pop_node(&map->redraw_block)) != NULL) {
//        draw_block(pad, pos->y, pos->x, &map->block[pos->y][pos->x]);
//    }
//    return 0;
//}
/*---------------------------------------------------------------------------*/
static int draw_units(tui_t *tui, unit_t *unit, map_t *map) {
    unit_t *iter;
    for(iter = unit; iter != NULL; iter = iter->next) {
        iter->draw(tui, iter, map);
    }
    return 0;
}
