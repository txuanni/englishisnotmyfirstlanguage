#include "cheese.h"
#include "player.h"

void cheese_init(void)
{
    cheese->Image = CP_Image_Load("./Assets/cheese.png");
    cheese->Size = CP_Vector_Set(70, 70);
    cheese->Buffer = CP_Vector_Set(35, 35);
    cheese->isActive = 1;
    cheese->Counter = 0;

    cheese[0].Position = CP_Vector_Set(900, 580);
    cheese[1].Position = CP_Vector_Set(1200, 480);
    cheese[2].Position = CP_Vector_Set(1500, 380);
    cheese[3].Position = CP_Vector_Set(2100, 260);
    cheese[4].Position = CP_Vector_Set(2700, 180);
    cheese[5].Position = CP_Vector_Set(2880, 290);
    cheese[6].Position = CP_Vector_Set(2880, 380);
    cheese[7].Position = CP_Vector_Set(2880, 470);
    cheese[8].Position = CP_Vector_Set(2880, 690);
    cheese[9].Position = CP_Vector_Set(3900, 480);
    cheese[10].Position = CP_Vector_Set(4300, 280);
    cheese[11].Position = CP_Vector_Set(4700, 280);
    cheese[12].Position = CP_Vector_Set(4900, 380);
    cheese[13].Position = CP_Vector_Set(5750, 700);
    cheese[14].Position = CP_Vector_Set(6700, 580);
    cheese[15].Position = CP_Vector_Set(7168, 480);
    cheese[16].Position = CP_Vector_Set(7550, 580);
    cheese[17].Position = CP_Vector_Set(7750, 680);
    cheese[18].Position = CP_Vector_Set(7918, 680);
    cheese[19].Position = CP_Vector_Set(8300, 480);
    cheese[20].Position = CP_Vector_Set(8900, 580);
    cheese[21].Position = CP_Vector_Set(8700, 480);
    cheese[22].Position = CP_Vector_Set(9100, 580);
    cheese[23].Position = CP_Vector_Set(9600, 700);
    cheese[24].Position = CP_Vector_Set(4500, 180);
    cheese[25].Position = CP_Vector_Set(5300, 380);
}

void spawn_bad_cheese(void)
{
    CP_Image_Draw(cheese->Image, cheese[8].Position.x, cheese[8].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[12].Position.x, cheese[12].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[13].Position.x, cheese[13].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[17].Position.x, cheese[17].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[20].Position.x, cheese[20].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[23].Position.x, cheese[23].Position.y, cheese->Size.x, cheese->Size.y, 255);

}

void spawn_good_cheese(void)
{
    CP_Image_Draw(cheese->Image, cheese[0].Position.x, cheese[0].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[1].Position.x, cheese[1].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[2].Position.x, cheese[2].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[3].Position.x, cheese[3].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[4].Position.x, cheese[4].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[5].Position.x, cheese[5].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[6].Position.x, cheese[6].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[7].Position.x, cheese[7].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[9].Position.x, cheese[9].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[10].Position.x, cheese[10].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[11].Position.x, cheese[11].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[14].Position.x, cheese[14].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[15].Position.x, cheese[15].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[16].Position.x, cheese[16].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[18].Position.x, cheese[18].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[19].Position.x, cheese[19].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[21].Position.x, cheese[21].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[22].Position.x, cheese[22].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[24].Position.x, cheese[24].Position.y, cheese->Size.x, cheese->Size.y, 255);
    CP_Image_Draw(cheese->Image, cheese[25].Position.x, cheese[25].Position.y, cheese->Size.x, cheese->Size.y, 255);


}