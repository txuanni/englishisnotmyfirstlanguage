/*!
@file door.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for door.c
*//*______________________________________________________________*/
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