/*!
@file sceneManager.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code to manage the game scenes and switch
between pages
*//*______________________________________________________________*/
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
#include "credits.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)
CP_Image dead;
CP_Image cheeseCounterImage;
CP_Image logoImage = NULL;
CP_Sound clickSFX = NULL;
CP_Font font;
CP_Vector menuButtonPosition;
CP_Vector menuButton1Position;
float fadeOutTime;
float timeElapsed;

/*!
@brief Initialise the scenes
@param void
@return void
*//*______________________________________________________________*/
void sceneManager_init()
{
	logoImage = CP_Image_Load("./Assets/digipen_logo.png");
	font = CP_Font_Load("./Assets/Kalam-Light.ttf");
	door.SFX = CP_Sound_Load("./Assets/door.wav");
	clickSFX = CP_Sound_Load("./Assets/Button.wav");
	CP_Font_Set(font);
	menu_init();
	controls_init();
	background_init();
	credits_init();
	menu.page = 6;
	menuButtonPosition = CP_Vector_Set(600, 600);
	menuButton1Position = CP_Vector_Set(30, 30);
}

/*!
@brief Switch between pages with respect to the actions/conditions
@param void
@return void
*//*______________________________________________________________*/
void switchPage()
{
	//menu page
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
		collision_check_button5(button[8].Position);
		collision_check_button6(button[9].Position);
	}

	//gameplay page
	else if (menu.page == 1)
	{
		CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
		drawbackground();
		gameplay();
	}

	//control page
	else if (menu.page == 2)
	{
		drawbackgroundUI();
		drawControlButtons();
		collision_check_button3(button[2].Position);
	}

	//death page
	else if (menu.page == 3)
	{
		CP_Settings_TextSize(80.0f);
		CP_Settings_Fill(COLOR_WHITE);
		CP_Graphics_DrawRect(menuButton1Position.x, menuButton1Position.y, 350, 80);
		CP_Graphics_ClearBackground(COLOR_BLACK);
		CP_Settings_Fill(COLOR_BLACK);
		CP_Font_DrawText("Back to menu", 60, 90);
		collision_check_button4(menuButton1Position);

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

	//game over page
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

	//credits page
	else if (menu.page == 5)
	{
		drawbackgroundCreds();
		drawCredits();
		collision_check_button3(button[2].Position);
	}

	//starting logo screen
	else if (menu.page == 6)
	{
		fadeOutTime += 80 * timeElapsed;
		if (fadeOutTime < 255.0f)
		{
			CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
			CP_Image_Draw(logoImage, 1600 / 2.0f, 900 / 2.0f, 1525, 445, (int)fadeOutTime);
			CP_Settings_TextSize(30.0f);
			CP_Settings_Fill(COLOR_BLACK);
			CP_Font_DrawText("All content copyright 2021 DigiPen Institute of Technology Singapore. All Rights Reserved", 450, 890);
			if (CP_Input_MouseClicked())
			{
				fadeOutTime = 255;
			}
		}
		else
		{
			menu.page = 0;
		}
	}
}