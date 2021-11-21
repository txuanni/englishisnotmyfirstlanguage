
#include "cheese.h"

void cheese_init()
{
    cheeses[0].Position = CP_Vector_Set(400, 500);
    cheeses[0].Size = CP_Vector_Set(70, 70);
    cheeses[0].Buffer = CP_Vector_Set(35, 35);
    cheeses[0].Image = CP_Image_Load("./Assets/cheese.png");
}

void spawn_cheese()
{
    CP_Image_Draw(cheeses[0].Image, cheeses[0].Position.x, cheeses[0].Position.y, cheeses[0].Size.x, cheeses[0].Size.y, 255);
}