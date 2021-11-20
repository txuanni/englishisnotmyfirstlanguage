#pragma once
void camera_init(CP_Vector playerPosition);
void camera_update(CP_Vector playerPosition, CP_Vector playerGravity,
	CP_Vector playerVelocity, float timeElapsed);
