#include "cheese.h"
#include "player.h"

void cheese_init(void)
{
    cheese->Image = CP_Image_Load("./Assets/cheese.png");
    cheese->Size = CP_Vector_Set(70, 70);
    cheese->Buffer = CP_Vector_Set(35, 35);
    cheese->isActive = 1;
    
    cheese[0].Position = CP_Vector_Set(400, 400);
    cheese[5].Position = CP_Vector_Set(1055, 485);
}

void spawn_bad_cheese(void)
{
    CP_Image_Draw(cheese->Image, cheese[0].Position.x, cheese[0].Position.y, cheese->Size.x, cheese->Size.y, 255);
}

void spawn_good_cheese(void)
{
    CP_Image_Draw(cheese->Image, cheese[5].Position.x, cheese[5].Position.y, cheese->Size.x, cheese->Size.y, 255);

}

/*if (gPlayer.collidedWithCheese == 1)
    {
        CP_Image_Free(&gPlayer.goodCheese);
        
    }
    
    else if (gPlayer.collidedWithCheese == 0)
    {
    }*/