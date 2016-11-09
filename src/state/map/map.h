/******************************************************************************
*     File Name           :     map.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-09 23:14]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#ifndef MAP_H
#define MAP_H
/*****************************************************************************/
#include "src/state/map/obj/block/block.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/obj/unit/player/player.h"
/*****************************************************************************/
typedef struct map_s map_t;
/*****************************************************************************/
struct map_s {
    int height;
    int width;
    block_t **block;
    unit_t *unit;
    player_t *player;
    int num_local_players;
    int num_units;
};
/*****************************************************************************/
map_t *init_map(char *filepath);
void free_map(map_t *map);
/*****************************************************************************/
#endif // MAP_H
