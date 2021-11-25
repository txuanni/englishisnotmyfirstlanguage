#include "cprocessing.h"
#include "platform.h"
#include <stdio.h>


void platform_init(void)
{
	platforms->Image = CP_Image_Load("./Assets/platform.png");
	platforms->Size = CP_Vector_Set(800, 100);
	platforms->Buffer = CP_Vector_Set(400, 50);


	platforms[0].Position = CP_Vector_Set(400, 790);

	platforms[1].Position = CP_Vector_Set(2100, 350);

	platforms[2].Position = CP_Vector_Set(3200, 790);

	platforms[3].Position = CP_Vector_Set(6100, 790);

	platforms[4].Position = CP_Vector_Set(9700, 790);


}

void spawn_platform(void)
{
	for (int i = 0; i < 5; i++)
	{
		CP_Image_Draw(platforms->Image, platforms[i].Position.x, platforms[i].Position.y, platforms->Size.x, platforms->Size.y, 255);
	}
}
