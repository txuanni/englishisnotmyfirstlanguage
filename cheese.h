#include "cprocessing.h"
void cheese_init(void);
void spawn_cheese(void);


struct Cheeses
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}; struct Cheeses cheese[30];
