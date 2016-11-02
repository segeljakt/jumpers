#ifndef MARIO_PLAYERS
#define MARIO_PLAYERS
#include "config.h"
#include "player.h"
#include "unit.h"
int marioMovement(char map[][MAP_WIDTH], int input[], player *p, unit **u, block ***blockMap);
#endif