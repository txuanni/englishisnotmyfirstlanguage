#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "collision.h"
#include "camera.h"
#include "sceneManager.h"
#include "menu.h"
#include "level1.h"

#define recommendedWidth 1600
#define recommendedHeight 900
CP_Vector playerPosition;
CP_Vector playerGravity;
CP_Vector playerVelocity;
CP_Vector platformPosition;
CP_Vector platformPosition2;
CP_Vector platformPosition3;
CP_Vector platformBuffer;
CP_Vector cheesePosition;
CP_Vector cheeseBuffer;
<<<<<<< Updated upstream
CP_Vector player, terrain, terrainbuffer;

struct sceneManager game;
=======
CP_Vector terrainPosition;
CP_Vector terrainBuffer;
>>>>>>> Stashed changes

static float timeElapsed;

void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	CP_System_SetFrameRate(60.0f);

	platform_init();
	player_init();
<<<<<<< Updated upstream
	//mouse_init();
	terrain_init();
	cheese_init();
	traps_init();
	camera_init(playerPosition);

	sceneManger_init(&game);
=======
	terrain_init();
	cheese_init();
	traps_init();
	camera_init();
	menu_init(); 
	background_init();
	sceneManager_init();
>>>>>>> Stashed changes
}
void game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	timeElapsed = CP_System_GetDt();

<<<<<<< Updated upstream
	float dt = CP_System_GetDt();
	//Note: Always update first before rendering
	//Update
	camera_update(playerPosition, playerGravity,
		playerVelocity, timeElapsed);
	player_update(dt);
	Collision_PlayerWithPlatform(platformPosition2, platformBuffer);
	Collision_PlayerWithPlatform(platformPosition3, platformBuffer);
	Collision_PlayerWithPlatform(platformPosition, platformBuffer);
	//mouse_movement();
	//collision_check_platform(playerPosition, platformPosition, platformBuffer);
	//collision_check_cheese(playerPosition, cheesePosition, cheeseBuffer);
	//collision_check_terrain(player, terrain, terrainbuffer);

	//Render
	draw_background(&game);
	spawn_platform();
	spawn_terrain();
	spawn_traps();
	spawn_cheese();
	//spawn_mouse();
	player_render();
=======
	switchPage();
	
>>>>>>> Stashed changes
}
void game_exit(void)
{

}