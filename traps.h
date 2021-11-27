#include "cprocessing.h"
void traps_init(void);

struct Traps
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
    int isActive;
}; struct Traps trap[30];