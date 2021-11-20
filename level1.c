#include "cprocessing.h"
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "collision.h"
#include "camera.h"

CP_Vector playerPosition;
CP_Vector platformPosition;
CP_Vector platformBuffer;
CP_Vector cheesePosition;
CP_Vector cheeseBuffer;
CP_Vector terrainPosition;
CP_Vector terrainBuffer;
CP_Image backgroundImage = NULL;

void background_init()
{
	backgroundImage = CP_Image_Load("./Assets/background.png");
}

void drawbackground()
{
	CP_Image_Draw(backgroundImage, 800, 450, 1600, 900, 255);
}

void gameplay()
{
	camera_update();
	spawn_platform();
	spawn_terrain();
	spawn_traps();
	spawn_cheese();
	spawn_mouse();

	mouse_movement();
	collision_check_platform(playerPosition, platformPosition, platformBuffer);
	collision_check_cheese(playerPosition, cheesePosition, cheeseBuffer);
	collision_check_terrain(playerPosition, terrainPosition, terrainBuffer);
}