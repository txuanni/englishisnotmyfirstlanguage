#include "cprocessing.h"
#include <stdio.h>
#include "player.h"
#include "cheese.h"
#include "platform.h"
#include "terrain.h"
#include "traps.h"
#include "collision.h"
#include "cameraV2.h"
#include "sceneManager.h"
#include "menu.h"
#include "level1.h"

#define recommendedWidth 1600
#define recommendedHeight 900



static float timeElapsed;

void game_init(void)
{
	CP_System_SetWindowSize(recommendedWidth, recommendedHeight);
	CP_System_SetFrameRate(60.0f);
	sceneManager_init();

}
void game_update(void)
{
	timeElapsed = CP_System_GetDt();
	switchPage();
}
void game_exit(void)
{

}