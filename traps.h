/*!
@file traps.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for traps.c
*//*______________________________________________________________*/
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