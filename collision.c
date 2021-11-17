#include "cprocessing.h"
#include <stdio.h>
#include "collision.h"
#include "player.h"

#define ERROR_MARGIN 10.0f

//#define mouse_buffer 45

//CP_Vector playerVelocity;
//CP_Vector playerGravity;
//
//int isJumping; //Jumping flag
//int isLeft;
//int isRight;
//float timeElapsed;

int CheckAABB_Collision(CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector bSize)
{
    return (aPos.x + aSize.x >= bPos.x - bSize.x) && (aPos.x - aSize.x <= bPos.x + bSize.x) &&
        (aPos.y + aSize.y >= bPos.y - bSize.y) && (aPos.y - aSize.y <= bPos.y + bSize.y);
}

void Collision_PlayerWithPlatform(CP_Vector platformPos, CP_Vector platformSize)
{
    if (CheckAABB_Collision(gPlayer.position, CP_Vector_Scale(gPlayer.size, 0.5f), platformPos, platformSize))
    {
        //printf("Collision detected!\n");

        gPlayer.canMoveLeft = 1;
        gPlayer.canMoveRight = 1;

        //gPlayer on top of platform
        if (gPlayer.position.y + gPlayer.size.y * 0.5f >= platformPos.y - platformSize.y &&
            gPlayer.position.y + gPlayer.size.y * 0.5f <= platformPos.y - platformSize.y + ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= platformPos.x + platformSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= platformPos.x - platformSize.x + ERROR_MARGIN)
        {
            printf("gPlayer on top of platform!\n");
            gPlayer.canJump = 1;
            gPlayer.isJumping = 0; //gPlayer is on ground, so he is not jumping and is able to jump again
            gPlayer.isGrounded = 1;
        }
        //gPlayer below platform
        else if (gPlayer.position.y - gPlayer.size.y * 0.5f <= platformPos.y + platformSize.y &&
            gPlayer.position.y - gPlayer.size.y * 0.5f >= platformPos.y + platformSize.y - ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= platformPos.x + platformSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= platformPos.x - platformSize.x + ERROR_MARGIN)
        {
            printf("gPlayer below platform!\n");
            gPlayer.canJump = 0; //Cannot jump if top is blocked
            gPlayer.isJumping = 1;
            gPlayer.velocity.y = 0.0f;
        }

        //gPlayer on the left side of platform and inside
        if (gPlayer.position.x + gPlayer.size.x * 0.5f >= platformPos.x - platformSize.x &&
            gPlayer.position.x + gPlayer.size.x * 0.5f <= platformPos.x + platformSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= platformPos.y - platformSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= platformPos.y + platformSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the left of platform!\n");
            gPlayer.canMoveRight = 0;
        }
        //gPlayer on the right side of platform
        else if (gPlayer.position.x - gPlayer.size.x * 0.5f <= platformPos.x + platformSize.x &&
            gPlayer.position.x - gPlayer.size.x * 0.5f >= platformPos.x - platformSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= platformPos.y - platformSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= platformPos.y + platformSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the right of platform!\n");
            gPlayer.canMoveLeft = 0;
        }
    }
}

//int is_colliding(CP_Vector player, CP_Vector object, CP_Vector buffer)
//{
//    return player.x + mouse_buffer >= object.x - buffer.x && player.x - mouse_buffer <= object.x + buffer.x &&
//        player.y + mouse_buffer >= object.y - buffer.y && player.y - mouse_buffer <= object.y + buffer.y;
//}
//
//void collision_check_platform(CP_Vector player, CP_Vector platform, CP_Vector platformbuffer)
//{
//    CP_Vector intersection;
//    if (is_colliding(player, platform, platformbuffer))
//    {
//        if (player.y + mouse_buffer >= platform.y - platformbuffer.y) //top collision?
//        {
//            playerVelocity.y = 0;// add position of player to -0.5
//            intersection.y = (player.y + mouse_buffer) - (platform.y - platformbuffer.y);
//            player.y = player.y - intersection.y;
//            //if u press spacebar and it is colliding with the floor then u add jumping velocity to player
//            printf("%3f", player.y);
//            isJumping = 0;
//        }
//        else if (player.y - mouse_buffer < platform.y + platformbuffer.y) //btm collision?
//        {
//            playerVelocity.y = 0;
//            intersection.y = (platform.y + platformbuffer.y) - (player.y - mouse_buffer);
//            player.y = player.y + intersection.y;
//        }
//
//        if (player.x + mouse_buffer > platform.x - platformbuffer.x)
//        {
//            playerVelocity.x = 0;
//            intersection.x = (player.x + mouse_buffer) - (platform.x - platformbuffer.x);
//            player.x = player.x - intersection.x;
//        }
//        else if (player.x - mouse_buffer < platform.x + platformbuffer.x)
//        {
//            playerVelocity.x = 0;
//            intersection.x = (platform.x + platformbuffer.x) - (player.x - mouse_buffer);
//            player.x = player.x + intersection.x;
//        }
//    }
//    else
//    {
//        playerVelocity.y += playerGravity.y * timeElapsed;
//    }
//}
//
//void collision_check_cheese(CP_Vector player, CP_Vector cheese, CP_Vector cheesebuffer)
//{
//    if (is_colliding(player, cheese, cheesebuffer))
//    {
//        printf("colliding with cheese\n");
//
//    }
//}
//
//void collision_check_terrain(CP_Vector player, CP_Vector terrain, CP_Vector terrainbuffer)
//{
//    //TODO: Terrain collision
//}
