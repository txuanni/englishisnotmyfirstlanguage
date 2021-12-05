/*---------------------------------------------------------
 * file:	traps.h
 * author:	Teo Xuan Ni
			* Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
			* qairulshazriz.b@digipen.edu
*
 * brief:	This file contains declarations for traps.c
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include "cprocessing.h"
/*!
@brief Initialise the trap position, size and buffer
@param void
@return void
*//*______________________________________________________________*/
void traps_init(void);

struct Traps
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
}; struct Traps trap[30];