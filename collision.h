#include "player.h"

int CheckAABB_Collision(CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector bSize);
void Collision_PlayerWithPlatform(CP_Vector platformPos, CP_Vector platformSize);

//LegacyCode
//int is_colliding(CP_Vector player, CP_Vector object, CP_Vector buffer);
//void collision_check_platform(CP_Vector player, CP_Vector platform, CP_Vector platformbuffer);
//void collision_check_cheese(CP_Vector player, CP_Vector cheese, CP_Vector cheesebuffer);
//void collision_check_terrain(CP_Vector player, CP_Vector terrain, CP_Vector terrainbuffer);