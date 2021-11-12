#include "cprocessing.h"
#include <stdio.h>
#include "player.h"

#define mouse_size 90

static const float SCALE = 3.0f;
static const float PAN = 100.0f;

static float currentScale;

static CP_Vector currentPosition, centerOffset;

static CP_Matrix scaleMatrix, translationMatrix;

CP_Image mouseCamera = NULL;

void camera_init(void)
{
	scaleMatrix = CP_Matrix_Identity();
	currentScale = 1.0f;

	float centerX = CP_System_GetWindowWidth() / 2.0f;
	float centerY = CP_System_GetWindowHeight() / 2.0f;
	centerOffset = CP_Vector_Set(centerX, centerY);
	currentPosition = CP_Vector_Zero();
	translationMatrix = CP_Matrix_Translate(currentPosition);

	mouseCamera = CP_Image_Load("./Assets/idle.png");

}

void camera_update(void)
{
	float dt = CP_System_GetDt();

	if (CP_Input_KeyDown(KEY_UP) || CP_Input_KeyDown(KEY_W))
	{
		currentPosition.y += dt * PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}

	else if (CP_Input_KeyDown(KEY_RIGHT) || CP_Input_KeyDown(KEY_D))
	{
		currentPosition.x += dt * -PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}

	else if (CP_Input_KeyDown(KEY_LEFT) || CP_Input_KeyDown(KEY_A))
	{
		currentPosition.x += dt * PAN;
		translationMatrix = CP_Matrix_Translate(currentPosition);
		printf("Current Pos: %f %f\n", currentPosition.x, currentPosition.y);
	}

	CP_Vector offsetOrigin = CP_Vector_Scale(currentPosition, -1.0f);
	CP_Vector offsetVector = CP_Vector_Add(offsetOrigin, centerOffset);
	CP_Matrix offsetMatrix = CP_Matrix_Translate(CP_Vector_Scale(offsetVector, -1.0f));

	//Translates all objects by the world space position fo the curren screen center
	CP_Matrix offsetUndoMatrix = CP_Matrix_Translate(offsetVector);
	//now all objects are within the center screen local coordinate system

	//Applying the scale
	CP_Matrix transform = CP_Matrix_Multiply(scaleMatrix, offsetMatrix);

	//Return all objects to the world space
	transform = CP_Matrix_Multiply(offsetUndoMatrix, transform);

	//Translate objects in world space based on the current camera panning
	transform = CP_Matrix_Multiply(translationMatrix, transform);

	CP_Settings_ApplyMatrix(transform);

	//Draw the mouse here
	//CP_Image_Draw(mouseCamera, offsetVector.x, offsetVector.y, mouse_size, mouse_size, 255);
}
