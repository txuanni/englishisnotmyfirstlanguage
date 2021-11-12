#include "cprocessing.h"

CP_Vector trapsPosition;
CP_Vector trapsSize;
CP_Vector trapsBuffer;
CP_Image trapsImage = NULL;

void traps_init(void)
{
	trapsPosition = CP_Vector_Set(900, 600);
	trapsSize = CP_Vector_Set(110, 60);
	trapsBuffer = CP_Vector_Set(55, 30);
	trapsImage = CP_Image_Load("./Assets/traps.png");
}

void spawn_traps(void)
{
	CP_Image_Draw(trapsImage, trapsPosition.x, trapsPosition.y, trapsSize.x, trapsSize.y, 255);
	CP_Image_Draw(trapsImage, trapsPosition.x, trapsPosition.y, trapsSize.x, trapsSize.y, 255);
}

