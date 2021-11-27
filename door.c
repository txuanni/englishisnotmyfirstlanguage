#include "door.h"

void door_init(void)
{
	door.Image = CP_Image_Load("./Assets/door.png");
	door.Size = CP_Vector_Set(120, 120);
	door.Buffer = CP_Vector_Set(60, 60);
	door.Position = CP_Vector_Set(9780, 680);
	door.SFX = CP_Sound_Load("./Assets/door.wav");
	
}

void spawn_door(void)
{
	CP_Image_Draw(door.Image, door.Position.x, door.Position.y, door.Size.x, door.Size.y, 255);
}
