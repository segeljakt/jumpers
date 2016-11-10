/******************************************************************************
*     File Name           :     map.h                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-10 13:57]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#ifndef MAP_H
#define MAP_H
/*****************************************************************************/
typedef struct block_s block_t;
typedef struct unit_s unit_t;
typedef struct player_s player_t;
/*---------------------------------------------------------------------------*/
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
