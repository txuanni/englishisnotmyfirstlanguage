#include "cprocessing.h"
void traps_init(void);
void spawn_good_traps(void);
void spawn_bad_traps(void);

struct Traps
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}; struct Traps trap[30];