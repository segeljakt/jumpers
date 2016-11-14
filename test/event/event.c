#include "src/state/map/event/event.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    int x = 1;
    int y = 5;
    event_t *event = new_event(0, &x);
    insert_event(&event, new_event(2, &y));

    event_t *iter;
    int i;
    int *val;

    for(iter = event, i = 0; iter != NULL; iter = iter->next, i++) {
        printf("list[%d]: %d\n", i, iter->counter);
    }

    while((val = (int*)pop_event(&event, 100))) {
        printf("popped: %d\n", *val);
    }

    return 0;
}
