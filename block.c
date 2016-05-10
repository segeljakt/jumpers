#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"
#include "config.h"

#include <stdlib.h>

block* new_block(int state, int (*action)(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int x, int y))
{
	block* b = malloc(sizeof(new_block));
	b->state = state;
	b->action = action;
	return b;
}

int free_block(block *b)
{
	b->state = 0;
	b->action = NULL;
	free(b);
	b = NULL;
	return 0;
}
