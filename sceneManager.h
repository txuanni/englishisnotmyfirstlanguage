/*---------------------------------------------------------
 * file:	sceneManager.h
 * author:	Teo Xuan Ni
 * email:	t.xuanni@digipen.edu
*
 * brief:	This file contains declarations for 
			* sceneManager.c
*
 * documentation link:
 * https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
*
 * Copyright � 2021 DigiPen, All rights reserved.
* ---------------------------------------------------------*/
struct SceneManager
{
	int page;
	int level;
};  struct SceneManager menu;

/*!
@brief Initialise the scenes
@param void
@return void
*//*______________________________________________________________*/
void sceneManager_init();

/*!
@brief Switch between pages with respect to the actions/conditions
@param void
@return void
*//*______________________________________________________________*/
void switchPage();
