/******************************************************************************
*     File Name           :     map.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-13 20:53]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "./map.h"
#include "src/cfg.h"
#include "src/state/parser/parser.h"
#include "src/state/map/event/event.h"
#include "src/state/map/obj/block/block.h"
/*****************************************************************************/
static char **read_map(char *fp, int *height, int *width);
/*****************************************************************************/
map_t *init_map(char *fp) {
    map_t *map = malloc(sizeof(map_t));

    /* Read raw map */
    char **raw_map = read_map(fp, &(map->height), &(map->width));

    if(raw_map != NULL) {
        map->block = malloc(sizeof(block_t*)*map->height);
        int i;
        for(i = 0; i < map->height; i++) {
            map->block[i] = malloc(sizeof(block_t)*map->width);
        }
        parse_map(map, raw_map);
        map->redraw_block = NULL;
        map->animate_unit = NULL;
        return map;
    } else {
        free(map);
        return NULL;
    }
}
/*---------------------------------------------------------------------------*/
char **read_map(char *fp, int *height, int *width) {
    FILE *stream = NULL;

    if((stream = fopen(fp, "r")) == NULL) {
        return NULL;
    }

    char **raw_map = NULL;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    *width = 0;
    *height = 0;
    int i = 0;
    while((linelen = getline(&line, &linecap, stream)) > 0) {
        if(i == 0) {
            raw_map = malloc(sizeof(char*));
        } else {
            raw_map = realloc(raw_map, sizeof(char*)*(i+1));
        }
        raw_map[i] = line;
        line = NULL;
        linecap = 0;
        *width = (linelen > *width)? linelen:*width;
        i++;
    }
    *height = i;
//    (*height)--; TODO:FIX THIS
    fclose(stream);
    return raw_map;
}
/*---------------------------------------------------------------------------*/
void free_map(map_t *map) {

}
