/*!
@file sceneManager.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for sceneManager.c
*//*______________________________________________________________*/
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
