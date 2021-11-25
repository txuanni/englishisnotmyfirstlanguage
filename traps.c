#include "traps.h"

void traps_init(void)
{
	trap->Image = CP_Image_Load("./Assets/traps.png");
	trap->Size = CP_Vector_Set(70, 70);
	trap->Buffer = CP_Vector_Set(35, 35);

	trap[0].Position = CP_Vector_Set(750, 700);
	trap[1].Position = CP_Vector_Set(1950, 260);
	trap[2].Position = CP_Vector_Set(2250, 260);
	trap[3].Position = CP_Vector_Set(3550, 700);
	trap[4].Position = CP_Vector_Set(3700, 580);
	trap[5].Position = CP_Vector_Set(4100, 380);
	trap[6].Position = CP_Vector_Set(5900, 700);
	trap[7].Position = CP_Vector_Set(6450, 700);
	trap[8].Position = CP_Vector_Set(7000, 480);
	trap[9].Position = CP_Vector_Set(7336, 480);
	trap[10].Position = CP_Vector_Set(8086, 580);
	trap[11].Position = CP_Vector_Set(8900, 450);
	trap[12].Position = CP_Vector_Set(9100, 680);
	trap[13].Position = CP_Vector_Set(9500, 700);
	trap[14].Position = CP_Vector_Set(5100, 480);
	trap[15].Position = CP_Vector_Set(5500, 480);

}

void spawn_good_traps(void)
{
	CP_Image_Draw(trap->Image, trap[3].Position.x, trap[3].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[4].Position.x, trap[4].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[5].Position.x, trap[5].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[6].Position.x, trap[6].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[7].Position.x, trap[7].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[8].Position.x, trap[8].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[10].Position.x, trap[10].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[11].Position.x, trap[11].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[12].Position.x, trap[12].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[14].Position.x, trap[14].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[15].Position.x, trap[15].Position.y, trap->Size.x, trap->Size.y, 255);


}

void spawn_bad_traps(void)
{
	CP_Image_Draw(trap->Image, trap[0].Position.x, trap[0].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[1].Position.x, trap[1].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[2].Position.x, trap[2].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[9].Position.x, trap[9].Position.y, trap->Size.x, trap->Size.y, 255);
	CP_Image_Draw(trap->Image, trap[13].Position.x, trap[13].Position.y, trap->Size.x, trap->Size.y, 255);

}

