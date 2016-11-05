#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"
#include "config.h"
#include <ncurses.h>

#include <string.h>

int marioMovement(char map[][MAP_WIDTH], int input[], player *p, unit **u, block ***blockMap)
{
    //fprintf(stderr, "g");
    // printw("z");
    float x = p->x;
    float y = p->y;
    if(input[1] == UP && p->onGround)
    {
        p->v_y = -MAX_Y_VELOCITY;
        p->onGround = 0;
    }
    else if(input[0] == RIGHT)
    {
        (p->v_x < 0)?(p->v_x+=0.5):(p->v_x+=X_ACCELERATION);
        /* p->v_x = MAX_X_VELOCITY; */
    }
    else if(input[0] == LEFT)
    {
        (p->v_x > 0)?(p->v_x-=0.5):(p->v_x-=X_ACCELERATION);
        /* p->v_x = MAX_X_VELOCITY; */
    }
    else if(p->onGround && (p->v_x < 0.25 || p->v_x > -0.25))
    {
        p->v_x /= 1.5;
    }
    else if(p->onGround)
    {
        p->v_x /= 1.125;
    }

    p->v_y += GRAVITY;

    if(p->v_x > MAX_X_VELOCITY)
    {
        p->v_x = MAX_X_VELOCITY;
    }
    else if(p->v_x < -MAX_X_VELOCITY)
    {
        p->v_x = -MAX_X_VELOCITY;
    }
    if(p->v_y > MAX_Y_VELOCITY)
    {
        p->v_y = MAX_Y_VELOCITY;
    }
    else if(p->v_y < -MAX_Y_VELOCITY)
    {
        p->v_y = -MAX_Y_VELOCITY;
    }

    p->y += p->v_y;
    p->x += p->v_x;

    /* CHECK FOR COLLISION WITH UNITS */

    /* X - Collision */
    if(y >= 0 && y < MAP_HEIGHT && p->x + MARIO_X_OFFSET >= 0 && p->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)y][(int)p->x+MARIO_X_OFFSET]))
        {
            if(p->v_x > 0 || p->v_x < 0)
            {
                p->v_x = 0;
                p->x = x;
            }
        }
    }
    /* Y - Collision */
    if(p->y >= 0 && p->y < MAP_HEIGHT && x + MARIO_X_OFFSET >= 0 && x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)p->y][(int)p->x+MARIO_X_OFFSET]))
        {
            int bX = (int)p->x;
            int bY = (int)p->y;
            if(p->v_y > 0)
            {
                if(!p->onGround)
                {
                    p->onGround = 1;
                    if(input[0] != RIGHT && input[0] != LEFT)
                    {
                        //p->x = x;
                        p->v_x = 0;
                    }
                }
                p->v_y = 0;
                p->y = y;
            }
            else if(p->v_y < 0)
            {
                p->v_y *= -1;
                p->y = y;
                // Action blocks (Coin Block, Red Shroom Block etc.)
                for(int i = -1; i <= 1; i++)
                {
                    if(strchr(ACTION_SET, map[bY][bX+MARIO_X_OFFSET+i]))
                    {
                        block *b = blockMap[bY][(bX+MARIO_X_OFFSET+i)/3];
                        b->action(map, blockMap, p, u, (bX+MARIO_X_OFFSET+i)/3, bY);
                    }
                }
            }
        }
        else
        {
            p->onGround = 0;
        }
    }

    /* XY - Collision */
    if(y >= 0 && y < MAP_HEIGHT && p->x + MARIO_X_OFFSET >= 0 && p->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)p->y][(int)p->x+MARIO_X_OFFSET]))
        {
            if((p->v_y > 0 || p->v_y < 0) && (p->v_x > 0 || p->v_x < 0))
            {
                p->x = x;
                p->v_y = 0;
                p->onGround = 1;
                p->y = y;
            }
        }
    }

    unit *iter = *u;
    for(unit *iter = *u; iter != NULL; iter = iter->next)
    {
        if((int)p->y == (int)iter->y && (int)p->x + MARIO_X_OFFSET == (int)iter->x)
        {
            if(strchr(DEADLY_UNITS, iter->type))
            {
                if((int)y < (int)iter->y)
                {
                    switch(iter->type)
                    {
                        case 'g':
                            p->v_y = -MAX_Y_VELOCITY+GRAVITY;
                            iter->status = 0;
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                    p->status = 0;
                }
            }
            else
            {
                switch(iter->type)
                {
                    case 's':
                        p->type = 'O';
                        iter->status = 0;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    // while(u)
    // {
    //     if((int)p->y == (int)u->y && (int)p->x + MARIO_X_OFFSET == (int)u->x)
    //     {
    //         if((int)y < (int)u->y)
    //         {
    //             switch(u->type)
    //             {
    //                 case 'g':
    //                     p->v_y = -MAX_Y_VELOCITY+GRAVITY;
    //                     u->status = 0;
    //                     break;
    //                 default:
    //                     break;
    //             }
    //         }
    //         else
    //         {
    //             p->status = 0;
    //         }
    //     }
    //     u = u->next;
    // }
    if(p->y > MAP_HEIGHT+20)
    {
        p->status = 0;
    }

    return 0;
}
