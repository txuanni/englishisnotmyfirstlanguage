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

void Collision_PlayerWithTerrain(CP_Vector terrainPos, CP_Vector terrainSize)
{
    if (CheckAABB_Collision(gPlayer.position, CP_Vector_Scale(gPlayer.size, 0.5f), terrainPos, terrainSize))
    {
        //printf("Collision detected!\n");

        gPlayer.canMoveLeft = 1;
        gPlayer.canMoveRight = 1;

        //gPlayer on top of terrain
        if (gPlayer.position.y + gPlayer.size.y * 0.5f >= terrainPos.y - terrainSize.y &&
            gPlayer.position.y + gPlayer.size.y * 0.5f <= terrainPos.y - terrainSize.y + ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= terrainPos.x + terrainSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= terrainPos.x - terrainSize.x + ERROR_MARGIN)
        {
            printf("gPlayer on top of terrain!\n");
            gPlayer.canJump = 1;
            gPlayer.isJumping = 0; //gPlayer is on ground, so he is not jumping and is able to jump again
            gPlayer.isGrounded = 1;
        }
        //gPlayer below terrain
        else if (gPlayer.position.y - gPlayer.size.y * 0.5f <= terrainPos.y + terrainSize.y &&
            gPlayer.position.y - gPlayer.size.y * 0.5f >= terrainPos.y + terrainSize.y - ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= terrainPos.x + terrainSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= terrainPos.x - terrainSize.x + ERROR_MARGIN)
        {
            printf("gPlayer below terrain!\n");
            gPlayer.canJump = 0; //Cannot jump if top is blocked
            gPlayer.isJumping = 1;
            gPlayer.velocity.y = 0.0f;
        }

        //gPlayer on the left side of terrain and inside
        if (gPlayer.position.x + gPlayer.size.x * 0.5f >= terrainPos.x - terrainSize.x &&
            gPlayer.position.x + gPlayer.size.x * 0.5f <= terrainPos.x + terrainSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= terrainPos.y - terrainSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= terrainPos.y + terrainSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the left of terrain!\n");
            gPlayer.canMoveRight = 0;
        }
        //gPlayer on the right side of terrain
        else if (gPlayer.position.x - gPlayer.size.x * 0.5f <= terrainPos.x + terrainSize.x &&
            gPlayer.position.x - gPlayer.size.x * 0.5f >= terrainPos.x - terrainSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= terrainPos.y - terrainSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= terrainPos.y + terrainSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the right of terrain!\n");
            gPlayer.canMoveLeft = 0;
        }
    }
}

void Collision_PlayerWithCheese(CP_Vector Cheesepos, CP_Vector CheeseSize)
{
    if (CheckAABB_Collision(gPlayer.position, CP_Vector_Scale(gPlayer.size, 0.5f), Cheesepos, CheeseSize))

    {
        //printf("Collision detected!\n");

        gPlayer.canMoveLeft = 1;
        gPlayer.canMoveRight = 1;

        //gPlayer on top of cheese
        if (gPlayer.position.y + gPlayer.size.y * 0.5f >= Cheesepos.y - CheeseSize.y &&
            gPlayer.position.y + gPlayer.size.y * 0.5f <= Cheesepos.y - CheeseSize.y + ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= Cheesepos.x + CheeseSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= Cheesepos.x - CheeseSize.x + ERROR_MARGIN)
        {
            printf("gPlayer on top of cheese!\n");

            gPlayer.canJump = 1;
            gPlayer.isJumping = 0; //gPlayer is on ground, so he is not jumping and is able to jump again
            gPlayer.isGrounded = 1;
        }

        //gPlayer below cheese
        else if (gPlayer.position.y - gPlayer.size.y * 0.5f <= Cheesepos.y + CheeseSize.y &&
            gPlayer.position.y - gPlayer.size.y * 0.5f >= Cheesepos.y + CheeseSize.y - ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= Cheesepos.x + CheeseSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= Cheesepos.x - CheeseSize.x + ERROR_MARGIN)
        {
            printf("gPlayer below cheese!\n");

            gPlayer.canJump = 0; //Cannot jump if top is blocked
            gPlayer.isJumping = 1;
            gPlayer.velocity.y = 0.0f;
        }

        //gPlayer on the left side of cheese and inside
        if (gPlayer.position.x + gPlayer.size.x * 0.5f >= Cheesepos.x - CheeseSize.x &&
            gPlayer.position.x + gPlayer.size.x * 0.5f <= Cheesepos.x + CheeseSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= Cheesepos.y - CheeseSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= Cheesepos.y + CheeseSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the left of cheese!\n");
            gPlayer.canMoveRight = 0;
        }
        //gPlayer on the right side of cheese
        else if (gPlayer.position.x - gPlayer.size.x * 0.5f <= Cheesepos.x + CheeseSize.x &&
            gPlayer.position.x - gPlayer.size.x * 0.5f >= Cheesepos.x - CheeseSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= Cheesepos.y - CheeseSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= Cheesepos.y + CheeseSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the right of cheese!\n");

            gPlayer.canMoveLeft = 0;
        }
    }
}

