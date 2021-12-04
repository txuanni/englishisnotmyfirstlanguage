/*!
@file menu.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code to check for collisions
*//*______________________________________________________________*/
#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"
#include "controls.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Image backgroundUIImage = NULL;
CP_Vector startButtonPosition;

/*!
@brief Initialise the buttons for menu page
@param void
@return void
*//*______________________________________________________________*/
void menu_init()
{	
	backgroundUIImage = CP_Image_Load("./Assets/backgroundui.png");

	button->Size = CP_Vector_Set(250, 70);
	button->Buffer = CP_Vector_Set(125, 35);
	
	button[0].Position = CP_Vector_Set(320, 300); //start button
	button[0].TextPosition = CP_Vector_Set(350, 350); //start text

	button[1].Position = CP_Vector_Set(320, 450); //controls button
	button[1].TextPosition = CP_Vector_Set(350, 500); //controls text

	button[8].Position = CP_Vector_Set(320, 600); //credits button
	button[8].TextPosition = CP_Vector_Set(350, 650); //credits text
}

/*!
@brief Render the background
@param void
@return void
*//*______________________________________________________________*/
void drawbackgroundUI()
{
	CP_Graphics_ClearBackground(COLOR_WHITE);
	CP_Image_Draw(backgroundUIImage, 800, 450, 1610, 910, 255); 
}

/*!
@brief Renders the buttons and text for menu page
@param void
@return void
*//*______________________________________________________________*/
void drawButtons()
{
	CP_Settings_Fill(COLOR_WHITE);

	CP_Graphics_DrawRect(button[0].Position.x, button[0].Position.y, button->Size.x, button->Size.y);
	CP_Graphics_DrawRect(button[1].Position.x, button[1].Position.y, button->Size.x, button->Size.y);
	CP_Graphics_DrawRect(button[8].Position.x, button[8].Position.y, button->Size.x, button->Size.y);

	CP_Settings_Fill(COLOR_BLACK);
	CP_Settings_TextSize(80.0f);
	CP_Font_DrawText("Start", button[0].TextPosition.x, button[0].TextPosition.y);
	CP_Font_DrawText("Controls", button[1].TextPosition.x, button[1].TextPosition.y);
	CP_Font_DrawText("Credits", button[8].TextPosition.x, button[8].TextPosition.y);
}