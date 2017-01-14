/******************************************************************************
*     File Name           :     main.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:33]                            *
*     Last Modified       :     [2017-01-09 23:32]                            *
*     Description         :     Game loop.                                    *
******************************************************************************/
#include "src/state/state.h"
#include <unistd.h>
/*****************************************************************************/
int main(int argc, char *argv[]) {

    /* Setup */
    state_t *state = init_state(argc, argv);

    if(state == NULL) {
        exit(-1);
    }

    while(read_input(state->map->player)) {
        update(state);
//        serialize(state);
//        synchronize(state->online, state->change);
        draw_win(state->tui, state->map);
        usleep(TICKRATE*1000);
        flushinp();
    }

    /* Teardown */
    free_state(state);

    exit(0);
}
