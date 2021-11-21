#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"
#include "controls.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

void controls_init()
{
	button->KeyButtonSize = CP_Vector_Set(70, 70);

	button[2].Position = CP_Vector_Set(20, 20); //backbutton
	button[2].TextPosition = CP_Vector_Set(50, 70); //back text

	button[3].Position = CP_Vector_Set(300, 300); //W button
	button[3].TextPosition = CP_Vector_Set(320, 350); //W text

	button[4].Position = CP_Vector_Set(220, 380); //A button
	button[4].TextPosition = CP_Vector_Set(240, 430); //A text

	button[5].Position = CP_Vector_Set(300, 380); //S button
	button[5].TextPosition = CP_Vector_Set(320, 430); //S text

	button[6].Position = CP_Vector_Set(380, 380); //D button
	button[6].TextPosition = CP_Vector_Set(400, 430); //D text

	button[7].Position = CP_Vector_Set(150, 500); //space button
	button[7].TextPosition = CP_Vector_Set(270, 550); //space text
}

void drawControlButtons()
{
	CP_Settings_Fill(COLOR_WHITE);
	CP_Graphics_DrawRect(button[2].Position.x, button[2].Position.y, button->Size.x, button->Size.y);

	for (int i = 3; i < 7; i++)
	{
		CP_Graphics_DrawRect(button[i].Position.x, button[i].Position.y, button->KeyButtonSize.x, button->KeyButtonSize.y);
	}

	CP_Graphics_DrawRect(button[7].Position.x, button[7].Position.y, 400, button->KeyButtonSize.y);
	

	CP_Settings_Fill(COLOR_BLACK);
	CP_Font_DrawText("Back", button[2].TextPosition.x, button[2].TextPosition.y);
	CP_Font_DrawText("W", button[3].TextPosition.x, button[3].TextPosition.y);
	CP_Font_DrawText("A", button[4].TextPosition.x, button[4].TextPosition.y);
	CP_Font_DrawText("S", button[5].TextPosition.x, button[5].TextPosition.y);
	CP_Font_DrawText("D", button[6].TextPosition.x, button[6].TextPosition.y);
	CP_Font_DrawText("Move", 600, 430);

	CP_Font_DrawText("Spacebar", button[7].TextPosition.x, button[7].TextPosition.y);
	CP_Font_DrawText("Jump", 600, 550);
}