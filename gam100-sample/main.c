
/*---------------------------------------------------------
 * file:	Prototype
 * author:	[David]
 * email:	[tan.d@digipen.edu]
*
 * brief:	Main entry point for the sample project
            * of the CProcessing library
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
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
CP_Image mouseIdle, mouseMove1, mouseMove2, mouseDead;
struct Box
{
    CP_Vector Position;
    float height;
    float width;
};
struct Box Box1, Box2;

/*float collisionleft(CP_Vector topleft, CP_Vector btmleft)
{
    if(player_x + radius > topleft && player_x + radius > btmleft)
}*/

void game_init(void)
{
    CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
    //setFrameRate(60.0f);
    
    //Start position
    player_x = 20;
    player_y = 780;
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
    mouseMove1 = CP_Image_Load("./Assets/walk_1.png");
    mouseMove2 = CP_Image_Load("./Assets/walk_2.png");
    mouseDead = CP_Image_Load("./Assets/die.png");

}

void game_update(void)
{
    //Left Movement
    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
    {
        player_x -= 10;
    }

    //Right Movement
    if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
    {
        player_x += 10;
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


    //Set white background
    CP_Graphics_ClearBackground(CP_Color_Create(0,0,0,0));
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 255));

    CP_Graphics_DrawRect(Box1.Position.x, Box1.Position.y, Box1.width, Box1.height);
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 150));

    CP_Graphics_DrawRect(Box2.Position.x, Box2.Position.y, Box2.width, Box2.height);
    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

    //Mouse
    //CP_Graphics_DrawCircle(player_x, player_y, 40);
    CP_Image_Draw(mouseIdle, player_x, player_y, 40, 40, 120);

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
