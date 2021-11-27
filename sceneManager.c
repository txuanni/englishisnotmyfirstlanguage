#include "sceneManager.h"
#include "menu.h"
#include "collision.h"
#include "level1.h"
#include "controls.h"
#include <stdio.h>

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)
CP_Font font;
CP_Vector buttonPosition;

void sceneManager_init()
{
	font = CP_Font_Load("./Assets/Kalam-Light.ttf");
	CP_Font_Set(font);
	menu_init();
	controls_init();
	background_init();
	menu.page = 0;
}

void switchPage()
{
	if (menu.page == 0)
	{
		drawbackgroundUI();
		drawButtons();
		collision_check_button1(button[0].Position);
		collision_check_button2(button[1].Position);
	}
	else if (menu.page == 1)
	{
		drawbackground();
		gameplay();
	}

	else if (menu.page == 2)
	{
		drawbackgroundUI();
		drawControlButtons();
		collision_check_button3(button[2].Position);
	}
	else if (menu.page == 3)
	{
		CP_Graphics_ClearBackground(COLOR_BLACK);
		CP_Settings_Fill(COLOR_WHITE);
		CP_Font_DrawText("Press SPACE to continue", 800, 450);
		if (CP_Input_KeyDown(KEY_SPACE))
		{
			menu.page = 1;
		}

	}
}