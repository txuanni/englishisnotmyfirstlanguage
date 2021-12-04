/*!
@file terrain.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for terrain.c
and size
*//*______________________________________________________________*/
#include "cprocessing.h"
/*!
@brief Initialise the terrain position, size and buffer
@param void
@return void
*//*______________________________________________________________*/
void terrain_init(void);

struct Terrain
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
}; struct Terrain terrain[30];