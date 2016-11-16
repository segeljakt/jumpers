/******************************************************************************
*     File Name           :     parser.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 22:35]                            *
*     Last Modified       :     [2016-11-15 14:33]                            *
*     Description         :     Map parser.                                   *
******************************************************************************/
#include "parser.h"
#include <string.h>
#include "src/state/map/obj/block/block.h"
#include "src/state/map/obj/unit/unit.h"
#include "src/state/map/obj/unit/player/player.h"
/*****************************************************************************/
static int parse_block(map_t *map, char **raw_map, int i, int j);
static int parse_unit(map_t *map, char **raw_map, int i, int j);
/*****************************************************************************/
int parse_map(map_t *map, char **raw_map) {
    int i;
    int j;
    int len;
    for(i = 0; i < map->height; i++) {
        len = strlen(raw_map[i]);
        for(j = 0; j < map->width; j++) {
            if(j > len) {                                       // Filler
                new_empty_block(i, j, CHAR_NONE, map);
            } else {
                if(parse_block(map, raw_map, i, j)) {           // Block
                    raw_map[i][j] = CHAR_NONE;
                    map->block[i][j].status |= ASSIGNED;
                    continue;
                } else if(parse_unit(map, raw_map, i, j)) {     // Unit
                    continue;
                }
            }
        }
    }
    for(i = 0; i < map->height; i++) {
        len = strlen(raw_map[i]);
        for(j = 0; j < len; j++) {
            if(raw_map[i][j] != CHAR_NONE) {                    // Decoration
                new_empty_block(i, j, raw_map[i][j], map);
            } else if(map->block[i][j].status == UNASSIGNED) {  // Behind unit
                new_empty_block(i, j, CHAR_NONE, map);
            }
        }
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
static int parse_block(map_t *map, char **raw_map, int i, int j) {
    switch(raw_map[i][j]) {
        case CHAR_NORMAL_BLOCK: {
            new_normal_block(i, j, CHAR_NORMAL_BLOCK, map);
            return 1;
        } case EDITOR_CHAR_COIN_BLOCK: {
            new_coin_block(i, j, map);
            return 1;
        } case CHAR_BRICK_BLOCK: {
            new_brick_block(i, j, map);
            return 1;
        } case CHAR_SHROOM: {
            new_red_shroom_block(i, j, map);
        } case CHAR_STAR: {
            new_star_block(i, j, map);
        } case CHAR_NONE: {
            new_empty_block(i, j, CHAR_NONE, map);
        } default: {
            return 0;
        }
    }
}
/*---------------------------------------------------------------------------*/
static int parse_unit(map_t *map, char **raw_map, int i, int j) {
    switch(raw_map[i][j]) {
        case CHAR_MARIO: {
            parse_mario(i, j, raw_map, map);
            return 1;
        } case CHAR_GOOMBA: {
            parse_goomba(i, j, raw_map, map);
            return 1;
        } case CHAR_KOOPA_T: {
            parse_koopa(i, j, raw_map, map);
            return 1;
        } case CHAR_PIRANHA_T: {
            parse_piranha(i, j, raw_map, map);
            return 1;
        } default: {
            return 0;
        }
    }
}
