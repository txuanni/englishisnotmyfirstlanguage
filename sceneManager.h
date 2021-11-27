struct sceneManager {
	
	int page;
	int level;
	CP_Sound ClickSFX;
	ClickSFX = CP_Sound_Load("./Assets/Button.wav");
}; struct sceneManager menu;




void sceneManager_init();
void switchPage();
