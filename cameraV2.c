#include "cprocessing.h"
#include <stdio.h>
#include "player.h"


static const float SCALE = 1.5f;
static const float PAN = 100.0f;

CP_Vector currentPosition, playerBoxLeft, playerBoxRight;
float leftOffset, rightOffset, upOffset;
float moveLeft, moveRight, moveUp;
int screenWidth;

int outOfBoxLeft = 0;
int outOfBoxRight = 0;
int outOfBoxUp = 0;
//int outOfBoxDown = 0;

void camerav2_init(CP_Vector playerPosition)
{
	screenWidth = CP_System_GetWindowWidth();

	playerBoxLeft = CP_Vector_Set(50.0f, 600.0f);
	playerBoxRight = CP_Vector_Set(300.0f, 600.0f);

	currentPosition = CP_Vector_Set(playerPosition.x, playerPosition.y);

	leftOffset = playerPosition.x - 0;
	rightOffset = playerBoxRight.x - playerPosition.x;
	upOffset = playerBoxLeft.y - playerPosition.y;
	

}

void camerav2_update(CP_Vector playerPosition, float timeElapsed)
{
	if (playerPosition.x < playerBoxLeft.x)
	{
		outOfBoxLeft = 1;
		//Camera moves left
		moveLeft = playerPosition.x - leftOffset;
		printf("Move Left: %.2f\n", moveLeft);
		printf("Mouse pos: %.2f, %.2f\n", playerPosition.x, playerPosition.y);
		
	}

	else if (playerPosition.x > playerBoxRight.x)
	{
		outOfBoxRight = 1;
		//Camera moves right
		moveRight = playerPosition.x + rightOffset;
		printf("Move Right: %.2f\n", moveRight);
		printf("Mouse pos: %.2f, %.2f\n", playerPosition.x, playerPosition.y);


	}

	else if (playerPosition.y < playerBoxLeft.y)
	{
		outOfBoxUp = 1;
		//Camera moves up
		moveUp = playerPosition.y + upOffset;
		printf("Move Up: %.2f\n", moveUp);
		printf("Mouse pos: %.2f, %.2f\n", playerPosition.x, playerPosition.y);

	}
	//else if (playerPosition.y > playerBoxLeft.y)
	//{
	//	outOfBoxDown = 1;
	//	//Camera moves down
	//	moveDown = playerPosition.y - downOffset;
	//	printf("Move Down: %.2f\n", moveDown);
	//	printf("Mouse pos: %.2f, %.2f\n", playerPosition.x, playerPosition.y);
	//}

}