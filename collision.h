#include "player.h"

int CheckAABB_Collision(CP_Vector aPos, CP_Vector aSize, CP_Vector bPos, CP_Vector bSize);
void Collision_PlayerWithPlatform(CP_Vector platformPos, CP_Vector platformSize);

int is_btn_colliding(float mousepositionx, float mousepositiony, CP_Vector buttonPosition);
void collision_check_button(CP_Vector buttonPosition);
