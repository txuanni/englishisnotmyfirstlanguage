#include "cprocessing.h"

CP_Vector terrainPosition;
CP_Vector terrainSize;
CP_Vector terrainBuffer;
CP_Image terrainImage = NULL;

void terrain_init(void)
{
	terrainPosition = CP_Vector_Set(700, 600);
	terrainSize = CP_Vector_Set(130, 40);
	terrainBuffer = CP_Vector_Set(805, 105);
	terrainImage = CP_Image_Load("./Assets/terrain.png");
}

void spawn_terrain(void)
{
	CP_Image_Draw(terrainImage, terrainPosition.x, terrainPosition.y, terrainSize.x, terrainSize.y, 255);
}

