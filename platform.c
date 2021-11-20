#include "cprocessing.h"
#include "platform.h"


void platform_init(void)
{
	platforms[0].Size = CP_Vector_Set(1000, 100);
	platforms[0].Buffer = CP_Vector_Set(500, 50);
	platforms[0].Position = CP_Vector_Set(400, 350);
	platforms[1].Position = CP_Vector_Set(400, 700);
	platforms[2].Position = CP_Vector_Set(800, 600);
	platforms[0].Image = CP_Image_Load("./Assets/platform.png");
	platforms[1].Image = CP_Image_Load("./Assets/platform.png");
	platforms[2].Image = CP_Image_Load("./Assets/platform.png");
}

void spawn_platform(void)
{
	CP_Image_Draw(platforms[0].Image, platforms[0].Position.x, platforms[0].Position.y, platforms[0].Size.x, platforms[0].Size.y, 255);
	CP_Image_Draw(platforms[1].Image, platforms[1].Position.x, platforms[1].Position.y, platforms[0].Size.x, platforms[0].Size.y, 255);
	CP_Image_Draw(platforms[2].Image, platforms[2].Position.x, platforms[2].Position.y, platforms[0].Size.x, platforms[0].Size.y, 255);
}
