#include "cprocessing.h"
#include <stdio.h>

#define mouse_buffer 45

CP_Vector playerVelocity;
CP_Vector playerGravity;

int isJumping; //Jumping flag
float timeElapsed;


int is_colliding(CP_Vector player, CP_Vector object, CP_Vector buffer)
{
    return player.x + mouse_buffer >= object.x - buffer.x && player.x - mouse_buffer <= object.x + buffer.x &&
        player.y + mouse_buffer >= object.y - buffer.y && player.y - mouse_buffer <= object.y + buffer.y;
}

void collision_check_platform(CP_Vector player, CP_Vector platform, CP_Vector platformbuffer)
{
    if (is_colliding(player, platform, platformbuffer))
    {
        printf("colliding with platform\n");
        isJumping = 0;
        playerVelocity.y = 0;
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