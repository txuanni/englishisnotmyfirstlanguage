
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
#define buffer 20
bool isJumping = false;
bool isFalling = false;
bool isMoving = false;
CP_Vector gravity;
CP_Image mouseIdle, mouseMoveRight1, mouseMoveRight2
, mouseMoveLeft1, mouseMoveLeft2, mouseDead;

typedef struct _player
{
    CP_Vector position;
    float playerjump;
    CP_Vector player_velocity;
    bool faceLeft;
    bool faceRight;
}player;
player mouse;

typedef struct Box
{
    CP_Vector Position;
    float height;
    float width;
}box;
struct Box Box1, Box2;

struct Box Box1, Box2;

void deathcount(bool dead)
{

    //if (mouse == FALSE)
    {

        //int deathcount;
       // deathcount++;

    }
}
// Box based collision
bool collision(CP_Vector bowser, box block)
{
    if ((bowser.x + buffer) <= (block.Position.x + block.width) && (bowser.x + buffer) >= block.Position.x &&
        (bowser.y + buffer) <= (block.Position.y + block.height) && (bowser.y + buffer) >= block.Position.y)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void collision_check(CP_Vector *bowser, box block)
{
    CP_Vector tmp;
    tmp = *bowser;
    if(bowser->y + buffer >= block.Position.y  && bowser->x >= block.Position.x && bowser->x <= block.Position.x + block.width)//top
    {
        tmp.y = block.Position.y - buffer;
        isJumping = FALSE;
    }
    else if(bowser->y + buffer  <= block.Position.y + block.height && bowser->x >= block.Position.x && bowser->x <= block.Position.x + block.width)//btm
    {
         tmp.y = block.Position.y + block.height + buffer;
         isJumping = FALSE;

    }
    if (bowser->x + buffer >= block.Position.x &&
    bowser->y >= block.Position.y && bowser->y <= block.Position.y + block.height)//left
    {
    tmp.x = block.Position.x - buffer;
    bowser->x = tmp.x;
    bowser->y = tmp.y;
    }
    else if (bowser->x + buffer <= block.Position.x + block.width &&
    bowser->y >= block.Position.y && bowser->y <= block.Position.y + block.height)//right
    {
    tmp.x = block.Position.x + block.width + buffer;
    bowser->y = tmp.y;
    }
    *bowser = tmp;
}


void game_init(void)
{
    CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
    //setFrameRate(60.0f);
    
    //Start position
    mouse.position = CP_Vector_Set(20.0, 700.0);
    gravity = CP_Vector_Set(0.0, 750.0); //Set Gravity

    //(Left) Box1 Elements
    Box1.Position = CP_Vector_Set(0.0, 800.0);
    Box1.width = 700;
    Box1.height = 600;

    //(Right) Box 2 Elements
    Box2.Position = CP_Vector_Set(300.0, 700);
    Box2.width = 200;
    Box2.height = 90;

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
    //Left and Right Movement
    if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
    {
        mouse.player_velocity.x = -200.0;
        mouse.faceLeft = 1;
    }
    else if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
    {
        mouse.player_velocity.x = 200.0;
        mouse.faceRight = 1;
    }
    else
    {
        //No input, go to idle
        mouse.faceRight = 0;
        mouse.faceLeft = 0;
        mouse.player_velocity.x = 0;
    }

    //Gravity is always on player
    mouse.player_velocity.y += gravity.y * CP_System_GetDt();
    if (mouse.player_velocity.y > 250)
    {
        mouse.player_velocity.y = 250;
    }
    mouse.position.x += mouse.player_velocity.x * CP_System_GetDt();

    // jump movement
    mouse.position.y += mouse.player_velocity.y * CP_System_GetDt();
    
    // collision check monkaS
    if (collision(mouse.position, Box1))
    {
        collision_check(&mouse.position, Box1);
    }
    printf("%.2f , %.2f\n", mouse.position.x, mouse.position.y);

    if (collision(mouse.position, Box2))
    {
        collision_check(&mouse.position, Box2);
    }

        //Set spacebar to jump
        if (CP_Input_KeyTriggered(KEY_SPACE) && isJumping == false)
        {
            isJumping = true;
            mouse.player_velocity.y = -400;
        }

        //Code for if mouse is moving
        if (isMoving)
        {

        }

        char deathcount[999];
        sprintf_s(deathcount, sizeof(deathcount) / sizeof(deathcount[0]), "%d", 42);
        // mouse render for left and right
    CP_Image moveRightArray[] = { mouseMoveRight1, mouseMoveRight2 };
    CP_Image moveLeftArray[] = { mouseMoveLeft1, mouseMoveLeft2 };
        if (mouse.faceLeft == 1) //Face left
        {
            for (int i = 0; i < 2; i++) {
                CP_Image_Draw(moveLeftArray[i], mouse.position.x, mouse.position.y
                    , 40, 40, 120);
            }
        }
        else if (mouse.faceRight == 1) //Face right
        {
            for (int i = 0; i < 2; i++) {
                CP_Image_Draw(moveRightArray[i], mouse.position.x, mouse.position.y
                    , 40, 40, 120);
            }
        }
        else //Idle
        {
            CP_Image_Draw(mouseIdle, mouse.position.x, mouse.position.y, 40, 40, 255);
        }

        //set death count
        CP_TEXT_ALIGN_HORIZONTAL horizontal = CP_TEXT_ALIGN_H_CENTER;
        CP_TEXT_ALIGN_VERTICAL vertical = CP_TEXT_ALIGN_V_MIDDLE;

        CP_Font_DrawText(deathcount, 80, 80);
        CP_Settings_TextAlignment(horizontal, vertical);
        CP_Settings_TextSize(60);
        CP_Image_Draw(mouseIdle, 20, 80, 40, 40, 120);

        //Set white background
        CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
        CP_Settings_Fill(CP_Color_Create(150, 75, 0, 255));

        CP_Graphics_DrawRect(Box1.Position.x, Box1.Position.y, Box1.width, Box1.height);
        CP_Settings_Fill(CP_Color_Create(150, 75, 0, 150));

        CP_Graphics_DrawRect(Box2.Position.x, Box2.Position.y, Box2.width, Box2.height);
        CP_Settings_Fill(CP_Color_Create(255, 0, 0, 150));

        //Mouse
        CP_Image_Draw(mouseIdle, mouse.position.x, mouse.position.y, 40, 40, 255);

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
