/*---------------------------------------------------------
 * file:	platform.h
 * author:	Teo Xuan Ni
			* Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
			* qairulshazriz.b@digipen.edu
*
 * brief:	This file contains declarations for platform.c
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/

/*!
@brief Initialise the platform positions
@param void
@return void
*//*______________________________________________________________*/
void platform_init(void);

/*!
@brief Renders the platform
@param void
@return void
*//*______________________________________________________________*/
void spawn_platform(void);


struct Platform
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}; struct Platform platforms[30];




