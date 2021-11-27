#include "cprocessing.h"
void door_init(void);
void spawn_door(void);

struct Doors
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    CP_Sound SFX;
    door.SFX = CP_Sound_Load("./Assets/door.wav");
}; struct Doors door;