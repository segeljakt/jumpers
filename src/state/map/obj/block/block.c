/******************************************************************************
*     File Name           :     block.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-08 11:00]                            *
*     Last Modified       :     [2016-11-13 00:19]                            *
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
    wattron(pad, block->color_attribute);
    mvwaddch(pad, y, x, block->ch);
    wattroff(pad, block->color_attribute);
    return 0;
}
/*---------------------------------------------------------------------------*/
int block_collision(unit_t *unit, map_t *map) {
    block_t *block = &map->block[(int)unit->pos.y][(int)unit->pos.x];

    if(block->has_collision) {
        float w = (unit->len.x + BLOCKLENGTH)/2;
        float h = (unit->len.y + BLOCKLENGTH)/2;
        float dx = unit->cen.x - ((int)unit->pos.x+BLOCKLENGTH/2);
        float dy = unit->cen.y - ((int)unit->pos.y+BLOCKLENGTH/2);

        float wy = w*dy;
        float hx = h*dx;

        if (wy > hx) {
            if (wy > -hx) {
                /* bottom */
                block->ctop(unit, block, map);
            } else {
                /* left */
                block->cside(unit, block, map);
            }
        } else {
            if (wy > -hx) {
                /* right */
                block->cside(unit, block, map);
            } else {
                /* top */
                block->cbot(unit, block, map);
            }
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
int cblock(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->pos.y = player->pre.y;
    return 0;
}
/*---------------------------------------------------------------------------*/
int cbnone(unit_t *player, block_t *self, map_t *map) {
    return 0;
}
