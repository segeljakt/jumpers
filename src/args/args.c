/******************************************************************************
*     File Name           :     args.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 14:00]                            *
*     Last Modified       :     [2016-10-30 17:09]                            *
*     Description         :     Argument parser.                              *
******************************************************************************/
#include <unistd.h>     // getopt
#include "args.h"
/*****************************************************************************/
#define ARG_PLAYERS    "p"
#define ARG_DIFFICULTY "d"
#define ARG_ONLINE     "o"
#define ARGS ARG_PLAYERS ARG_DIFFICULTY ARG_ONLINE
/*****************************************************************************/
int parse_args(int argc, char *argv[], state_t *state) {
    if(argc > 1) {
        int opt;
        while((opt = getopt(argc, argv, ARGS)) != -1) {
            switch (opt) {
                case 'o': {
                    state->opts.peer = optarg;
                    break;
                }
            }
        }
    }
}
