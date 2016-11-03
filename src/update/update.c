/******************************************************************************
*     File Name           :     update.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 11:34]                            *
*     Last Modified       :     [2016-10-30 17:09]                            *
*     Description         :     Update the game state.                        *
******************************************************************************/
#include "update.h"
/*****************************************************************************/
static int update_units(state_t *state, input_t *input) {
    unit_t *iter;
    for(iter = state->map->unit; iter != NULL; iter = iter->next) {
        iter->action(state->map, iter);
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
int update(state_t *state, input_t *input) {
    return 0;
}
