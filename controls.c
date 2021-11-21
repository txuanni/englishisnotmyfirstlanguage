#include "cprocessing.h"
#include "sceneManager.h"
#include "collision.h"

#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Vector backButtonPosition;
CP_Vector buttonSize;

void controls_init()
{
	backButtonPosition = CP_Vector_Set(400, 270);
	buttonSize = CP_Vector_Set(150, 70);
}