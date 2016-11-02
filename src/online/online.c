/******************************************************************************
*     File Name           :     online.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 12:32]                            *
*     Last Modified       :     [2016-11-02 17:11]                            *
*     Description         :     Peer-to-peer online multiplayer.              *
******************************************************************************/
#include "online.h"
/*****************************************************************************/
int setup_online(state_t *state) {
    if(state->opts.peer)
}
/*---------------------------------------------------------------------------*/
static int multicast(peer_t *peer, state_t *state) {
    peer_t *iter;
    for(iter = peer; iter != NULL; iter = iter->next) {

    }
}
/*---------------------------------------------------------------------------*/
static int join(peer_t *peer, state_t **state) {
    return 0;
}
/*---------------------------------------------------------------------------*/
static int sync(peer_t *peer, state_t *state) {
    return 0;
}
/*---------------------------------------------------------------------------*/
static int online(peer_t *peer, state_t *state) {
    while(state->active) {
        multicast(peer, state_t *state);
        sync(peer, state_t *state);
    }
}
