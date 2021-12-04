/*!
@file collision.c
@author David Tan Wei Jie (tan.d@digipen.edu)
        Teo Xuan Ni (t.xuanni@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for collision.c
*//*______________________________________________________________*/
#include "player.h"

/*!
@brief Check the collision using AABB
@param CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector
bSize
@return int
*//*______________________________________________________________*/
int CheckAABB_Collision(CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector bSize);

/*!
@brief Check the player collision with platform
@param CP_Vector platformPos, CP Vector platformSize
@return void
*//*______________________________________________________________*/
void Collision_PlayerWithPlatform(CP_Vector platformPos, CP_Vector platformSize);

/*!
@brief Check the player collision with terrain
@param CP_Vector terrainPos, CP Vector terrainSize
@return void
*//*______________________________________________________________*/
void Collision_PlayerWithTerrain(CP_Vector terrainPos, CP_Vector terrainSize);

/*!
@brief Check the player collision with input Obstacles
@param CP_Vector Obpos, CP Vector ObsSize
@return void
*//*______________________________________________________________*/
void Collision_PlayerWithObstacle(CP_Vector Obspos, CP_Vector ObsSize);

/*!
@brief Check the player collision with door
@param CP_Vector Doorpos, CP Vector DoorSize
@return void
*//*______________________________________________________________*/
void Collision_PlayerWithDoor(CP_Vector Doorpos, CP_Vector DoorSize);


/*!
@brief Check collision with a button
@param float mousepositionx, float mousepositiony, CP_Vector
buttonPosition
@return int
*//*______________________________________________________________*/
int is_btn_colliding(float mousepositionx, float mousepositiony, CP_Vector buttonPosition);

/*!
@brief Check collision with start button
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button1(CP_Vector buttonPosition);

/*!
@brief Check collision with control button
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button2(CP_Vector buttonPosition);

/*!
@brief Check collision with back button
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button3(CP_Vector buttonPosition);

/*!
@brief Check collision with back button in game over
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button4(CP_Vector buttonPosition);

/*!
@brief Check collision with back button in credits
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button5(CP_Vector buttonPosition);

/*!
@brief Check collision with exit button in main menu
@param CP_Vector buttonPosition
@return void
*//*______________________________________________________________*/
void collision_check_button6(CP_Vector buttonPosition);
