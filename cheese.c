#include "cprocessing.h"

CP_Image cheeseImage = NULL;
CP_Vector cheesePosition;
CP_Vector cheeseSize;
CP_Vector cheeseBuffer;

void cheese_init()
{
	cheesePosition = CP_Vector_Set(400, 500);
	cheeseSize = CP_Vector_Set(70, 70);
	cheeseBuffer = CP_Vector_Set(35, 35);
	cheeseImage = CP_Image_Load("./Assets/cheese.png");
}

void spawn_cheese()
{
	CP_Image_Draw(cheeseImage, cheesePosition.x, cheesePosition.y, cheeseSize.x, cheeseSize.y, 255);
}

int is_cheese_colliding()
{
	return 0;
}