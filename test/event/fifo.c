#include "src/state/map/fifo/fifo.h"
#include <stdio.h>
int main() {
    node_t *node;
    int x = 1;
    int y = 2;
    int z = 3;
    node = new_node(&x);
    insert_node(&node, new_node(&y));
    insert_node(&node, new_node(&z));
    while(pop_node(&node)) {
        printf("LOL\n");
    }
}
