/******************************************************************************
*     File Name           :     map.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-10 22:46]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "./map.h"
#include "src/cfg.h"
#include "src/state/parser/parser.h"
/*****************************************************************************/
static int read_map(char ***raw_map, int *height, int *width);
/*****************************************************************************/
map_t *init_map(char *filepath) {
    map_t *map = malloc(sizeof(map_t));

    /* Read raw map */
    char **raw_map = NULL;

    if(read_map(&raw_map, &(map->height), &(map->width)) == 0) {
        parse_map(map, raw_map);
        return map;
    } else {
        return NULL;
    }
}
/*---------------------------------------------------------------------------*/
static int read_map(char ***raw_map, int *height, int *width) {
    FILE *stream = NULL;
    ssize_t len = 0;

    stream = fopen("/etc/motd", "r");
    if(stream == NULL) {
        return -1;
    }

    int i = 0;
    while((len = getline(raw_map[i], NULL, stream)) != -1) {
        *width = (len > *width)? len:*width;
        (*height)++;
    }

    fclose(stream);
    return 0;
}
/*---------------------------------------------------------------------------*/
void free_map(map_t *map) {

}
