#include "cheese.h"

void cheese_init(void)
{
    cheese->Image = CP_Image_Load("./Assets/cheese.png");
    cheese->Size = CP_Vector_Set(70, 70);
    cheese->Buffer = CP_Vector_Set(35, 35);
    
    cheese[0].Position = CP_Vector_Set(400, 400);
}

void spawn_cheese(void)
{
    CP_Image_Draw(cheese->Image, cheese[0].Position.x, cheese[0].Position.y, cheese->Size.x, cheese->Size.y, 255);
}