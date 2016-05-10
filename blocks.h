#ifndef MARIO_BLOCKS
#define MARIO_BLOCKS
#include "player.h"
#include "unit.h"
#include "block.h"
#include "config.h"

int coinBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y);

int redShroomBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y);

int greenShroomBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y);

int noteBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y);

#endif