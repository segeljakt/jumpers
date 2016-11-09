/******************************************************************************
*     File Name           :     args.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 14:00]                            *
*     Last Modified       :     [2016-11-09 22:58]                            *
*     Description         :     Argument parser.                              *
******************************************************************************/
#include "args.h"
#include <unistd.h>     // getopt
#include <stdlib.h>     // calloc
/*****************************************************************************/
#define ARGS "pdof"
/*****************************************************************************/
enum ARG {
    ARG_DIFFICULTY = 'd',
    ARG_FILEPATH   = 'f',
    ARG_ONLINE     = 'o',
    ARG_PLAYERS    = 'p'
};
/*****************************************************************************/
args_t *parse_args(int argc, char *argv[]) {
    args_t *args = calloc(1, sizeof(args_t));
    int opt;
    while((opt = getopt(argc, argv, ARGS)) != -1) {
        switch (opt) {
            case ARG_DIFFICULTY: {
                args->difficulty = atoi(optarg);
                break;
            } case ARG_FILEPATH: {
                args->fp = optarg;
                break;
            } case ARG_ONLINE: {
                args->online = 1;
                break;
            } case ARG_PLAYERS: {
                args->num_players = atoi(optarg);
                break;
            }
        }
    }
    return args;
}
/*****************************************************************************/
int free_args(args_t *args) {
    free(args->fp);
    free(args);
    return 0;
}
