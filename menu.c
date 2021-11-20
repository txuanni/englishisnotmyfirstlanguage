#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Image backgroundUIImage = NULL;
CP_Vector buttonPosition;
CP_Vector buttonSize;


void menu_init()
{
	buttonPosition = CP_Vector_Set(300, 270);
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
	CP_Graphics_DrawRect(buttonPosition.x, buttonPosition.y, buttonSize.x, buttonSize.y);
	CP_Settings_Fill(COLOR_BLACK);
	CP_Settings_TextSize(40.0f);
	CP_Font_DrawText("Start", 305, 320);

	collision_check_button(buttonPosition);
}