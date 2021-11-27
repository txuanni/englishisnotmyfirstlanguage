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
CP_Image dead;
CP_Image cheeseCounterImage;
CP_Image backgroundImage = NULL;
CP_Sound eatSFX;
CP_Sound trapSFX;

float timeElapsed;

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
	
}

void drawbackground()
{
	
	CP_Image_Draw(backgroundImage, 800, 450, 1600, 900, 255);
	CP_Settings_Fill(COLOR_WHITE);
	//Death Counter
	CP_Image_Draw(dead, 45, 60, 80, 80, 255);
	CP_Settings_TextSize(80.0f);
	char buffer[100];
	sprintf_s(buffer, 100, "X %.0d", gPlayer.deathcount);
	CP_Font_DrawText(buffer, 85, 75);

	//Cheese Counter
	CP_Image_Draw(cheeseCounterImage, 35, 120, 50, 50, 128);
	CP_Settings_TextSize(80.0f);
	sprintf_s(buffer, 100, "X %.0d", cheese->Counter);
	CP_Font_DrawText(buffer, 85, 140);
}

void gameplay()
{
	timeElapsed = CP_System_GetDt();
	//Note: Always update first before rendering
	//Update
	camera_update(gPlayer.position, gPlayer.size, timeElapsed);
	player_update(timeElapsed);

	

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
				CP_Sound_Play(eatSFX);
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
				CP_Sound_Play(trapSFX);
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
				CP_Sound_Play(eatSFX);
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
				CP_Sound_Play(trapSFX);
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


	for (int i = 0; i < 30; i++)
	{
		//Collision_PlayerWithTraps(trap[i].Position, trap->Buffer);
	}

	//die
	Collision_PlayerWithDoor(door.Position, door.Buffer);
	touch_water(&gPlayer.position);
	//Render
	spawn_platform();

	spawn_door();
	player_render(timeElapsed);
}
