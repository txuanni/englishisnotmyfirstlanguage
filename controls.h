#include "cprocessing.h"
void controls_init();
void drawControlButtons();

struct Buttons
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Vector TextPosition;
    CP_Vector TextSize;
    CP_Vector KeyButtonSize;
}; struct Buttons button[8];