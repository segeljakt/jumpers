/******************************************************************************
*     File Name           :     state.h                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:34]                            *
*     Last Modified       :     [2016-11-10 19:02]                            *
*     Description         :     Game state.                                   *
******************************************************************************/
#ifndef STATE_H
#define STATE_H
/*****************************************************************************/
#include <ncurses.h>
#include "src/state/map/map.h"
#include "src/state/online/online.h"
#include "src/state/input/input.h"
#include "src/state/serialize/serialize.h"
#include "src/state/gfx/gfx.h"
/*****************************************************************************/
typedef struct state_s state_t;
/*****************************************************************************/
struct state_s {
    map_t *map;
    gfx_t *gfx;
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
