/*!
@file level1.c
@author David Tan Wei Jie (tan.d@digipen.edu)
		Teo Xuan Ni (t.xuanni@digipen.edu)
		Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code for level1 
*//*______________________________________________________________*/
#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "door.h"
#include "collision.h"
#include "camera.h"
#include "menu.h"

#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Vector playerPosition;
CP_Vector playerGravity;
CP_Vector playerVelocity;
CP_Vector player;
CP_Image dead = NULL;
CP_Image cheeseCounterImage = NULL;
CP_Image backgroundImage = NULL;
CP_Sound eatSFX = NULL;
CP_Sound trapSFX = NULL;

float timeElapsed;
float random_float;

/*!
@brief Initialise the background and other objects
@param void
@return void
*//*______________________________________________________________*/
void background_init()
{
	backgroundImage = CP_Image_Load("./Assets/background.png");
	dead = CP_Image_Load("./Assets/die.png");
	cheeseCounterImage = CP_Image_Load("./Assets/cheese.png");
	platform_init();
	player_init();
	terrain_init();
	cheese_init();
	traps_init();
	door_init();
	camera_init(playerPosition);
	eatSFX = CP_Sound_Load("./Assets/eat.wav");
	trapSFX = CP_Sound_Load("./Assets/death.wav");
	random_float = CP_Random_RangeFloat(0.9f, 1.1f);
	
}

/*!
@brief Initialise the background and other objects
@param void
@return void
*//*______________________________________________________________*/
void drawbackground()
{
	
	CP_Image_Draw(backgroundImage, 800, 450, 1605, 905, 255);
	CP_Settings_Fill(COLOR_WHITE);
	//Death Counter
	CP_Image_Draw(dead, 60, 60, 80, 60, 255);
	CP_Settings_TextSize(80.0f);
	char buffer[100];
	sprintf_s(buffer, 100, "x %.0d", gPlayer.deathcount);
	CP_Font_DrawText(buffer, 105, 75);

	//Cheese Counter
	CP_Image_Draw(cheeseCounterImage, 50, 120, 50, 50, 255);
	CP_Settings_TextSize(80.0f);
	sprintf_s(buffer, 100, "x %.0d", cheese->Counter);
	CP_Font_DrawText(buffer, 100, 140);
}

/*!
@brief Render codes for the gameplay
@param void
@return void
*//*______________________________________________________________*/
void gameplay()
{
	//Note: Always update first before rendering
	//Update
	camera_update(gPlayer.position, gPlayer.size, timeElapsed);
	player_update(timeElapsed);

	//game explaination text
	CP_Settings_TextSize(50.0f);
	CP_Settings_Fill(COLOR_WHITE);
	CP_Font_DrawText("There's a door awaiting the mouse at the end for it's escape.", -500, 300);
	CP_Font_DrawText("Cheese and traps may either be harmless or harmful, be cautious... ", -500, 350);
	CP_Font_DrawText("Also, some of those terrains do look suspicious...", -500, 400);
	CP_Font_DrawText("Are you able to reach the end? Good luck!", -500, 450);

	//spawn good cheese and add points if collided
	for (int i = 0; i < 21; i++)
	{
		if (cheese[i].isActive)
		{
			CP_Image_Draw(cheese->Image, cheese[i].Position.x, cheese[i].Position.y, cheese->Size.x, cheese->Size.y, 255);
			Collision_PlayerWithObstacle(cheese[i].Position, cheese->Buffer);
			if (gPlayer.collidedWithObs == 1)
			{
				cheese[i].isActive = 0;
				gPlayer.collidedWithObs = 0;
				cheese->Counter++;
				
				CP_Sound_PlayAdvanced(eatSFX, 0.2f,random_float, FALSE, 0);
			}
		}
	}

	//spawn bad cheese, reset and add death count
	for (int i = 21; i < 27; i++)
	{
		if (cheese[i].isActive)
		{
			CP_Image_Draw(cheese->Image, cheese[i].Position.x, cheese[i].Position.y, cheese->Size.x, cheese->Size.y, 255);
			Collision_PlayerWithObstacle(cheese[i].Position, cheese->Buffer);
			if (gPlayer.collidedWithObs == 1)
			{
				cheese[i].isActive = 0;
				gPlayer.collidedWithObs = 0;
				die(&gPlayer.position);
				CP_Sound_PlayAdvanced(trapSFX, 0.1f, random_float, FALSE, 0);
			}
		}
	}

	//spawn good traps 
	for (int i = 0; i < 11; i++)
	{
		if (trap[i].isActive)
		{
			CP_Image_Draw(trap->Image, trap[i].Position.x, trap[i].Position.y, trap->Size.x, trap->Size.y, 255);
			Collision_PlayerWithObstacle(trap[i].Position, trap->Buffer);
			if (gPlayer.collidedWithObs == 1)
			{
				trap[i].isActive = 0;
				gPlayer.collidedWithObs = 0;
				/*CP_Sound_Play(eatSFX);*/
				CP_Sound_PlayAdvanced(eatSFX, 0.2f, random_float, FALSE, 0);
			}
		}
	}

	//spawn bad trap, reset and add death count
	for (int i = 10; i < 16; i++)
	{
		if (trap[i].isActive)
		{
			CP_Image_Draw(trap->Image, trap[i].Position.x, trap[i].Position.y, trap->Size.x, trap->Size.y, 255);
			Collision_PlayerWithObstacle(trap[i].Position, trap->Buffer);
			if (gPlayer.collidedWithObs == 1)
			{
				trap[i].isActive = 0;
				gPlayer.collidedWithObs = 0;
				die(&gPlayer.position);
				/*CP_Sound_Play(trapSFX);*/
				CP_Sound_PlayAdvanced(trapSFX, 0.1f, random_float, FALSE, 0);
			}
		}
	}

	for (int i = 0; i < 24; i++)
	{
		CP_Image_Draw(terrain->Image, terrain[i].Position.x, terrain[i].Position.y, terrain[i].Size.x, terrain[i].Size.y, 255);
		Collision_PlayerWithTerrain(terrain[i].Position, terrain[i].Buffer);
	}

	for (int i = 24; i < 27; i++)
	{
		if (terrain[i].isActive)
		{
			CP_Image_Draw(terrain->Image, terrain[i].Position.x, terrain[i].Position.y, terrain[i].Size.x, terrain[i].Size.y, 255);
			Collision_PlayerWithObstacle(terrain[i].Position, terrain[i].Buffer);
			if (gPlayer.collidedWithObs == 1)
			{
				terrain[i].isActive = 0;
				gPlayer.collidedWithObs = 0;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		Collision_PlayerWithPlatform(platforms[i].Position, platforms->Buffer);
	}

	//die
	Collision_PlayerWithDoor(door.Position, door.Buffer);
	touch_water(&gPlayer.position);
	//Render
	spawn_platform();
	spawn_door();
	player_render(timeElapsed);
}
