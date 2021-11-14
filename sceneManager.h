#include "cprocessing.h"
struct sceneManager {
	CP_Vector backgroundPosition;
	CP_Vector backgroundSize;
	CP_Image backgroundImage;
};

void gamePage_init(struct sceneManager* game);
void startPage_init(struct sceneManager* startpage);
void draw_background(struct sceneManager* game);
void draw_backgroundUI(struct sceneManager* startpage);