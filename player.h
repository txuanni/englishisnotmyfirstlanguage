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
	int deathcount;
	CP_Vector size;
	CP_Vector velocity;
	CP_Vector position;
	CP_Image idleGFX;
	CP_Image idle1GFX;
	CP_Image leftGFX;
	CP_Image left1GFX;
	CP_Image rightGFX;
	CP_Image right1GFX;
	CP_Image deathGFX;
}Player;

//This struct will hold all our player variables
Player gPlayer;

//Initialise the player
void player_init(void);

//Update the player
void player_update(float dt);

//Render the player
void player_render(float dt);

void die(CP_Vector* playerpos);

void touch_water(CP_Vector *playerpos);
#endif // !PLAYER_H