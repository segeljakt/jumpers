/******************************************************************************
*     File Name           :     data.h                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-12 00:49]                            *
*     Last Modified       :     [2016-11-12 14:12]                            *
*     Description         :     Event queue.                                  *
******************************************************************************/
#ifndef EVENT_H
#define EVENT_H
/*****************************************************************************/
/* Native */
#include <stdlib.h>
#include <string.h>
/*****************************************************************************/
typedef struct event_s event_t;
/******************************************************************************
* Struct: event_s                                                             *
* ~~~~~~~~~~~~~~~                                                             *
* Node in the list.                                                           *
******************************************************************************/
struct event_s {
    int counter;
    void *data;
    event_t *next;
};
/*****************************************************************************/
event_t *new_event(int counter, void *data);
int insert_event(event_t **head, event_t *event);
void *pop_event(event_t **head, int counter);
/*****************************************************************************/
#endif // EVENT_H
