/*---------------------------------------------------------
 * file:	cheese.h
 * author:	Teo Xuan Ni
            * Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
            * qairulshazriz.b@digipen.edu
*
 * brief:	This file contains declarations for cheese.c
* 
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/

#include "cprocessing.h"
/*!
@brief Initialise the cheese positions
@param void
@return void
*//*______________________________________________________________*/
void cheese_init(void);

struct Cheeses
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
    int Counter;
}; struct Cheeses cheese[30];
