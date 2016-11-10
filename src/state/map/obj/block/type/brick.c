/******************************************************************************
*     File Name           :     brick.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 13:08]                            *
*     Last Modified       :     [2016-11-10 23:26]                            *
*     Description         :     Brick block (breakable).                      *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int ctop(unit_t *player, block_t *self, map_t *map);
static int cside(unit_t *player, block_t *self, map_t *map);
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_brick_block(int y, int x, map_t *map) {
    block_t block;
    block.ctop = cblock;
    block.cside = cblock;
    block.cbot = cbot;
    block.ch = CHAR_BRICK_BLOCK;
    return 0;
}
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    self->status = DEAD;
    return 0;
}
