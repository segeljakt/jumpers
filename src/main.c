/******************************************************************************
*     File Name           :     main.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:33]                            *
*     Last Modified       :     [2016-11-08 14:44]                            *
*     Description         :     Game loop.                                    *
******************************************************************************/
#include <ncurses.h>
#include "src/state/state.h"
#include "src/cfg.h"
#include "src/input/input.h"
#include "src/update/update.h"
#include "src/online/online.h"
#include "src/gfx/gfx.h"
/*****************************************************************************/
int main(int argc, char *argv[]) {

    /* Setup */
    state_t *state = init_state(argc, argv);

    if(state == NULL) {
        exit(-1);
    }

    while(read_input(state->map->player)) {
        update(state);
        serialize(state);
        synchronize(state);
        render(state);
        napms(TICKRATE);
    }

    /* Teardown */
    free_state(state);

    return 0;
}
