#include <stdio.h>
#include "sceneManager.h"
#include "menu.h"
#include "collision.h"
#include "level1.h"
#include "controls.h"
#include "door.h"
#include "cheese.h"
#include "traps.h"
#include "terrain.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 200)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)
CP_Image dead;
CP_Image cheeseCounterImage;
CP_Sound clickSFX = NULL;
CP_Font font;
CP_Vector menuButtonPosition;

void sceneManager_init()
{
	font = CP_Font_Load("./Assets/Kalam-Light.ttf");
	door.SFX = CP_Sound_Load("./Assets/door.wav");
	clickSFX = CP_Sound_Load("./Assets/Button.wav");
	CP_Font_Set(font);
	menu_init();
	controls_init();
	background_init();
	menu.page = 0;
	menuButtonPosition = CP_Vector_Set(600, 600);
}

void switchPage()
{
	if (menu.page == 0)
	{
		respawn(&gPlayer.position);

		for (int i = 0; i < 26; i++)
		{
			cheese[i].isActive = 1;
		}
		for (int i = 0; i < 16; i++)
		{
			trap[i].isActive = 1;
		}
		for (int i = 24; i < 27; i++)
		{
			terrain[i].isActive = 1;
		}
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
		CP_Settings_TextSize(80.0f);
		CP_Graphics_ClearBackground(COLOR_BLACK);
		CP_Settings_Fill(COLOR_WHITE);

		//Death Counter
		CP_Image_Draw(dead, 450, 450, 200, 130, 255);
		char buffer[100];
		sprintf_s(buffer, 100, "x %.0d", gPlayer.deathcount);
		CP_Font_DrawText(buffer, 550, 450);

		CP_Font_DrawText("Press SPACE to continue", 850, 450);
		if (CP_Input_KeyDown(KEY_SPACE))
		{
			menu.page = 1;
		}
	}

	else if (menu.page == 4)
	{
		CP_Settings_TextSize(80.0f);
		CP_Graphics_ClearBackground(COLOR_BLACK);
		CP_Settings_Fill(COLOR_WHITE);
		CP_Font_DrawText("Congratulations! Thank you for playing :D", 350, 450);

		//Death Counter
		CP_Image_Draw(dead, 450, 320, 170, 120, 255);
		char buffer[100];
		sprintf_s(buffer, 100, "x %.0d", gPlayer.deathcount);
		CP_Font_DrawText(buffer, 550, 320);

		//Cheese Counter
		CP_Image_Draw(cheeseCounterImage, 950, 300, 130, 110, 255);
		sprintf_s(buffer, 100, "x %.0d", cheese->Counter);
		CP_Font_DrawText(buffer, 1050, 320);

		CP_Settings_Fill(COLOR_WHITE);
		CP_Graphics_DrawRect(menuButtonPosition.x, menuButtonPosition.y, 350, 80);
		CP_Settings_Fill(COLOR_BLACK);
		CP_Font_DrawText("Back to menu", 630, 660);
		collision_check_button4(menuButtonPosition);
	}
}