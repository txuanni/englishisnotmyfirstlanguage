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

#define recommendedWidth 1600
#define recommendedHeight 900
CP_Vector playerPosition;
CP_Vector platformPosition;
CP_Vector platformBuffer;
CP_Vector cheesePosition;
CP_Vector cheeseBuffer;
CP_Vector player, terrain, terrainbuffer;

struct sceneManager game;

float timeElapsed;

void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	platform_init();
	mouse_init();
	terrain_init();
	cheese_init();
	traps_init();
	camera_init();
	
	sceneManger_init(&game);
}
void game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	timeElapsed = CP_System_GetDt();

	draw_background(&game);
	camera_update();
	spawn_platform();
	spawn_terrain();
	spawn_traps();
	spawn_cheese();
	spawn_mouse();

	mouse_movement();
	collision_check_platform(playerPosition, platformPosition, platformBuffer);
	collision_check_cheese(playerPosition, cheesePosition, cheeseBuffer);
	collision_check_terrain(player, terrain, terrainbuffer);
}
void game_exit(void)
{

}