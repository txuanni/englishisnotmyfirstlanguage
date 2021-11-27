#include "player.h"

int CheckAABB_Collision(CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector bSize);
void Collision_PlayerWithPlatform(CP_Vector platformPos, CP_Vector platformSize);
void Collision_PlayerWithTerrain(CP_Vector terrainPos, CP_Vector terrainSize);
void Collision_PlayerWithObstacle(CP_Vector Obspos, CP_Vector ObsSize);
void Collision_PlayerWithDoor(CP_Vector Doorpos, CP_Vector DoorSize);

int is_btn_colliding(float mousepositionx, float mousepositiony, CP_Vector buttonPosition);

void collision_check_button1(CP_Vector buttonPosition);
void collision_check_button2(CP_Vector buttonPosition);
void collision_check_button3(CP_Vector buttonPosition);
