#include <ncurses.h>
#include "config.h"
#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"
#include "input.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

int update(WINDOW *win, char map[][MAP_WIDTH], int input[INPUT_TYPE_COUNT], player *p, unit **punits, block ***blockMap);
int readMap(char *fileName, char map[][MAP_WIDTH]);
unit* mapUnits(char map[][MAP_WIDTH], player *p);
block *** mapBlocks(char map[][MAP_WIDTH]);
int updateUnits(WINDOW *win, char map[][MAP_WIDTH], player *p, unit **punits);

int main(int argc, char *argv[])
{
    int i;
    char map[MAP_HEIGHT][MAP_WIDTH];

    readMap("world.txt", map);
    player *p = new_player(marioMovement);
    fprintf(stderr,"player created\n");
    unit *units = mapUnits(map, p);
    fprintf(stderr, "units mapped\n");
    block ***blockMap = mapBlocks(map);
    fprintf(stderr,"blocks mapped\n");
    WINDOW *mario_world;
    int offsetx, offsety;
    
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    
    // printw("Super Mario Terminal v. 0.0  -  Press x to quit...");
    refresh();
    
    offsetx = (COLS - WINDOW_WIDTH) / 2;
    offsety = (LINES - WINDOW_HEIGHT) / 2;
    
    mario_world = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, offsety, offsetx);
    int active = 1;
    flushinp();
    char charr[6];

    while(active)
    {
        int input[2];
        for(i = 0; i < INPUT_TYPE_COUNT; i++)
        {
            input[i] = -1;
        }
        if(isPressed(KEY_A))
        {
            input[X_AXIS] = LEFT;
        }
        else if(isPressed(KEY_D))
        {
            input[X_AXIS] = RIGHT;
        }
        if(isPressed(KEY_W))
        {
            input[Y_AXIS] = UP;
        }
        if(isPressed(KEY_X))
        {
            active = 0;
        }
        active *= update(mario_world, map, input, p, &units, blockMap);
        napms(TICKRATE);
    }

    flushinp();
    delwin(mario_world);
    
    endwin();
    
    return 0;
}

int update(WINDOW *win, char map[][MAP_WIDTH], int input[INPUT_TYPE_COUNT], player *p, unit **punits, block ***blockMap)
{
    int i, j;
    unit *u = *punits;

    wclear(win);
    
    for(i = 0; i <= WINDOW_HEIGHT; i++)
    {
        for(j = 0; (j <= WINDOW_WIDTH); j++)
        {
            if((j+(int)p->x) >= 0 && (j + (int)p->x) < MAP_WIDTH)
            {
                mvwaddch(win, i+1, j+1, map[i][j+(int)p->x]);
            }
        }
    }

    updateUnits(win, map, p, punits);

    p->movement(map, input, p, punits, blockMap);
    
    mvwaddch(win, 1, 1, 'C');
    mvwaddch(win, 1, 2, 'O');
    mvwaddch(win, 1, 3, 'I');
    mvwaddch(win, 1, 4, 'N');
    mvwaddch(win, 1, 5, 'S');
    mvwaddch(win, 1, 6, ':');
    mvwaddch(win, 1, 7, p->coins+'0');

    mvwaddch(win, (int)p->y+1, MARIO_X_OFFSET+1, p->type);



    box(win, 0, 0);

    wrefresh(win);

    return p->status;
}

int updateUnits(WINDOW *win, char map[][MAP_WIDTH], player *p, unit **punits)
{
    unit *u = *punits;
    while(u)
    {
        unit *temp = NULL;
        if((int)u->x > (int)p->x)
        {
            if((int)u->x < (int)p->x + WINDOW_WIDTH)
            {
                u->movement(map, u, p);
                if(u->status == 1)
                {
                    mvwaddch(win, (int)u->y+1, (int)u->x+1-(int)p->x, u->type);
                }
            }
        }
        else
        {
            u->status = 0;
        }
        if(u->status == 0)
        {
            if(u->prev && u->next)
            {
                u->prev->next = u->next;
                u->next->prev = u->prev;
            }
            else if(u->prev)
            {
                u->prev->next = NULL;
            }
            else if(u->next)
            {
                u->next->prev = NULL;
                (*punits) = u->next;
            }
            else
            {
                (*punits) = NULL;
            }
            temp = u;
        }
        u = u->next;
        if(temp)
        {
            free(temp);
        }
    }

    return 0;
}

int readMap(char *fileName, char map[][MAP_WIDTH])
{
    int i, j;
    FILE *fp;
    if((fp = fopen(fileName, "r+")) == NULL) 
    {
        printf("No such file\n");
        return -1;
    }

    for(i = 0; i < MAP_HEIGHT; i++)
    {
        for(j = 0; j < MAP_WIDTH; j++)
        {
            int ret = fscanf(fp, "%c", &map[i][j]);

            if(map[i][j] == '\n')
            {
                j--;
            }
            if(errno != 0) {
                perror("scanf:");
                break;
            } else if(ret == EOF) {
                break;
            }
        }
    }
    return 0;
}

unit* mapUnits(char map[][MAP_WIDTH], player *p)
{
    int i, j;
    unit *c = NULL, *root = NULL;
    for(i = 0; i < MAP_WIDTH; i++)
    {
        for(j = 0; j < MAP_HEIGHT; j++)
        {
            switch(map[j][i])
            {
                case 'm':
                    p->x = i-MARIO_X_OFFSET;
                    p->y = j;
                    map[j][i] = ' ';
                    break;
                case 'g':
                {
                    unit *u = new_unit(i, j, -0.1, 0, 1, 0, goombaMovement, map[j][i]);
                    if(c)
                    {
                        u->prev = c;
                        c->next = u;
                    }
                    else
                    {
                        root = u;
                    }
                    c = u;
                    map[j][i] = ' ';

                    break;
                }
                case 'k':
                {
                    /*unit *u = new_unit(i, j, 0.5, 0, 0, koopa, s, map[i][j]);
                    s = u;*/
                    break;
                }
                case '3':
                    break;
                case '4':
                    break;
                default:
                    break;
            }
        }
    }
    return root;
}

block*** mapBlocks(char map[][MAP_WIDTH])
{
    block*** blockMap = malloc(BLOCKMAP_HEIGHT*sizeof(block**));
    for(int i = 0; i < BLOCKMAP_HEIGHT; i++)
    {
        blockMap[i] = malloc(BLOCKMAP_WIDTH*sizeof(block*));
    }
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 1; j < MAP_WIDTH; j += 3)
        {
            switch(map[i][j])
            {
                case COIN_BLOCK:
                    map[i][j] = '?';
                    blockMap[i][j/3] = new_block(5, coinBlockAction);
                    break;
                case RED_SHROOM_BLOCK:
                    map[i][j] = '?';
                    blockMap[i][j/3] = new_block(1, redShroomBlockAction);
                    break;
                case GREEN_SHROOM_BLOCK:
                    map[i][j] = '?';
                    blockMap[i][j/3] = new_block(1, greenShroomBlockAction);
                    break;
                case NOTE_BLOCK:
                    map[i][j] = 'j';
                    blockMap[i][j/3] = new_block(3, noteBlockAction);
                    break;
                default:
                    break;
            }
        }
    }
    return blockMap;
}


























