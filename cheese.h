#include "cprocessing.h"
void cheese_init();
void spawn_cheese();


typedef struct Cheese
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Image Image;
}Cheese;

Cheese cheeses[30];