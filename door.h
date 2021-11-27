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
}; struct Doors door;