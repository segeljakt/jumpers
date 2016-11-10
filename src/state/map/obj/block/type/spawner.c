/******************************************************************************
*     File Name           :     spawner.c                                     *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 23:12]                            *
*     Last Modified       :     [AUTO_UPDATE_BEFORE_SAVE]                     *
*     Description         :     Spawner block.                                *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
typedef struct spawn_s spawn_t;
typedef int (*spawn_f)(int, int, map_t*);
/*****************************************************************************/
struct spawner_s {
    block_t;
    spawn_f spawn;
};
/*****************************************************************************/
int new_spawner_block()
