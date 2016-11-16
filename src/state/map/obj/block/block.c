/******************************************************************************
*     File Name           :     block.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-08 11:00]                            *
*     Last Modified       :     [2016-11-16 22:04]                            *
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
int draw_block(WINDOW *pad, int y, int x, block_t *block) {
//    wattron(pad, block->color_attribute);
    mvwaddch(pad, y*BLOCK_SPACING, x*BLOCK_SPACING, block->ch);
//    wattroff(pad, block->color_attribute);
    return 0;
}
/*---------------------------------------------------------------------------*/
#include <math.h>
int block_collision(unit_t *unit, map_t *map) {
    vecti_t pre;
    vecti_t pos;
    vecti_t dif;
    pre.x = (int)(unit->pre.x*BLOCK_SPACING);
    pre.y = (int)(unit->pre.y*BLOCK_SPACING);
    pos.x = (int)(unit->pos.x*BLOCK_SPACING);
    pos.y = (int)(unit->pos.y*BLOCK_SPACING);
    dif.x = pre.x-pos.x;
    dif.y = pre.y-pos.y;
    // X-collision
    if((pre.x != pos.x)) {
        int x = (dif.x < 0)? (int)round(unit->pos.x):(int)unit->pos.x;
        int y = (dif.y < 0)? (int)round(unit->pre.y):(int)unit->pre.y;
//        int y = (int)unit->pre.y;
        block_t *xblock = &map->block[y][x];
        if(xblock->has_collision) {
            xblock->cside(unit, xblock, map);
        }
    }
    // Y-collision
    if((pre.y != pos.y)) {
//        int x = (int)unit->pre.x;
        int x = (dif.x < 0)? (int)round(unit->pre.x):(int)unit->pre.x;
        int y = (dif.y < 0)? (int)round(unit->pos.y):(int)unit->pos.y;
        block_t *yblock  = &map->block[y][x];
        if(yblock->has_collision) {
            if(unit->pos.y > unit->pre.y) {
                yblock->ctop(unit, yblock, map);
            } else {
                yblock->cbot(unit, yblock, map);
            }
        }
    }
    // XY-collision
    if((pre.x != pos.x) && (pre.y != pos.y)) {
        int x = (dif.x < 0)? (int)round(unit->pos.x):(int)unit->pos.x;
        int y = (dif.y < 0)? (int)round(unit->pos.y):(int)unit->pos.y;
        block_t *xyblock = &map->block[y][x];
        if(xyblock->has_collision) {
            xyblock->cside(unit, xyblock, map);
            if(unit->pos.y > unit->pre.y) {
                xyblock->ctop(unit, xyblock, map);
            } else {
                xyblock->cbot(unit, xyblock, map);
            }
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
