/******************************************************************************
*     File Name           :     main.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-29 23:33]                            *
*     Last Modified       :     [2016-11-02 22:20]                            *
*     Description         :     Game loop.                                    *
******************************************************************************/
#include <ncurses.h>
#include "src/state/state.h"
#include "src/cfg.h"
#include "src/input/input.h"
#include "src/update/update.h"
#include "src/online/online.h"
/*****************************************************************************/
int main(int argc, char *argv[]) {
    state_t *state = init_state(argc, argv);

    if(state->opts.peer) {
        if(setup_online(&state) != 0) {
            return 0;
        }
    } else if(state->opts.host) {
        
    }else {
        state->
    }
    initscr();

    while(read_input(input)) {
        update(state, input);
        sync(state);
        napms(TICKRATE);
    }

    state->active = false;

    endwin();

    return 0;
}

