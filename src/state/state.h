/******************************************************************************
*     File Name           :     state.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:34]                            *
*     Last Modified       :     [2016-11-05 12:12]                            *
*     Description         :     Game state.                                   *
******************************************************************************/
#ifndef STATE_H
#define STATE_H
/*****************************************************************************/
#include "src/type.h"
#include <stdlib.h>
#include <ncurses.h>
#include "src/map/map.h"
#include "src/online/online.h"
/*****************************************************************************/
struct change_s {
    void *data;
    size_t len;
    change_t *next;
};
/*---------------------------------------------------------------------------*/
struct state_s {
    map_t *map;
    WINDOW *pad;
    online_t *online;
    change_t *change;
    char *fp;
    int difficulty;
    int seq;
};
/*****************************************************************************/
state_t *init_state();
void serialize(state_t *state);
void free_state(state_t *state);
void update(state_t *state);
/*****************************************************************************/
#endif // STATE_H
