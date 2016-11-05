/******************************************************************************
*     File Name           :     map.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-05 14:04]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#ifndef MAP_H
#define MAP_H
/*****************************************************************************/
#include <ncurses.h>
#include "src/type.h"
#include "src/map/block/block.h"
#include "src/map/unit/unit.h"
#include "src/map/player/player.h"
#include "src/map/cfg.h"
#include "src/gfx/gfx.h"
/*****************************************************************************/
struct map_s {
    int height;
    int width;
    block_t **block;
    unit_t *unit;
    player_t *local_player;
    int num_local_players;
    player_t *remote_player;
};
/*****************************************************************************/
map_t *init_map(char *filepath);
WINDOW *draw_map(map_t *map);
void free_map(map_t *map);
/*****************************************************************************/
#endif // MAP_H
/*****************************************************************************/
