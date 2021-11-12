#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "camera.h"
#include "collision.h"

#define recommendedWidth 1600
#define recommendedHeight 900
CP_Vector playerPosition;
CP_Vector platformPosition;
CP_Vector platformBuffer;
CP_Vector cheesePosition;
CP_Vector cheeseBuffer;


float timeElapsed;

void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	platform_init();
	mouse_init();
	terrain_init();
	cheese_init();
	camera_init();
}
void game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	timeElapsed = CP_System_GetDt();
	camera_update();
	spawn_platform();
	spawn_terrain();
	spawn_cheese();
	spawn_mouse();

	mouse_movement();
	collision_check_platform(playerPosition, platformPosition, platformBuffer);
	collision_check_cheese(playerPosition, cheesePosition, cheeseBuffer);
}
void game_exit(void)
{

}