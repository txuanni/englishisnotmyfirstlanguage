#ifndef PLAYER_H
#define PLAYER_H


#include "cprocessing.h"

#define GRAVITY 9.8f
#define TERMINAL_VEL 400.0f
#define PLAYER_MOVE_SPEED 200.0f

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
	CP_Vector size;
	CP_Vector velocity;
	CP_Vector position;
	CP_Image idleGFX;
}Player;

//This struct will hold all our player variables
Player gPlayer;

//Initialise the player
void player_init(void);

//Update the player
void player_update(float dt);

//Render the player
void player_render(void);

//==========legacy code==============//
//void mouse_init(void);
//
//void spawn_mouse(void);
//	
//void mouse_movement(float dt);


#endif // !PLAYER_H