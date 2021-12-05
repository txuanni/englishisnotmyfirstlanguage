/*---------------------------------------------------------
 * file:	door.h
 * author:	Teo Xuan Ni
 * email:	t.xuanni@digipen.edu
*
 * brief:	This file contains declarations for door.c
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include "cprocessing.h"

/*!
@brief Initialise the door
@param void
@return void
*//*______________________________________________________________*/
void door_init(void);

/*!
@brief Render the door
@param void
@return void
*//*______________________________________________________________*/
void spawn_door(void);

struct Doors
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    CP_Sound SFX;
}; struct Doors door;