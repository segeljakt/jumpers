/******************************************************************************
*     File Name           :     map.c                                         *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-23 14:57]                            *
*     Last Modified       :     [2016-11-02 18:55]                            *
*     Description         :     World map.                                    *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./map.h"
#include "cfg.h"
#include "block.h"
/*****************************************************************************/
static int read_map(char ***raw_map, int *height, int *width);
static int parse_map(map_t *map, char **raw_map);
/*****************************************************************************/
map_t *init_map(char *filepath) {
    map_t *map = malloc(sizeof(map_t));

    /* Read raw map */
    char **raw_map = NULL;
    int height = 0;
    int width = 0;

    if(read_map(&raw_map, &(map->height), &(map->width)) == 0) {
        parse_map(map, raw_map);
    }
    return map;
}
/*****************************************************************************/
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


static int parse_block(map_t *map, char **raw_map, int i, int j) {
    switch(raw_map[i][j]) {
        case NORMAL_BLOCK_CHAR: {
            map->block[i][j].c = NORMAL_BLOCK_CHAR;
            map->block[i][j].action = normal_block_collision;
        } case COIN_BLOCK_CHAR: {
            map->block[i][j].c = NORMAL_BLOCK_CHAR;
            map->block[i][j].action = coin_block_collision;
        }
    }
    if(parse_block(map, raw_map, i, j)) {
        return 1;
    } else if(parse_coin_block(map, raw_map, i, j)) {
        return 1;
    } else if(parse_coin_block(map, raw_map, i, j)) {
        return 1;
    } else {
        return 0;
    }
}

static int parse_unit(map_t *map, char **raw_map, int i, int j) {

}

static int parse_map(map_t *map, char **raw_map) {
    int i;
    int j;
    int len;
    for(i = 0; i < map->height; i++) {
        len = strlen(raw_map[i]);
        for(j = 0; j < map->width; j++) {
            if(j > len) {
                map->block[i][j].c = ' ';
                map->block[i][j].action = NULL;
            } else {
                if(parse_block(map, raw_map, i, j)) {
                    continue;
                } else if(parse_unit(map, raw_map, i, j)) {
                    continue;
                }
            }
        }
    }
}
