/******************************************************************************
*     File Name           :     block.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-01 22:12]                            *
*     Last Modified       :     [2016-11-01 22:14]                            *
*     Description         :     Block in map.                                 *
******************************************************************************/
#ifndef BLOCK_H
#define BLOCK_H
/*****************************************************************************/
#include "src/map/map.h"
/*****************************************************************************/
typedef struct block_s block_t;
typedef struct map_s map_t;
typedef void (*block_action_f)(map_t*, block_t*);
/*****************************************************************************/
struct block_s {
    char c;
    void *data;
    block_action_f action;
};
/*****************************************************************************/
void normal_block_collision(map_t *map, block_t *block);
void coin_block_collision(map_t *map, block_t *block);
/*****************************************************************************/
#endif // BLOCK_H
