void mouse_init(void);
void spawn_mouse(void);
int is_colliding(float x, float y, float objectX, float objectY, float widthX, float widthY);

void collision_check_platform(float playerx, float playery, float platformx, float platformy, float platformwidthx, float platformwidthy);
void collision_check_cheese(float playerx, float playery, float cheesex, float cheesey, float cheesewidth, float cheeseheight);
	
void mouse_movement();