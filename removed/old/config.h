#ifndef MARIO_CONFIG
#define MARIO_CONFIG

#define TICKRATE 20
#define MAX_Y_VELOCITY 0.725
#define MAX_X_VELOCITY 0.5

#define MARIO_X_OFFSET 10

#define WINDOW_WIDTH 50
#define WINDOW_HEIGHT 15

#define GRAVITY 0.055
#define X_ACCELERATION 0.2
#define INPUT_TYPE_COUNT 2
#define X_AXIS 0
#define Y_AXIS 1

#define MAP_WIDTH 636
#define MAP_HEIGHT 13

#define BLOCKMAP_WIDTH MAP_WIDTH/3
#define BLOCKMAP_HEIGHT MAP_HEIGHT

#define COLLISION_SET "[#]?=T"
#define ACTION_SET "?"

#define COIN_BLOCK '1'
#define RED_SHROOM_BLOCK '2'
#define GREEN_SHROOM_BLOCK '3'
#define NOTE_BLOCK '4'

#define RED_SHROOM 's'

#define DEADLY_UNITS "g"


enum direction {UP, DOWN, RIGHT, LEFT};
#endif