#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"
#include "controls.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Image backgroundUIImage = NULL;
CP_Vector startButtonPosition;



void menu_init()
{	

	backgroundUIImage = CP_Image_Load("./Assets/backgroundui.png");

	button->Size = CP_Vector_Set(200, 70);
	button->Buffer = CP_Vector_Set(100, 35);
	
	button[0].Position = CP_Vector_Set(370, 250); //start button
	button[0].TextPosition = CP_Vector_Set(400, 300); //start text

	button[1].Position = CP_Vector_Set(370, 400); //controls button
	button[1].TextPosition = CP_Vector_Set(400, 450); //controls text
	
}

void drawbackgroundUI()
{
	CP_Image_Draw(backgroundUIImage, 800, 450, 1600, 900, 255); 
}


void drawButtons()
{
	CP_Settings_Fill(COLOR_WHITE);

	CP_Graphics_DrawRect(button[0].Position.x, button[0].Position.y, button->Size.x, button->Size.y);
	CP_Graphics_DrawRect(button[1].Position.x, button[1].Position.y, button->Size.x, button->Size.y);

	CP_Settings_Fill(COLOR_BLACK);
	CP_Settings_TextSize(40.0f);
	CP_Font_DrawText("Start", button[0].TextPosition.x, button[0].TextPosition.y);
	CP_Font_DrawText("Controls", button[1].TextPosition.x, button[1].TextPosition.y);
}