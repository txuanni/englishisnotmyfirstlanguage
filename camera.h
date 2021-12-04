/*!
@file camera.h
@author Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file declaration code for camera.c
*//*______________________________________________________________*/
#pragma once
/*!
@brief Initialise the camera
@param CP_Vector playerPosition
@return void
*//*______________________________________________________________*/
void camera_init(CP_Vector playerPosition);
/*!
@brief Updates the camera to follow the player
@param CP_Vector playerPosition, CP_Vector playerSize
@return void
*//*______________________________________________________________*/
void camera_update(CP_Vector playerPosition, CP_Vector playerSize, float timeElapsed);
