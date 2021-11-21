#include "sceneManager.h"
#include "menu.h"
#include "collision.h"
#include "level1.h"
#include "controls.h"

#include <stdio.h>

CP_Vector buttonPosition;

void sceneManager_init()
{
	menu_init();
	controls_init();
	menu.page = 0;
}

void switchPage()
{
	if (menu.page == 0)
	{
		drawbackgroundUI();
		drawButtons();
		collision_check_button1(buttonPosition);
	}
	else if (menu.page == 1)
	{
		drawbackground();
		gameplay();
	}

	else if (menu.page == 2)
	{
		drawbackgroundUI();
	}
}