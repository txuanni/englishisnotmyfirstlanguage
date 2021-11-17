#include "cprocessing.h"
#include <stdio.h>
#include "collision.h"
#define mouse_buffer 45

CP_Vector playerVelocity;
CP_Vector playerGravity;

int isJumping; //Jumping flag
int isLeft;
int isRight;
float timeElapsed;


int is_colliding(CP_Vector player, CP_Vector object, CP_Vector buffer)
{
    return player.x + mouse_buffer >= object.x - buffer.x && player.x - mouse_buffer <= object.x + buffer.x &&
        player.y + mouse_buffer >= object.y - buffer.y && player.y - mouse_buffer <= object.y + buffer.y;
}

void collision_check_platform(CP_Vector player, CP_Vector platform, CP_Vector platformbuffer)
{
    CP_Vector intersection;
    if (is_colliding(player, platform, platformbuffer))
    {
        if (player.y + mouse_buffer >= platform.y - platformbuffer.y) //top collision?
        {
            playerVelocity.y = 0;// add position of player to -0.5
            intersection.y = (player.y + mouse_buffer) - (platform.y - platformbuffer.y);
            player.y = player.y - intersection.y;
            //if u press spacebar and it is colliding with the floor then u add jumping velocity to player
            printf("%3f", player.y);
            isJumping = 0;
        }
        else if (player.y - mouse_buffer < platform.y + platformbuffer.y) //btm collision?
        {
            playerVelocity.y = 0;
            intersection.y = (platform.y + platformbuffer.y) - (player.y - mouse_buffer);
            player.y = player.y + intersection.y;
        }

        if (player.x + mouse_buffer > platform.x - platformbuffer.x)
        {
            playerVelocity.x = 0;
            intersection.x = (player.x + mouse_buffer) - (platform.x - platformbuffer.x);
            player.x = player.x - intersection.x;
        }
        else if (player.x - mouse_buffer < platform.x + platformbuffer.x)
        {
            playerVelocity.x = 0;
            intersection.x = (platform.x + platformbuffer.x) - (player.x - mouse_buffer);
            player.x = player.x + intersection.x;
        }
    }
    else
    {
        playerVelocity.y += playerGravity.y * timeElapsed;
    }
}

void collision_check_cheese(CP_Vector player, CP_Vector cheese, CP_Vector cheesebuffer)
{
    if (is_colliding(player, cheese, cheesebuffer))
    {
        printf("colliding with cheese\n");

    }
}

void collision_check_terrain(CP_Vector player, CP_Vector terrain, CP_Vector terrainbuffer)
{
    //TODO: Terrain collision
}