void Collision_PlayerWithTraps(CP_Vector Trappos, CP_Vector TrapSize)
{
    if (CheckAABB_Collision(gPlayer.position, CP_Vector_Scale(gPlayer.size, 0.5f), Trappos, TrapSize))

    {
        //printf("Collision detected!\n");

        gPlayer.canMoveLeft = 1;
        gPlayer.canMoveRight = 1;

        //gPlayer on top of Trap
        if (gPlayer.position.y + gPlayer.size.y * 0.5f >= Trappos.y - TrapSize.y &&
            gPlayer.position.y + gPlayer.size.y * 0.5f <= Trappos.y - TrapSize.y + ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= Trappos.x + TrapSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= Trappos.x - TrapSize.x + ERROR_MARGIN)
        {
            printf("gPlayer on top of cheese!\n");

            gPlayer.canJump = 1;
            gPlayer.isJumping = 0; //gPlayer is on ground, so he is not jumping and is able to jump again
            gPlayer.isGrounded = 1;
        }

        //gPlayer below Trap
        else if (gPlayer.position.y - gPlayer.size.y * 0.5f <= Trappos.y + TrapSize.y &&
            gPlayer.position.y - gPlayer.size.y * 0.5f >= Trappos.y + TrapSize.y - ERROR_MARGIN &&
            gPlayer.position.x - gPlayer.size.x * 0.5f <= Trappos.x + TrapSize.x - ERROR_MARGIN &&
            gPlayer.position.x + gPlayer.size.x * 0.5f >= Trappos.x - TrapSize.x + ERROR_MARGIN)
        {
            printf("gPlayer below cheese!\n");

            gPlayer.canJump = 0; //Cannot jump if top is blocked
            gPlayer.isJumping = 1;
            gPlayer.velocity.y = 0.0f;
        }

        //gPlayer on the left side of Trap and inside
        if (gPlayer.position.x + gPlayer.size.x * 0.5f >= Trappos.x - TrapSize.x &&
            gPlayer.position.x + gPlayer.size.x * 0.5f <= Trappos.x + TrapSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= Trappos.y - TrapSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= Trappos.y + TrapSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the left of cheese!\n");
            gPlayer.canMoveRight = 0;
        }
        //gPlayer on the right side of Trap
        else if (gPlayer.position.x - gPlayer.size.x * 0.5f <= Trappos.x + TrapSize.x &&
            gPlayer.position.x - gPlayer.size.x * 0.5f >= Trappos.x - TrapSize.x &&
            gPlayer.position.y + gPlayer.size.y * 0.5f >= Trappos.y - TrapSize.y + ERROR_MARGIN && //Allow player to be inside a little bit
            gPlayer.position.y - gPlayer.size.y * 0.5f <= Trappos.y + TrapSize.y - ERROR_MARGIN)
        {
            printf("gPlayer on the right of cheese!\n");

            gPlayer.canMoveLeft = 0;
        }
    }
}

void Collision_PlayerWithDoor(CP_Vector Doorpos, CP_Vector DoorSize)
{
    if (CheckAABB_Collision(gPlayer.position, CP_Vector_Scale(gPlayer.size, 0.5f), Doorpos, DoorSize))

    {
        //printf("Collision detected!\n");
        menu.page = 0;
    }
}


int is_btn_colliding(float mousepositionx, float mousepositiony, CP_Vector buttonPosition)
{
    return mousepositionx >= buttonPosition.x && mousepositionx <= buttonPosition.x + buttonSize.x &&
        mousepositiony >= buttonPosition.y && mousepositiony <= buttonPosition.y + buttonSize.y;
}


void collision_check_button1(CP_Vector buttonPosition)
{
    if (CP_Input_MouseTriggered(MOUSE_BUTTON_1) && is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), buttonPosition))
    {
        printf("clicking\n");
        menu.page = 1;
    }
}

void collision_check_button2(CP_Vector buttonPosition)
{
    if (CP_Input_MouseTriggered(MOUSE_BUTTON_1) && is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), buttonPosition))
    {
        menu.page = 2;
    }
}


