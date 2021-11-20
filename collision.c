#include "cprocessing.h"
#include <stdio.h>
#include "collision.h"
#include "player.h"
#include "sceneManager.h"

#define ERROR_MARGIN 10.0f
CP_Vector buttonSize;

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


int is_btn_colliding(float mousepositionx, float mousepositiony, CP_Vector buttonPosition)
{
    return mousepositionx >= buttonPosition.x && mousepositionx <= buttonPosition.x + buttonSize.x &&
        mousepositiony >= buttonPosition.y && mousepositiony <= buttonPosition.y + buttonSize.y;
}

void collision_check_button(CP_Vector buttonPosition)
{
    if ((CP_Input_MouseTriggered(MOUSE_BUTTON_1)) && (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), buttonPosition)))
    {
        menu.page = 1;
    }
}