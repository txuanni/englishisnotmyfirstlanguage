#include "sceneManager.h"
#include "menu.h"
#include "collision.h"
#include "level1.h"

#include <stdio.h>

CP_Vector buttonPosition;

void sceneManager_init()
{
	menu.page = 0;
}

void switchPage()
{
	if (menu.page == 0)
	{
		drawbackgroundUI();
		drawButtons();
		collision_check_button(buttonPosition);
	}
	else if (menu.page == 1)
	{
		printf("game1");
		drawbackground();
		gameplay();
	}
}