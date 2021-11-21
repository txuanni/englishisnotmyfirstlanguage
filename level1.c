#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "collision.h"
#include "camera.h"
#include "menu.h"

CP_Vector playerPosition;
CP_Vector playerGravity;
CP_Vector playerVelocity;
CP_Vector cheesePosition;
CP_Vector cheeseBuffer;
CP_Vector player;

CP_Image backgroundImage = NULL;
float timeElapsed;

void background_init()
{
	backgroundImage = CP_Image_Load("./Assets/background.png");
	platform_init();
	player_init();
	terrain_init();
	cheese_init();
	traps_init();
	camera_init(playerPosition);
	menu_init();
}

void drawbackground()
{
	CP_Image_Draw(backgroundImage, 800, 450, 1600, 900, 255);
}

void gameplay()
{
	timeElapsed = CP_System_GetDt();
	//Note: Always update first before rendering
	//Update
	camera_update(playerPosition, playerGravity,
		playerVelocity, timeElapsed);
	player_update(timeElapsed);

	for (int i = 0; i < 3; i++)
	{
		Collision_PlayerWithPlatform(platforms[i].Position, platforms->Buffer);
	}

	for (int i = 0; i < 11; i++)
	{
		Collision_PlayerWithTerrain(terrain[i].Position, terrain[i].Buffer);
	}
	//Render
	spawn_platform();
	spawn_terrain();
	spawn_traps();
	spawn_cheese();
	player_render();
}
