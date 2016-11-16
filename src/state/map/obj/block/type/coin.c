/******************************************************************************
*     File Name           :     coin.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 23:49]                            *
*     Last Modified       :     [2016-11-11 19:36]                            *
*     Description         :     Coin block.                                   *
******************************************************************************/
#include "../block.h"
#include "src/state/map/obj/unit/player/player.h"
/*****************************************************************************/
static int ccoin(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_coin_block(int y, int x, map_t *map) {
    map->block[y][x].ctop = cbtop;
    map->block[y][x].cside = cbside;
    map->block[y][x].cbot = ccoin;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = CHAR_BRICK_BLOCK;
    return 0;
}
/*****************************************************************************/
static int ccoin(unit_t *player, block_t *self, map_t *map) {
    player->pos.y = player->pre.y;
    player->pos.x = player->pre.x;
    player->vel.y = 0;
    player_t *p = (player_t*)player;
    p->coins++;
    return 0;
}
