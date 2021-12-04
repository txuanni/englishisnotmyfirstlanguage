/*!
@file player.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
		David Tan Wei Jie (tan.d@digipen.edu)
		Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for player.c
*//*______________________________________________________________*/
#ifndef PLAYER_H
#define PLAYER_H


#include "cprocessing.h"

#define GRAVITY 9.8f
#define TERMINAL_VEL 400.0f
#define PLAYER_MOVE_SPEED 250.0f

typedef struct Player
{
	int isMovingLeft;
	int isMovingRight;
	int isJumping;
	int isGrounded;
	int canJump;
	int canMoveLeft;
	int canMoveRight;
	float jumpForce;
	int deathcount, cheesecount;
	int collidedWithCheese;
	int collidedWithObs;
	CP_Vector size;
	CP_Vector velocity;
	CP_Vector position;
	CP_Image idleGFX;
	CP_Image idle1GFX;
	CP_Image leftGFX;
	CP_Image left1GFX;
	CP_Image rightGFX;
	CP_Image right1GFX;
	CP_Sound jumpSFX;
	CP_Sound drownSFX;
	CP_Sound deathSFX;
}Player;

//This struct will hold all our player variables
Player gPlayer;

/*!
@brief Initialise the player
@param void
@return void
*//*______________________________________________________________*/
void player_init(void);

/*!
@brief This function contains code fror player's movement
@param float dt
@return void
*//*______________________________________________________________*/
void player_update(float dt);

/*!
@brief renders the player
@param float dt
@return void
*//*______________________________________________________________*/
void player_render(float dt);

/*!
@brief Respawns the player at a certain position and remove points
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void die(CP_Vector* playerpos);

/*!
@brief If player dies, respawn and set everything back to default
and load death screen
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void touch_water(CP_Vector *playerpos);

/*!
@brief If player touches the water, kill the player
@param CP_Vector playerpos
@return void
*//*______________________________________________________________*/
void respawn(CP_Vector* playerpos);
#endif // !PLAYER_H