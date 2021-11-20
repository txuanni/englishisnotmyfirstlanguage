#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Image backgroundUIImage = NULL;
CP_Vector startButtonPosition;
CP_Vector controlButtonPosition;
CP_Vector buttonSize;


void menu_init()
{
	startButtonPosition = CP_Vector_Set(400, 270);
	controlButtonPosition = CP_Vector_Set(400, 400);
	buttonSize = CP_Vector_Set(150, 70);
	backgroundUIImage = CP_Image_Load("./Assets/backgroundui.png");
}

void drawbackgroundUI()
{
	CP_Image_Draw(backgroundUIImage, 800, 450, 1600, 900, 255);
}


void drawButtons()
{
	CP_Settings_Fill(COLOR_WHITE);
	CP_Graphics_DrawRect(startButtonPosition.x, startButtonPosition.y, buttonSize.x, buttonSize.y);
	CP_Graphics_DrawRect(controlButtonPosition.x, controlButtonPosition.y, buttonSize.x, buttonSize.y);
	CP_Settings_Fill(COLOR_BLACK);
	CP_Settings_TextSize(40.0f);
	CP_Font_DrawText("Start", 420, 320);
	CP_Font_DrawText("Controls", 410, 450);

	collision_check_button1(startButtonPosition);
	collision_check_button2(controlButtonPosition);
}