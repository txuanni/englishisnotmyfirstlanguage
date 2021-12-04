/*!
@file cheese.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations of cheese.c
*//*______________________________________________________________*/

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
