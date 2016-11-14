/******************************************************************************
*     File Name           :     fifo.c                                        *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-12 14:10]                            *
*     Last Modified       :     [2016-11-12 21:40]                            *
*     Description         :     FIFO queue.                                   *
******************************************************************************/
#include "./fifo.h"
/*****************************************************************************/
node_t *new_node(void *data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}
/*---------------------------------------------------------------------------*/
int insert_node(node_t **head, node_t *node) {
    node->next = *head;
    *head = node;
    return 0;
}
/*---------------------------------------------------------------------------*/
void *pop_node(node_t **head) {
    if(*head == NULL) {
        return NULL;
    } else {
        node_t *pop = *head;
        void *data = pop->data;
        *head = (*head)->next;
        free(pop);
        return data;
    }
}
