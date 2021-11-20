#include "cprocessing.h"
struct sceneManager {
	CP_Vector backgroundPosition;
	CP_Vector backgroundSize;
	CP_Image backgroundImage;
};
struct sceneManager scene;

void sceneManger_init(struct sceneManager* game);
void draw_background(struct sceneManager* game);