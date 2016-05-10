#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"
#include "config.h"
#include <stdlib.h>
#include <curses.h>

int coinBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int bX, int bY)
{
	block *b = blockMap[bY][bX];

	int x = bX*3+1, y = bY;
	p->coins += 1;
	b->state -= 1;
	if(b->state == 0)
	{
		map[y][x] = '#';
		blockMap[y][x] = NULL;
		free_block(b);
	}
	unit *iter = *u;
	for(unit *iter = *u; iter != NULL; iter = iter->next)
	{
		if(iter->x >= x-1 && iter->x <= x+1 && iter->y == y && iter->type != RED_SHROOM)
		{
			iter->status = 0;
		}
	}
	return 0;
}

int redShroomBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int bX, int bY)
{
	int x = bX*3+1, y = bY;
	unit* redShroom = new_unit((float)x, (float)y-1, 0.2, 0.0, 1, 0, redShroomMovement, RED_SHROOM);
	unit *iter = *u;
	for(unit *iter = *u; iter != NULL; iter = iter->next)
	{
		if(iter->x >= x-1 && iter->x <= x+1 && iter->y == y && iter->type != RED_SHROOM)
		{
			iter->status = 0;
		}
	}
	blockMap[bY][bX] = NULL;
	map[y][x] = '#';
	(*u)->prev = redShroom;
	redShroom->next = *u;
	*u = redShroom;	

	return 0;
}

int greenShroomBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int bX, int bY)
{
	return 0;
}

int noteBlockAction(char map[][MAP_WIDTH], block ***blockMap, player *p, unit **u, int bX, int bY)
{
	return 0;
}