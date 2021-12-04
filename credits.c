/*!
@file credits.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code to display credits page
*//*______________________________________________________________*/
#include "cprocessing.h"
#include <stdio.h>
#include "sceneManager.h"
#include "collision.h"
#include "credits.h"
#include "controls.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)
CP_Image backgroundCredits = NULL;

/*!
@brief Initialise the back button in credits page
@param void
@return void
*//*______________________________________________________________*/
void credits_init()
{
	button->KeyButtonSize = CP_Vector_Set(70, 70);
}

/*!
@brief Render the background image
@param void
@return void
*//*______________________________________________________________*/
void drawbackgroundCreds()
{
	CP_Graphics_ClearBackground(COLOR_WHITE);
	backgroundCredits = CP_Image_Load("./Assets/backgroundui.png");
	CP_Image_Draw(backgroundCredits, 800, 450, 1610, 910, 170);
}

/*!
@brief Render the credits
@param void
@return void
*//*______________________________________________________________*/
void drawCredits()
{
	CP_Settings_Fill(COLOR_WHITE);
	CP_Graphics_DrawRect(button[2].Position.x, button[2].Position.y, button->Size.x, button->Size.y);

	CP_Settings_TextSize(80.0f);
	CP_Settings_Fill(COLOR_BLACK);
	CP_Font_DrawText("Back", button[2].TextPosition.x, button[2].TextPosition.y);

	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Credits", 700, 100);
	CP_Settings_TextSize(40.0f);
	CP_Font_DrawText("Created at", 730, 140);
	CP_Font_DrawText("DigiPen Institute of Technology Singapore ", 580, 165);
	CP_Font_DrawText("By EnglishIsNotMyFirstLanguage", 1000, 270);

	CP_Settings_TextSize(80.0f);
	CP_Font_DrawText("President", 100, 230);
	CP_Font_DrawText("Executives", 100, 350);
	CP_Font_DrawText("Drowning Mouse", 1000, 230);

	CP_Settings_TextSize(60.0f);
	CP_Font_DrawText("Claude Comair", 100, 280);
	//executives
	CP_Font_DrawText("Jason Chu", 100, 400);
	CP_Font_DrawText("Christopher Comair", 400, 400);
	CP_Font_DrawText("Michael Gats", 100, 450);
	CP_Font_DrawText("Michele Comair", 400, 450);
	CP_Font_DrawText("Raymond Yan", 100, 500);
	CP_Font_DrawText("Samir Abou Samra", 400, 500);
	CP_Font_DrawText("Prasanna Ghali", 100, 550);
	CP_Font_DrawText("John Bauer", 400, 550);
	CP_Font_DrawText("Erik Mohrmann", 100, 600);
	CP_Font_DrawText("Melvin Gonsalvez", 400, 600);
	CP_Font_DrawText("Angela Kugler", 100, 650);
	CP_Font_DrawText("Charles Duba", 400, 650);
	CP_Font_DrawText("Ben Ellinger", 100, 700);
	CP_Font_DrawText("Johnny Deek", 400, 700);
	//students
	CP_Font_DrawText("Teo Xuan Ni", 1000, 350);
	CP_Font_DrawText("David Tan Wei Jie", 1000, 400);
	CP_Font_DrawText("Qairul Shazriz Bin Shamsul", 1000, 450);
	
	//professors
	CP_Font_DrawText("Cheng Ding Xiang (Professor)", 1000, 650);
	CP_Font_DrawText("Gerald Wong (Professor)", 1000, 700);

	CP_Settings_TextSize(30.0f);
	CP_Font_DrawText("www.digipen.edu", 750, 870);
	CP_Font_DrawText("All content copyright 2021 DigiPen Institute of Technology Singapore. All Rights Reserved", 500, 890);
}