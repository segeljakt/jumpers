#ifndef MARIO_UNITS
#define MARIO_UNITS
#include "config.h"
#include "unit.h"
#include "player.h"
int goombaMovement(char [][MAP_WIDTH], unit *u, player *p);
int greenKoopaMovement(char [][MAP_WIDTH], unit *u, player *p);
int redShroomMovement(char [][MAP_WIDTH], unit *u, player *p);
int tempCoin(char [][MAP_WIDTH], unit *u, player *p);
#endif