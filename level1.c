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

CP_Vector playerPosition;
CP_Vector playerGravity;
CP_Vector playerVelocity;
CP_Vector player;
CP_Image dead;
CP_Image cheeseCounter;
CP_Image backgroundImage = NULL;
float timeElapsed;

void background_init()
{
	backgroundImage = CP_Image_Load("./Assets/background.png");
	dead = CP_Image_Load("./Assets/die.png");
	cheeseCounter = CP_Image_Load("./Assets/cheese.png");
	platform_init();
	player_init();
	terrain_init();
	cheese_init();
	traps_init();
	door_init();
	camera_init(playerPosition);

	
}

void drawbackground()
{
	
	CP_Image_Draw(backgroundImage, 800, 450, 1600, 900, 255);

	//Death Counter
	CP_Image_Draw(dead, 45, 60, 80, 80, 255);
	CP_Settings_TextSize(80.0f);
	char buffer[100];
	sprintf_s(buffer, 100, "X %.0d", gPlayer.deathcount);
	CP_Font_DrawText(buffer, 85, 75);

	//Cheese Counter
	CP_Image_Draw(cheeseCounter, 35, 120, 50, 50, 128);
	CP_Settings_TextSize(80.0f);
	sprintf_s(buffer, 100, "X %.0d", gPlayer.cheesecount);
	CP_Font_DrawText(buffer, 85, 140);
}

void gameplay()
{
	timeElapsed = CP_System_GetDt();
	//Note: Always update first before rendering
	//Update
	camera_update(gPlayer.position, gPlayer.size, timeElapsed);
	player_update(timeElapsed);

	for (int i = 0; i < 5; i++)
	{
		Collision_PlayerWithBadCheese(cheese[i].Position, cheese->Buffer);
	}
	
	for (int i = 5; i < 11; i++)
	{
		if (cheese->isActive)
		{
			Collision_PlayerWithGoodCheese(cheese[i].Position, cheese->Buffer);
			if (gPlayer.collidedWithCheese == 1)
			{
				cheese->isActive = 0;
				gPlayer.cheesecount++;
				CP_Image_Free(&cheese[5].Image);
			}
	
		}
		if (!cheese->isActive)
		{
			spawn_good_cheese();
		}		
	}

	for (int i = 0; i < 3; i++)
	{
		Collision_PlayerWithPlatform(platforms[i].Position, platforms->Buffer);
	}

	for (int i = 0; i < 11; i++)
	{
		Collision_PlayerWithTerrain(terrain[i].Position, terrain[i].Buffer);
	}

	for (int i = 0; i < 2; i++)
	{
		Collision_PlayerWithTraps(trap[i].Position, trap->Buffer);
	}
	Collision_PlayerWithDoor(door.Position, door.Buffer);
	touch_water(&gPlayer.position);
	//Render
	spawn_platform();
	spawn_terrain();
	spawn_traps();
	spawn_door();
	spawn_good_cheese();
	spawn_bad_cheese();
	player_render(timeElapsed);
}
