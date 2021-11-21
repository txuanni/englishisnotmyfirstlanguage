#include "cprocessing.h"
#include "terrain.h"

void terrain_init(void)
{
	terrain->Image = CP_Image_Load("./Assets/terrain.png");

	terrain[0].Position = CP_Vector_Set(400, 550);
	terrain[0].Size = CP_Vector_Set(300, 50);
	terrain[0].Buffer = CP_Vector_Set(150, 25);

	terrain[1].Position = CP_Vector_Set(750, 650);
	terrain[1].Size = CP_Vector_Set(120, 50);
	terrain[1].Buffer = CP_Vector_Set(60, 25);

	terrain[2].Position = CP_Vector_Set(1050, 550);
	terrain[2].Size = CP_Vector_Set(120, 50);
	terrain[2].Buffer = CP_Vector_Set(60, 25);

	terrain[3].Position = CP_Vector_Set(1300, 450);
	terrain[3].Size = CP_Vector_Set(150, 50);
	terrain[3].Buffer = CP_Vector_Set(75, 25);

	terrain[4].Position = CP_Vector_Set(1560, 550);
	terrain[4].Size = CP_Vector_Set(120, 50);
	terrain[4].Buffer = CP_Vector_Set(60, 25);

	terrain[5].Position = CP_Vector_Set(1050, 310);
	terrain[5].Size = CP_Vector_Set(300, 50);
	terrain[5].Buffer = CP_Vector_Set(150, 25);

	terrain[6].Position = CP_Vector_Set(1650, 310);
	terrain[6].Size = CP_Vector_Set(500, 50);
	terrain[6].Buffer = CP_Vector_Set(250, 25);

	terrain[7].Position = CP_Vector_Set(2100, 350);
	terrain[7].Size = CP_Vector_Set(120, 50);
	terrain[7].Buffer = CP_Vector_Set(60, 25);

	terrain[8].Position = CP_Vector_Set(2100, 450);
	terrain[8].Size = CP_Vector_Set(120, 50);
	terrain[8].Buffer = CP_Vector_Set(60, 25);

	terrain[9].Position = CP_Vector_Set(2100, 550);
	terrain[9].Size = CP_Vector_Set(120, 50);
	terrain[9].Buffer = CP_Vector_Set(60, 25);

	terrain[10].Position = CP_Vector_Set(2500, 300);
	terrain[10].Size = CP_Vector_Set(400, 50);
	terrain[10].Buffer = CP_Vector_Set(200, 25);
}

void spawn_terrain(void)
{
	for (int i = 0; i < 11; i++)
	{
		CP_Image_Draw(terrain->Image, terrain[i].Position.x, terrain[i].Position.y, terrain[i].Size.x, terrain[i].Size.y, 255);
	}
}

