#include "cprocessing.h"

CP_Vector platformPosition;
CP_Vector platformSize;
CP_Vector platformBuffer;

CP_Vector platformPosition2;
CP_Vector platformPosition3;

CP_Image platformImage = NULL;


void platform_init(void)
{
	platformSize = CP_Vector_Set(1000, 100);
	platformBuffer = CP_Vector_Set(500, 50);
	platformPosition = CP_Vector_Set(400, 350);
	platformPosition2 = CP_Vector_Set(400, 700);
	platformPosition3 = CP_Vector_Set(800, 600);
	platformImage = CP_Image_Load("./Assets/platform.png");
}

void spawn_platform(void)
{
	CP_Image_Draw(platformImage, platformPosition.x, platformPosition.y, platformSize.x, platformSize.y, 255);
	CP_Image_Draw(platformImage, platformPosition2.x, platformPosition2.y, platformSize.x, platformSize.y, 255);
	CP_Image_Draw(platformImage, platformPosition3.x, platformPosition3.y, platformSize.x, platformSize.y, 255);
}
