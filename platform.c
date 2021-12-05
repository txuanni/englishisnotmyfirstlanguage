/*---------------------------------------------------------
 * file:	platform.c
 * author:	Teo Xuan Ni
			* Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
			* qairulshazriz.b@digipen.edu
*
 * brief:	This file contains code for the position, size 
			* and buffer of platform
			* Xuan Ni - Did the base code for this file
			* Qairul - Finalised the position for
			* initialisation of platforms
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include "cprocessing.h"
#include "platform.h"
#include <stdio.h>

/*!
@brief Initialise the platform positions
@param void
@return void
*//*______________________________________________________________*/
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

/*!
@brief Renders the platform
@param void
@return void
*//*______________________________________________________________*/
void spawn_platform(void)
{
	for (int i = 0; i < 5; i++)
	{
		CP_Image_Draw(platforms->Image, platforms[i].Position.x, platforms[i].Position.y, platforms->Size.x, platforms->Size.y, 255);
	}
}
