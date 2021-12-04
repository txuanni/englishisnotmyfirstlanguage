/*!
@file platform.h
@author	Teo Xuan Ni (t.xuanni@digipen.edu)
        David Tan Wei Jie (tan.d@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for platform.c
*//*______________________________________________________________*/

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




