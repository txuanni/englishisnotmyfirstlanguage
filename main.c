

/*---------------------------------------------------------
 * file:	main.c
 * author:	[NAME]
 * email:	[DIGIPEN EMAIL ADDRESS]
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
CP_Vector gravity;
struct Box
{
    CP_Vector Position;
    float height;
    float width;
};
struct Box Box1, Box2;


void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	//setFrameRate(60.0f);
    
    player_x = 20;
    player_y = 780;
    gravity = CP_Vector_Set(0.0, 100.0);
    Box1.Position = CP_Vector_Set(0.0, 800.0);
    Box1.width = 700;
    Box1.height = 600;
    Box2.Position = CP_Vector_Set(800, 800);
    Box2.width = 900;
    Box2.height = 600;
}

void game_update(void)
 {
        player_y += gravity.y * CP_System_GetDt();
    if ((player_x > Box1.Position.x && player_x < Box1.Position.x + Box1.width && player_y > Box1.Position.y - radius - 10 && player_y < Box1.Position.y + Box1.height))
    {
        player_y = Box1.Position.y - radius;
        isJumping = false;
    }
    if ((player_x > Box2.Position.x && player_x < Box2.Position.x + Box2.width && player_y > Box2.Position.y - radius && player_y < Box2.Position.y + Box2.height))
    {
        player_y = Box2.Position.y - radius;
        isJumping = false;
    }


    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
    {
        player_x -= 10;
    }
    if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
    {
        player_x += 10;
    }

    if (CP_Input_KeyTriggered(KEY_SPACE) && isJumping == false)
    {
        isJumping = true;
        playerjump = 1000;
    }

    if (isJumping)
    {
        player_y -= playerjump*CP_System_GetDt();
        playerjump -= gravity.y;
    }

     

    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 0));
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 255));
    CP_Graphics_DrawRect(Box1.Position.x, Box1.Position.y, Box1.width, Box1.height);
    CP_Settings_Fill(CP_Color_Create(150, 75, 0, 150));
    CP_Graphics_DrawRect(Box2.Position.x, Box2.Position.y, Box2.width, Box2.height);

    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
    CP_Graphics_DrawCircle(player_x, player_y, 40);

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
