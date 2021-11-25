#include "cprocessing.h"
void cheese_init(void);
void spawn_good_cheese(void);
void spawn_bad_cheese(void);


struct Cheeses
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
    int Counter;
}; struct Cheeses cheese[30];
