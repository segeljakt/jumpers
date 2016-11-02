#ifndef MARIO_BLOCK
#define MARIO_BLOCK
typedef struct block block;
#include "player.h"
#include "unit.h"
#include "config.h"

struct block
{
	int state;
	int (*action)(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y);
};

block* new_block(int state, int (*action)(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y));
int free_block(block *b);

#endif