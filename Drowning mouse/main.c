
/*---------------------------------------------------------
 * file:	Prototype
 * author:	
 * email:	
*
 * brief:	Main entry point for the sample project
            * of the CProcessing library
*
 * documentation link:
 * https://github.com/DigiPen-Faculty/CProcessing/wiki
*
 * Copyright © 2020 DigiPen, All rights reserved.
* ---------------------------------------------------------*/

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "cprocessing.h"
#define ground 800
#define jumpheight 100
#define recommendedWidth 1600
#define recommendedHeight 900
#define range 5
#define radius 20
float playerjump;
float player_x;
float player_y;
bool isJumping = false;
bool isFalling = false;
bool isMoving = false;
CP_Vector gravity;
CP_Image mouseIdle, mouseMoveRight1, mouseMoveRight2
, mouseMoveLeft1, mouseMoveLeft2, mouseDead;

struct Box
{
    CP_Vector Position;
    float height;
    float width;
};

struct Box Box1, Box2;

void deathcount(bool mouse)
{

    //if (mouse == FALSE)
    {

        //int deathcount;
       // deathcount++;

    }
}

void game_init(void)
{
    CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
    //setFrameRate(60.0f);
    
    //Start position
    player_x = 20;
    player_y = 710;
    gravity = CP_Vector_Set(0.0, 100.0); //Set Gravity

    //(Left) Box1 Elements
    Box1.Position = CP_Vector_Set(0.0, 800.0);
    Box1.width = 700;
    Box1.height = 600;

    //(Right) Box 2 Elements
    Box2.Position = CP_Vector_Set(800, 800);
    Box2.width = 900;
    Box2.height = 600;

    //Mouse Images
    mouseIdle = CP_Image_Load("./Assets/idle.png");
    mouseMoveRight1 = CP_Image_Load("./Assets/walk_1.png");
    mouseMoveRight2 = CP_Image_Load("./Assets/walk_2.png");
    mouseMoveLeft1 = CP_Image_Load("./Assets/walk_1_left.png");
    mouseMoveLeft2 = CP_Image_Load("./Assets/walk_2_left.png");
    mouseDead = CP_Image_Load("./Assets/die.png");

    

}

void game_update(void)
{
    CP_Image moveRightArray[] = {mouseMoveRight1, mouseMoveRight2};
    CP_Image moveLeftArray[] = {mouseMoveLeft1, mouseMoveLeft2};
    //Left Movement
    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
    {
        player_x -= 10;
        

        for (int i = 0; i < 2; i++) {
            CP_Image_Draw(moveLeftArray[i], player_x, player_y-30, 90, 90, 120);
        }
        
    }

    //Right Movement
    if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
    {
        player_x += 10;
        for (int i = 0; i < 2; i++) {
            CP_Image_Draw(moveRightArray[i], player_x, player_y-30, 90, 90, 120);
        }
        
    }

    //Gravity is always on player
    player_y += gravity.y * CP_System_GetDt();


    if (player_x > Box1.Position.x && 
        player_x < Box1.Position.x + Box1.width && 
        player_y > Box1.Position.y - radius - 10 && 
        player_y < Box1.Position.y + Box1.height)
    {
        isJumping = false;

        if (player_x >= Box1.Position.x && 
            player_x <= Box1.Position.x + Box1.width && 
            player_y > Box1.Position.y && 
            player_y < Box1.Position.y + Box1.height)
        {
            if (player_x + radius < Box1.Position.x)
            {
                player_x = Box1.Position.x - radius;
            }
            else if (player_x - radius < Box1.Position.x + Box1.width)
            {
                player_x = Box1.Position.x + Box1.width + radius;
            }

        }
        else if (player_y + radius > Box1.Position.y)
        {
            player_y = Box1.Position.y - radius;
        }

    }


    if ((player_x > Box2.Position.x && 
        player_x < Box2.Position.x + Box2.width && 
        player_y > Box2.Position.y - radius && 
        player_y < Box2.Position.y + Box2.height))
    {
        player_y = Box2.Position.y - radius;
        isJumping = false;
    }


    //Set spacebar to jump
    if (CP_Input_KeyTriggered(KEY_SPACE) && isJumping == false)
    {
        isJumping = true;
        playerjump = 1000;
    }

    //Code for jumping
    if (isJumping)
    {
        player_y -= playerjump * CP_System_GetDt();
        playerjump -= gravity.y;
    }
    
    //Code for if mouse is moving
    if (isMoving)
    {

    }

    char deathcount[999];
    sprintf_s(deathcount,sizeof(deathcount)/sizeof(deathcount[0]),"%d", 42);

    //set death count
    CP_TEXT_ALIGN_HORIZONTAL horizontal = CP_TEXT_ALIGN_H_CENTER;
    CP_TEXT_ALIGN_VERTICAL vertical = CP_TEXT_ALIGN_V_MIDDLE;
    
    CP_Font_DrawText(deathcount, 80, 80);
    CP_Settings_TextAlignment(horizontal, vertical);
    CP_Settings_TextSize(60);
    CP_Image_Draw(mouseIdle, 20, 80, 40, 40, 120);

    //Set white background
    CP_Graphics_ClearBackground(CP_Color_Create(0,0,0,0));
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 255));

    CP_Graphics_DrawRect(Box1.Position.x, Box1.Position.y, Box1.width, Box1.height);
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 150));

    CP_Graphics_DrawRect(Box2.Position.x, Box2.Position.y, Box2.width, Box2.height);
    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 150));

    //Mouse
    CP_Image_Draw(mouseIdle, player_x, player_y, 90, 90, 120);

}


void game_exit(void)
{

}

int main(void)
{
    CP_System_ShowConsole();
    CP_Engine_SetNextGameState(game_init, game_update, game_exit);
    CP_Engine_Run();
    return 0;
}
