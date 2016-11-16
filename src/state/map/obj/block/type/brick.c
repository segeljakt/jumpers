/******************************************************************************
*     File Name           :     brick.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 13:08]                            *
*     Last Modified       :     [2016-11-15 13:19]                            *
*     Description         :     Brick block (breakable).                      *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_brick_block(int y, int x, map_t *map) {
    map->block[y][x].ctop = cbtop;
    map->block[y][x].cside = cbside;
    map->block[y][x].cbot = cbot;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = CHAR_BRICK_BLOCK;
    return 0;
}
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    int y = (int)player->pos.y-1;
    int x = (int)player->pos.x;
    if(player->status & BIG) {
        kill_block(map, y, x);
    }
    unit_t *iter;
    for(iter = map->unit; iter != NULL; iter = iter->next) {
        if(iter->pos.x == x
        && iter->pos.y == y) {
            kill_unit(&iter);
        }
    }
    return 0;
}
