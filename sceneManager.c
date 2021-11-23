#include "sceneManager.h"
#include "menu.h"
#include "collision.h"
#include "level1.h"
#include "controls.h"

#include <stdio.h>
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
}