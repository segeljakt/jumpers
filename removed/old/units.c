#include "player.h"
#include "players.h"
#include "unit.h"
#include "units.h"
#include "block.h"
#include "blocks.h"

#include <string.h>
int goombaMovement(char map[][MAP_WIDTH], unit *u, player *p)
{
    float x,y;

    x = u->x;
    y = u->y;

    u->v_y += GRAVITY;

    /* Calculate new position */
    u->x += u->v_x;
    u->y += u->v_y;

    /* Check collision */

    // Y-Collision
    if(u->y >= 0 && u->y < MAP_HEIGHT && x + MARIO_X_OFFSET >= 0 && x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)x]))
        {
            if(u->v_y > 0)
            {
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
            else if(u->v_y < 0)
            {
                u->v_y = 0;
                u->y = y;
            }
        }
        else
        {
            u->onGround = 0;
        }
    }

    /* X-Collision */
    if(y >= 0 && y < MAP_HEIGHT && u->x + MARIO_X_OFFSET>= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)y][(int)u->x]))
        {
            u->v_x *= -1;
            if(u->v_x > 0)
            {
                u->x = x + 1;
            }
            else if(u->v_x < 0)
            {
                u->x = x - 1;
            }
        }  
    }
    /* XY-Collision */
    if(u->y >= 0 && u->y < MAP_HEIGHT && u->x + MARIO_X_OFFSET >= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)u->x]))
        {
            if((u->v_y > 0 || u->v_y < 0) && (u->v_x > 0 || u->v_x < 0))
            {
                u->x = x;
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
        }
    }
    if(u->y < 0)
    {
        u->status = 0;
    }

    return 0;
}

int koopaMovement(char map[][MAP_WIDTH], unit *u, player *p)
{
    float x,y;

    x = u->x;
    y = u->y;

    u->v_y += GRAVITY;

    /* Calculate new position */
    u->x += u->v_x;
    u->y += u->v_y;

    /* Check collision */

    // Y-Collision
    if(u->y >= 0 && u->y < MAP_HEIGHT && x + MARIO_X_OFFSET >= 0 && x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)x]))
        {
            if(u->v_y > 0)
            {
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
            else if(u->v_y < 0)
            {
                u->v_y = 0;
                u->y = y;
            }
        }
        else
        {
            u->onGround = 0;
        }
    }

    /* X-Collision */
    if(y >= 0 && y < MAP_HEIGHT && u->x + MARIO_X_OFFSET>= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)y][(int)u->x]))
        {
            if(u->v_x > 0 || u->v_x < 0)
            {
                u->v_x *= -1;
                u->x = x;    
            }
        }  
    }
    /* XY-Collision */
    if(u->y >= 0 && u->y < MAP_HEIGHT && u->x + MARIO_X_OFFSET >= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)u->x]))
        {
            if((u->v_y > 0 || u->v_y < 0) && (u->v_x > 0 || u->v_x < 0))
            {
                u->x = x;
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
        }
    }
    if(u->status == 0)
    {
        u->type = 'n';
    }

    if(u->y < 0)
    {
        u->status = 0;
    }

    return 0;
}

int redShroomMovement(char map[][MAP_WIDTH], unit *u, player *p)
{
    float x,y;

    x = u->x;
    y = u->y;

    u->v_y += GRAVITY;

    /* Calculate new position */
    u->x += u->v_x;
    u->y += u->v_y;

    /* Check collision */

    // Y-Collision
    if(u->y >= 0 && u->y < MAP_HEIGHT && x + MARIO_X_OFFSET >= 0 && x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)x]))
        {
            if(u->v_y > 0)
            {
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
            else if(u->v_y < 0)
            {
                u->v_y = 0;
                u->y = y;
            }
        }
        else
        {
            u->onGround = 0;
        }
    }

    /* X-Collision */
    if(y >= 0 && y < MAP_HEIGHT && u->x + MARIO_X_OFFSET>= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)y][(int)u->x]))
        {
            u->v_x *= -1;
            if(u->v_x > 0)
            {
                u->x = x + 1;
            }
            else if(u->v_x < 0)
            {
                u->x = x - 1;
            }
        }  
    }
    /* XY-Collision */
    if(u->y >= 0 && u->y < MAP_HEIGHT && u->x + MARIO_X_OFFSET >= 0 && u->x + MARIO_X_OFFSET < MAP_WIDTH)
    {
        if(strchr(COLLISION_SET, map[(int)u->y][(int)u->x]))
        {
            if((u->v_y > 0 || u->v_y < 0) && (u->v_x > 0 || u->v_x < 0))
            {
                u->x = x;
                u->onGround = 1;
                u->v_y = 0;
                u->y = y;
            }
        }
    }
    if(u->y < 0)
    {
        u->status = 0;
    }

    return 0;
}

