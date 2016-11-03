/******************************************************************************
*     File Name           :     state.c                                       *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:40]                            *
*     Last Modified       :     [2016-11-03 01:01]                            *
*     Description         :     State functions.                              *
******************************************************************************/
#include "state.h"
#include "src/args/args.h"
#include <string.h>
/*****************************************************************************/
static const char *default_filepath = "~/.mario/levels/map_1.txt";
/*****************************************************************************/
state_t *init_state(int argc, char *argv[]) {
    args_t *args = parse_args(argc, argv);
    state_t *state = malloc(sizeof(state_t));
    int i;
    /* Initialize map */
    if(args->filepath = 0) {
        state->filepath = strdup(default_filepath);
    } else {
        state->filepath = args->filepath;
    }
    state->map = init_map(state->filepath);
    /* Create players */
    for(i = 0; i < args->num_players; i++) {
        new_player(state->map, -1, -1);
    }
    /* Set difficulty */
    state->difficulty = args->difficulty;
    /* */
    free_args(args);
    return state;
}
