/*---------------------------------------------------------
 * file:	camera.h
 * author:	Qairul Shazriz Bin Shamsul
 * email:	qairulshazriz.b@digipen.edu
*
 * brief:	This file contains code declarations for 
			* camera.c
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
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
