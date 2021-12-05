﻿/*---------------------------------------------------------
 * file:	door.c
 * author:	Teo Xuan Ni
 * email:	t.xuanni@digipen.edu
*
 * brief:	This file contains code to draw the door
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include "door.h"

/*!
@brief Initialise the door
@param void
@return void
*//*______________________________________________________________*/
void door_init(void)
{
	door.Image = CP_Image_Load("./Assets/door.png");
	door.Size = CP_Vector_Set(120, 120);
	door.Buffer = CP_Vector_Set(60, 60);
	door.Position = CP_Vector_Set(9780, 680);
}

/*!
@brief Render the door
@param void
@return void
*//*______________________________________________________________*/
void spawn_door(void)
{
	CP_Image_Draw(door.Image, door.Position.x, door.Position.y, door.Size.x, door.Size.y, 255);
}
