#include "cprocessing.h"
void cheese_init(void);


struct Cheeses
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
    int Counter;
}; struct Cheeses cheese[30];
