#include "sceneManager.h"

void gamePage_init(struct sceneManager* game)
{
	game->backgroundPosition = CP_Vector_Set(800, 450);
	game->backgroundSize = CP_Vector_Set(1600, 900);
	game->backgroundImage = CP_Image_Load("./Assets/background.png");
}

void draw_background(struct sceneManager* game)
{
	CP_Image_Draw(game->backgroundImage, game->backgroundPosition.x, game->backgroundPosition.y, game->backgroundSize.x, game->backgroundSize.y, 255);
}

void startPage_init(struct sceneManager* startpage)
{
	startpage->backgroundPosition = CP_Vector_Set(800, 450);
	startpage->backgroundSize = CP_Vector_Set(1600, 900);
	startpage->backgroundImage = CP_Image_Load("./Assets/backgroundui.png");
}

void draw_backgroundUI(struct sceneManager* startpage)
{
	CP_Image_Draw(startpage->backgroundImage, startpage->backgroundPosition.x, startpage->backgroundPosition.y, startpage->backgroundSize.x, startpage->backgroundSize.y, 255);
}