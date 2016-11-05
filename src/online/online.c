/******************************************************************************
*     File Name           :     online.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 12:32]                            *
*     Last Modified       :     [2016-11-04 08:40]                            *
*     Description         :     Peer-to-peer online multiplayer.              *
******************************************************************************/
#include "online.h"
/*****************************************************************************/
static const char join_msg = 'j';
static const char ack_msg = 'a';
/*****************************************************************************/
static void multicast(online_t *online, change_t *change) {
    peer_t *iter;
    for(iter = online->peer; iter != NULL; iter = iter->next) {
        send(online->socket, change->data, change->len, 0);
    }
}
/*---------------------------------------------------------------------------*/
static int receive(online_t *online) {
    struct sockaddr_in client;
//    recvfrom(online->socket, online->buf, );
    return 0;
}
/*---------------------------------------------------------------------------*/
static int join(online_t *online) {

    send(online->socket, &join_msg, sizeof(join_msg), 0);
    ssize_t size = recv(online->socket, online->buf, online->bufsize, 0);
    if(size == sizeof(ack_msg)) {
        if(*online->buf == ack_msg) {
            
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
int synchronize(state_t *state) {
    change_t *iter;
    for(iter = state->change; iter != NULL; iter = iter->next) {
        multicast(state->online, iter);
    }
    return 0;
}
