#include <stdio.h>

#include "collision.h"
#include "player.h"

//#define mouse_size 90
//#define mouse_buffer 45
//#define platform_bufferx 375

//CP_Image mouseImage = NULL;
//CP_Vector playerVelocity;
//CP_Vector playerGravity;
//CP_Vector playerPosition;

//float timeElapsed;
//int isJumping; //Jumping flag

void player_init(void)
{
    gPlayer.canJump = 1;
    gPlayer.isJumping = 0;
    gPlayer.isMovingLeft = 0;
    gPlayer.isMovingRight = 0;
    gPlayer.isGrounded = 0;
    gPlayer.canMoveLeft = 1;
    gPlayer.canMoveRight = 1;
    gPlayer.jumpForce = -400.0f;
    gPlayer.size = CP_Vector_Set(90.0f, 90.0f);
    gPlayer.position = CP_Vector_Set(150.0f, 500.0f);
    gPlayer.velocity = CP_Vector_Zero();
    gPlayer.idleGFX = CP_Image_Load("./Assets/idle.png");
    gPlayer.leftGFX = CP_Image_Load("./Assets/leftwalk_1.png");
    gPlayer.left1GFX = CP_Image_Load("./Assets/leftwalk_2.png");
    gPlayer.rightGFX = CP_Image_Load("./Assets/walk_1.png");
    gPlayer.right1GFX = CP_Image_Load("./Assets/walk_2.png");
    //int leftAnim[2] = { gPlayer.leftGFX, gPlayer.left1GFX };
    //int rightAnim[2] = { gPlayer.rightGFX, gPlayer.right1GFX };
}

void player_update(float dt)
{
    //Player movement
    if ((CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)) &&
        gPlayer.canMoveLeft)
    {
        gPlayer.isMovingLeft = 1;
        gPlayer.velocity.x = -PLAYER_MOVE_SPEED;
    }
    else if ((CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)) &&
        gPlayer.canMoveRight)
    {
        gPlayer.isMovingRight = 1;
        gPlayer.velocity.x = PLAYER_MOVE_SPEED;
    }
    else
    {
        gPlayer.isMovingLeft = 0;
        gPlayer.isMovingRight = 0;
        gPlayer.velocity.x = 0.0f;
    }

    if (CP_Input_KeyDown(KEY_SPACE) && !gPlayer.isJumping &&
        gPlayer.canJump && gPlayer.isGrounded)
    {
        gPlayer.isGrounded = 0;
        gPlayer.isJumping = 1; //Start jumping
        gPlayer.canJump = 0; //Cant jump again once u start jumping
        gPlayer.velocity.y = gPlayer.jumpForce; //Apply instant velocity lol
    }

    //Apply gravity
    if (!gPlayer.isGrounded)
    {
        //printf("Applying gravity\n");
        gPlayer.velocity = CP_Vector_Add(gPlayer.velocity, CP_Vector_Set(0.0f, GRAVITY));
        if (gPlayer.velocity.y >= TERMINAL_VEL) //Cap the max downwards velocity
            gPlayer.velocity.y = TERMINAL_VEL;
    }
    else
    {
        //printf("Player on ground!\n");
        gPlayer.velocity.y = 0.0f;
    }
    //Calculate movement
    gPlayer.position = CP_Vector_Add(gPlayer.position, CP_Vector_Scale(gPlayer.velocity, dt));

    //Reset for collision check
    gPlayer.canMoveLeft = 1;
    gPlayer.canMoveRight = 1;
    gPlayer.isGrounded = 0;
}

void player_render(void)
{
    
    //Draw the idle state graphics
    if (gPlayer.isMovingLeft == 1) {
        CP_Image_Draw(gPlayer.leftGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }
    
    else if (gPlayer.isMovingRight == 1) {
        CP_Image_Draw(gPlayer.rightGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }
    
    else if (gPlayer.isMovingLeft == 0 && gPlayer.isMovingRight == 0) {
        CP_Image_Draw(gPlayer.idleGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }
    printf("Player pos: %.2f, %.2f\n", gPlayer.position.x, gPlayer.position.y);
    //TODO: Change graphics based on moving left/moving right
    //Hint: use if/else or switch statements
}


//==========legacy code==============//
//void mouse_init(void)
//{
//    playerPosition = CP_Vector_Set(150, 650); //Starting position
//    playerGravity = CP_Vector_Set(0, 650); //Gravity for jump
//    mouseImage = CP_Image_Load("./Assets/idle.png");
//}
//void spawn_mouse(void)
//{   
//    CP_Image_Draw(mouseImage, playerPosition.x, playerPosition.y, mouse_size, mouse_size, 255);
//    
//}
//
//void mouse_movement(float dt)
//{ 
//    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
//    {
//        playerVelocity.x = -200;
//        isLeft = 1;
//    }
//
//    else if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
//    {
//        playerVelocity.x = 200;
//        isRight = 1;
//        //playerPosition.x += (playerVelocity.x * timeElapsed);
//    }
//
//    else if (CP_Input_KeyDown(KEY_S) || CP_Input_KeyDown(KEY_DOWN))
//    {
//        playerVelocity.y = 400;
//        //playerPosition.y += (playerVelocity.y * timeElapsed);
//    }
//
//    else if (CP_Input_KeyDown(KEY_W) || CP_Input_KeyDown(KEY_UP))
//    {
//        playerVelocity.y = -400;
//        //playerPosition.y -= (playerVelocity.y * timeElapsed);
//    }
//
//    //no input detected set velocity to 0
//    else
//    {
//        playerVelocity.x = 0;
//    }
//
//    //left & right movement
//    playerPosition.x += playerVelocity.x * timeElapsed;
//
//    if (CP_Input_KeyTriggered(KEY_SPACE) && isJumping == 0)    
//    {
//        isJumping = 1;
//        playerVelocity.y = -400;
//        //playerPosition.y -= (playerVelocity.y * timeElapsed);
//    }
//
//    // jump movement
//    playerPosition.y += playerVelocity.y * timeElapsed;
//}