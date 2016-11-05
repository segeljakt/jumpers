/******************************************************************************
*     File Name           :     update.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 11:34]                            *
*     Last Modified       :     [2016-11-04 20:43]                            *
*     Description         :     Update the game state.                        *
******************************************************************************/
#include "update.h"
/*****************************************************************************/
static int update_units(map_t *map) {
    unit_t *iter;
    for(iter = map->unit; iter != NULL; iter = iter->next) {
        iter->update(map, iter);
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int update_players(map_t *map) {
    player_t *iter;
    for(iter = map->local_player; iter != NULL; iter = iter->next) {
        iter->update(map, iter);
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
int update(state_t *state) {
    update_players(state->map);
    update_units(state->map);
    return 0;
}
