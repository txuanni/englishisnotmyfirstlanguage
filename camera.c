#include "cprocessing.h"
#include <stdio.h>
#include "player.h"


static const float SCALE = 1.5f;
static const float PAN = 100.0f;

static float currentScale;
CP_Vector currentPosition, centerOffset, leftOffset, rightOffset;

static CP_Matrix scaleMatrix, translationMatrix;

CP_Image mouseCamera = NULL;

void camera_init(CP_Vector playerPosition)
{
	scaleMatrix = CP_Matrix_Identity();
	centerOffset = CP_Vector_Set(playerPosition.x, playerPosition.y);
	currentPosition = CP_Vector_Zero();
	translationMatrix = CP_Matrix_Translate(currentPosition);

	mouseCamera = CP_Image_Load("./Assets/idle.png");

}

void camera_update(CP_Vector playerPosition, CP_Vector playerSize,
	float timeElapsed)
{
	/*if (CP_Input_KeyDown(KEY_UP) || CP_Input_KeyDown(KEY_W))
	{
		currentPosition.y += timeElapsed * PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}
	

	else if (CP_Input_KeyDown(KEY_RIGHT) || CP_Input_KeyDown(KEY_D))
	{
		currentPosition.x += timeElapsed * -PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
	}

	else if (CP_Input_KeyDown(KEY_LEFT) || CP_Input_KeyDown(KEY_A))
	{
		currentPosition.x += timeElapsed * PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}
	else if (CP_Input_KeyDown(KEY_DOWN))
	{
		currentPosition.y += timeElapsed * -PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
	}*/

	currentPosition.x = -(playerPosition.x + (playerSize.x / 2) - CP_System_GetWindowWidth() / 2.0f);
	translationMatrix = CP_Matrix_Translate(currentPosition);

	CP_Vector offsetOrigin = CP_Vector_Scale(currentPosition, -1.0f);
	CP_Vector offsetVector = CP_Vector_Add(offsetOrigin, centerOffset);
	CP_Matrix offsetMatrix = CP_Matrix_Translate(CP_Vector_Scale(offsetVector, -1.0f));

	//Translates all objects by the world space position to the curren screen center
	CP_Matrix offsetUndoMatrix = CP_Matrix_Translate(offsetVector);
	//now all objects are within the center screen local coordinate system

	//Applying the scale
	CP_Matrix transform = CP_Matrix_Multiply(scaleMatrix, offsetMatrix);

	//Return all objects to the world space
	transform = CP_Matrix_Multiply(offsetUndoMatrix, transform);

	//Translate objects in world space based on the current camera panning
	transform = CP_Matrix_Multiply(translationMatrix, transform);

	CP_Settings_ApplyMatrix(transform);


}