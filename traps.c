/*!
@file traps.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
		Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code for traps position, size and buffer
*//*______________________________________________________________*/
#include "traps.h"

/*!
@brief Initialise the trap position, size and buffer
@param void
@return void
*//*______________________________________________________________*/
void traps_init(void)
{
	trap->Image = CP_Image_Load("./Assets/traps.png");
	trap->Size = CP_Vector_Set(70, 70);
	trap->Buffer = CP_Vector_Set(25, 25);
	for (int i = 0; i < 15; i++)
	{
		trap[i].isActive = 1;
	}

	//good traps pos
	trap[0].Position = CP_Vector_Set(3550, 700);
	trap[1].Position = CP_Vector_Set(3700, 580);
	trap[2].Position = CP_Vector_Set(4100, 380);
	trap[3].Position = CP_Vector_Set(5900, 700);
	trap[4].Position = CP_Vector_Set(6450, 700);
	trap[5].Position = CP_Vector_Set(7000, 480);
	trap[6].Position = CP_Vector_Set(8086, 580);
	trap[7].Position = CP_Vector_Set(8900, 450);
	trap[8].Position = CP_Vector_Set(9100, 680);
	trap[9].Position = CP_Vector_Set(5100, 480);
	trap[10].Position = CP_Vector_Set(5500, 480);

	//bad traps pos
	trap[11].Position = CP_Vector_Set(750, 700);
	trap[12].Position = CP_Vector_Set(1950, 260);
	trap[13].Position = CP_Vector_Set(2250, 260);
	trap[14].Position = CP_Vector_Set(7336, 480);
	trap[15].Position = CP_Vector_Set(9500, 700);

}
