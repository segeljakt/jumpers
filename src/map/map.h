/******************************************************************************
*     File Name           :     structdef.h                                   *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-02 23:36]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#ifndef MAP_H
#define MAP_H
/*****************************************************************************/
#include "src/map/block/block.h"
#include "src/map/unit/unit.h"
#include "src/map/player/player.h"
#include "src/map/cfg.h"
#include "src/input/keycodes.h"
/*****************************************************************************/
typedef struct map_s map_t;
typedef struct player_s player_t;
typedef struct unit_s unit_t;
typedef struct block_s block_t;
/*****************************************************************************/
enum DIRECTIONS {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};
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
/*****************************************************************************/
#endif // MAP_H
/*****************************************************************************/
