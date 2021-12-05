/*---------------------------------------------------------
 * file:	game.c
 * author:	Teo Xuan Ni
            * David Tan Wei Jie
            * Qairul Shazriz Bin Shamsul
 * email:	t.xuanni@digipen.edu
            * tan.d@digipen.edu
            * qairulshazriz.b@digipen.edu
*
 * brief:	This file contains code to run the game from 
			* start to end
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "collision.h"
#include "camera.h"
#include "sceneManager.h"
#include "menu.h"
#include "level1.h"

#define recommendedWidth 1600
#define recommendedHeight 900

float timeElapsed;

/*!
@brief Initialise the game
@param void
@return void
*//*______________________________________________________________*/
void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	CP_System_SetFrameRate(60.0f);
	sceneManager_init();
}

/*!
@brief Updates the game
@param void
@return void
*//*______________________________________________________________*/
void game_update(void)
{
	timeElapsed = CP_System_GetDt();
	switchPage();
}

/*!
@brief Exit the game
@param void
@return void
*//*______________________________________________________________*/
void game_exit(void)
{

}