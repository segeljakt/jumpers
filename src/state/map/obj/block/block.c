/******************************************************************************
*     File Name           :     block.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-08 11:00]                            *
*     Last Modified       :     [2017-01-15 10:06]                            *
*     Description         :     Block interface.                              *
******************************************************************************/
#include "block.h"
/*****************************************************************************/
int kill_block(map_t *map, int y, int x) {
    vecti_t *pos = malloc(sizeof(vecti_t));
    pos->y = y;
    pos->x = x;
    map->block[pos->y][pos->x].has_collision = 0;
    map->block[pos->y][pos->x].ch = CHAR_NONE;
    insert_node(&map->redraw_block, new_node(pos));
    return 0;
}
/*---------------------------------------------------------------------------*/
int draw_block(tui_t *tui, int y, int x, block_t *block, float camera) {
//    wattron(tui->win, block->color_attribute);
    mvwaddch(tui->win, y*TILE_SIZE, x*TILE_SIZE, block->ch);
//    wattroff(tui->win, block->color_attribute);
    return 0;
}
/*---------------------------------------------------------------------------*/
#include <math.h>
int block_collision(unit_t *unit, map_t *map) {
    char i;
    char j;
    char dx;
    char dy;
    char yaligned;
    char xaligned;
    block_t *block;
    dy = (int)(unit->pre.y*TILE_SIZE)-(int)(unit->pos.y*TILE_SIZE);
    xaligned = ((int)(unit->pre.x*TILE_SIZE)%TILE_SIZE==0);
    yaligned = ((int)(unit->pre.y*TILE_SIZE)%TILE_SIZE==0);
    // Y-collision
    if(yaligned) {
        for(j = 0; j <= unit->len.x - xaligned; j++) {
            int x = unit->pre.x+j;
            int y = unit->pos.y;
            if(dy < 0) { // dy < 0 (if moving downwards, check bottom)
                y += unit->len.y;
            }
            block = &map->block[y][x];
            if(block->has_collision) {
                if(dy < 0) { // top
                    block->ctop(unit, block, map);
                } else {     // bot
                    block->cbot(unit, block, map);
                }
            }
        }
    }
    dx = (int)(unit->pre.x*TILE_SIZE)-(int)(unit->pos.x*TILE_SIZE);
    // X-collision
    if(xaligned) {
        for(i = 0; i <= unit->len.y - yaligned; i++) {
            int y = unit->pre.y+i;
            int x = unit->pos.x;
            if(dx < 0) {
                x += unit->len.x;
            }
            block = &map->block[y][x];
            if(block->has_collision) {
                block->cside(unit, block, map);
            }
        }
    }
    // XY-collision
    if(1) {
        int y = unit->pos.y;
        int x = unit->pos.x;
        block = &map->block[y][x];
        if(block->has_collision) {
            block->ctop(unit, block, map);
            block->cside(unit, block, map);
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
int cbnone(unit_t *player, block_t *self, map_t *map) {
    return 0;
}
/*---------------------------------------------------------------------------*/
int cbtop(unit_t *player, block_t *self, map_t *map) {
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    player->on_ground = 1;
    return 0;
}
/*---------------------------------------------------------------------------*/
int cbside(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->vel.x = 0;
    return 0;
}
/*---------------------------------------------------------------------------*/
int cbbot(unit_t *player, block_t *self, map_t *map) {
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    return 0;
}
