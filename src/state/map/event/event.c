/******************************************************************************
*     File Name           :     data.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-06-30 20:09]                            *
*     Last Modified       :     [2016-11-12 14:39]                            *
*     Description         :     Ordered singly linked list and functions.     *
******************************************************************************/
#include "./event.h"
/*****************************************************************************/
event_t *new_event(int counter, void *data) {
    event_t *event = malloc(sizeof(event_t));
    event->counter = counter;
    event->data = data;
    event->next = NULL;
    return event;
}
/*---------------------------------------------------------------------------*/
int insert_event(event_t **head, event_t *event) {
    event_t *iter = *head;
    event_t **pp = head;
    while(1) {
        if(iter == NULL
        || (event->counter < iter->counter)) {
            event->next = *pp;
            *pp = event;
            break;
        } else {
            pp = &iter->next;
            iter = iter->next;
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
void *pop_event(event_t **head, int counter) {
    if(*head == NULL) {
        return NULL;
    } else if((*head)->counter < counter) {
        event_t *pop = *head;
        void *data = pop->data;
        *head = (*head)->next;
        free(pop);
        return data;
    } else {
        return NULL;
    }
}
