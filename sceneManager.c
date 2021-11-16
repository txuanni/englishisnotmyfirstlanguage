#include "sceneManager.h"

void sceneManger_init(struct sceneManager* game)
{
	game->backgroundPosition = CP_Vector_Set(800, 450);
	game->backgroundSize = CP_Vector_Set(1600, 900);
	game->backgroundImage = CP_Image_Load("./Assets/background.png");
}

void draw_background(struct sceneManager* game)
{
	CP_Image_Draw(game->backgroundImage, game->backgroundPosition.x, game->backgroundPosition.y, game->backgroundSize.x, game->backgroundSize.y, 255);
}