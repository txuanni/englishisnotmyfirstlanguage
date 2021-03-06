/*---------------------------------------------------------
 * file:	player.c
 * author:	Teo Xuan Ni
            * David Tan Wei Jie
            * Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
            * tan.d@digipen.edu
            * qairulshazriz.b@digipen.edu
*
 * brief:	This file contains code to initialise and
            * move the player as well as responses 
            * and give the appopriate responses.
            * Xuan Ni - Did the respawn/die codes
            * David - Movement code, gravity, player speed 
            * and death response
            * Qairul - Animation for the player
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include <stdio.h>
#include "collision.h"
#include "player.h"
#include "cheese.h"
#include "traps.h"
#include "terrain.h"
#include "sceneManager.h"

/*!
@brief Initialise the player
@param void
@return void
*//*______________________________________________________________*/
void player_init(void)
{
    gPlayer.deathcount = 0;
    gPlayer.collidedWithCheese = 0;

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
    gPlayer.idle1GFX = CP_Image_Load("./Assets/idle_left.png");
    gPlayer.leftGFX = CP_Image_Load("./Assets/leftwalk_1.png");
    gPlayer.left1GFX = CP_Image_Load("./Assets/leftwalk_2.png");
    gPlayer.rightGFX = CP_Image_Load("./Assets/walk_1.png");
    gPlayer.right1GFX = CP_Image_Load("./Assets/walk_2.png");

    gPlayer.jumpSFX = CP_Sound_Load("./Assets/jump.wav");
    gPlayer.drownSFX = CP_Sound_Load("./Assets/drown.wav");
    gPlayer.deathSFX = CP_Sound_Load("./Assets/death.wav");
}

/*!
@brief This function contains code fror player's movement
@param float dt
@return void
*//*______________________________________________________________*/
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
        if (CP_Input_KeyReleased(KEY_A) || CP_Input_KeyReleased(KEY_LEFT))
        {
            printf("Hello\n");
            gPlayer.isMovingLeft = 0;
            gPlayer.isMovingRight = 1;
        }
        if (CP_Input_KeyReleased(KEY_D) || CP_Input_KeyReleased(KEY_RIGHT))
        {
            gPlayer.isMovingRight = 0;
            gPlayer.isMovingLeft = 1;
        }
        gPlayer.velocity.x = 0.0f;
    }

    if (CP_Input_KeyDown(KEY_SPACE) && !gPlayer.isJumping &&
        gPlayer.canJump && gPlayer.isGrounded)
    {
        gPlayer.isGrounded = 0;
        gPlayer.isJumping = 1; //Start jumping
        gPlayer.canJump = 0; //Cant jump again once u start jumping
        gPlayer.velocity.y = gPlayer.jumpForce; //Apply instant velocity
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
        gPlayer.velocity.y = 0.0f;
    }
    //Calculate movement
    gPlayer.position = CP_Vector_Add(gPlayer.position, CP_Vector_Scale(gPlayer.velocity, dt));

    //Reset for collision check
    gPlayer.canMoveLeft = 1;
    gPlayer.canMoveRight = 1;
    gPlayer.isGrounded = 0;
}

/*!
@brief renders the player
@param float dt
@return void
*//*______________________________________________________________*/
void player_render(float dt)
{

    //Draw the idle state graphics
    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT)) {
        CP_Image_Draw(gPlayer.leftGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }

    else if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT)) {
        CP_Image_Draw(gPlayer.rightGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }

    else if (gPlayer.isMovingRight == 0) {
        CP_Image_Draw(gPlayer.idleGFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }
    
    else if (gPlayer.isMovingLeft == 0)
    {
        CP_Image_Draw(gPlayer.idle1GFX, gPlayer.position.x, gPlayer.position.y, gPlayer.size.x, gPlayer.size.y, 255);
    }
    printf("Player pos: %.2f, %.2f\n", gPlayer.position.x, gPlayer.position.y);
}

/*!
@brief Respawns the player at a certain position and remove points
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void respawn(CP_Vector* playerpos)
{
    *playerpos = CP_Vector_Set(150.0f, 500.0f);
    cheese->Counter = 0;
}

/*!
@brief If player dies, respawn and set everything back to default
and load death screen
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void die(CP_Vector* playerpos)
{
    gPlayer.deathcount++;
    respawn(playerpos);
    for (int i = 0; i < 26; i++)
    {
        cheese[i].isActive = 1;
    }
    for (int i = 0; i < 16; i++)
    {
        trap[i].isActive = 1;
    }
    for (int i = 24; i < 27; i++)
    {
        terrain[i].isActive = 1;
    }
    menu.page = 3;
}

/*!
@brief If player touches the water, kill the player
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void touch_water(CP_Vector* playerpos)
{
    if ((*playerpos).y >= 900)
    {
        die(playerpos);
        CP_Sound_Play(gPlayer.drownSFX);
    }
}




