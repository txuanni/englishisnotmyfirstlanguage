#include "traps.h"

void traps_init(void)
{
	trap->Image = CP_Image_Load("./Assets/traps.png");
	trap->Size = CP_Vector_Set(110, 60);
	trap->Buffer = CP_Vector_Set(55, 30);

	trap[0].Position = CP_Vector_Set(700, 650);
	trap[1].Position = CP_Vector_Set(900, 700);
}

void spawn_traps(void)
{
	for (int i = 0; i < 11; i++)
	{
		CP_Image_Draw(trap->Image, trap[i].Position.x, trap[i].Position.y, trap->Size.x, trap->Size.y, 255);
	}
}

