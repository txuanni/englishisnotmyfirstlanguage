#include "cprocessing.h"
#include <stdio.h>

#define mouse_size 90
#define mouse_buffer 45
#define platform_bufferx 375

CP_Image mouseImage = NULL;
CP_Vector playerVelocity;
CP_Vector playerGravity;
CP_Vector playerPosition;
int isLeft = 0;
int isRight = 0;

float timeElapsed;
int isJumping; //Jumping flag


void mouse_init(void)
{
    playerPosition = CP_Vector_Set(150, 650); //Starting position
    playerGravity = CP_Vector_Set(0, 650); //Gravity for jump
    mouseImage = CP_Image_Load("./Assets/idle.png");
}
void spawn_mouse(void)
{   
    CP_Image_Draw(mouseImage, playerPosition.x, playerPosition.y, mouse_size, mouse_size, 255);
    
}

void mouse_movement(void)
{ 
    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
    {
        playerVelocity.x = -200;
        isLeft = 1;
    }

    else if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
    {
        playerVelocity.x = 200;
        isRight = 1;
        //playerPosition.x += (playerVelocity.x * timeElapsed);
    }

    else if (CP_Input_KeyDown(KEY_S) || CP_Input_KeyDown(KEY_DOWN))
    {
        playerVelocity.y = 400;
        //playerPosition.y += (playerVelocity.y * timeElapsed);
    }

    else if (CP_Input_KeyDown(KEY_W) || CP_Input_KeyDown(KEY_UP))
    {
        playerVelocity.y = -400;
        //playerPosition.y -= (playerVelocity.y * timeElapsed);
    }

    //no input detected set velocity to 0
    else
    {
        playerVelocity.x = 0;
    }

    //left & right movement
    playerPosition.x += playerVelocity.x * timeElapsed;

    if (CP_Input_KeyTriggered(KEY_SPACE) && isJumping == 0)    
    {
        isJumping = 1;
        playerVelocity.y = -400;
        //playerPosition.y -= (playerVelocity.y * timeElapsed);
    }

    // jump movement
    playerPosition.y += playerVelocity.y * timeElapsed;
}

