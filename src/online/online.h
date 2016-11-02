/******************************************************************************
*     File Name           :     online.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 11:54]                            *
*     Last Modified       :     [2016-11-02 17:11]                            *
*     Description         :     Peer-to-peer online multiplayer.              *
******************************************************************************/
#ifndef ONLINE_H
#define ONLINE_H
/*****************************************************************************/
#include <sys/socket.h>         // socket, connect
#include <netinet/in.h>         // struct sockaddr_in, struct sockaddr
#include "src/state/state.h"    //
/*****************************************************************************/
typedef struct online_s online_t;
typedef struct peer_s peer_t;
/*****************************************************************************/
struct peer_s {
    int sock_fd;
    struct sockaddr_in sock;
    peer_t *next;
};
/*****************************************************************************/
int setup_online(state_t *state);
/*****************************************************************************/
#endif // ONLINE_H
