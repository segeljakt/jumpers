/******************************************************************************
*     File Name           :     state.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:34]                            *
*     Last Modified       :     [2016-11-03 01:01]                            *
*     Description         :     Game state.                                   *
******************************************************************************/
#ifndef STATE_H
#define STATE_H
/*****************************************************************************/
#include <stdlib.h>
#include <ncurses.h>
#include "src/map/map.h"
/*****************************************************************************/
typedef struct opts_s opts_t;
typedef struct state_s state_t;
/*****************************************************************************/
struct state_s {
    map_t *map;
    WINDOW *pad;
    char *filepath;
    int difficulty;
    char active;
};
/*****************************************************************************/
state_t *init_state();
/*****************************************************************************/
#endif // STATE_H
