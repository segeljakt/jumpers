/******************************************************************************
*     File Name           :     state.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:40]                            *
*     Last Modified       :     [2016-10-29 23:52]                            *
*     Description         :     State functions.                              *
******************************************************************************/
#include "state.h"
/*****************************************************************************/
state_t *init_state(int argc, char *argv[]) {
    state_t *state = malloc(sizeof(state_t));
    return state;
}
