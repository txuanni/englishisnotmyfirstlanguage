#include "cprocessing.h"

CP_Vector platformPosition;
CP_Vector platformSize;
CP_Vector platformBuffer;
CP_Image platformImage = NULL;


void platform_init(void)
{
	platformPosition = CP_Vector_Set(500, 800);
	platformSize = CP_Vector_Set(1000, 100);
	platformBuffer = CP_Vector_Set(500, 50);
	platformImage = CP_Image_Load("./Assets/platform.png");
}

void spawn_platform(void)
{
	CP_Image_Draw(platformImage, platformPosition.x, platformPosition.y, platformSize.x, platformSize.y, 255);
}

