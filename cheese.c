#include "cheese.h"
#include "player.h"

void cheese_init(void)
{
    cheese->Image = CP_Image_Load("./Assets/cheese.png");
    cheese->Size = CP_Vector_Set(70, 70);
    cheese->Buffer = CP_Vector_Set(35, 35);
    for (int i = 0; i < 26; i++)
    {
        cheese[i].isActive = 1;
    }
    
    cheese->Counter = 0;

    //good cheese spawn pos
    cheese[0].Position = CP_Vector_Set(900, 580);
    cheese[1].Position = CP_Vector_Set(1200, 480);
    cheese[2].Position = CP_Vector_Set(1500, 380);
    cheese[3].Position = CP_Vector_Set(2100, 260);
    cheese[4].Position = CP_Vector_Set(2700, 180);
    cheese[5].Position = CP_Vector_Set(2880, 290);
    cheese[6].Position = CP_Vector_Set(2880, 380);
    cheese[7].Position = CP_Vector_Set(2880, 470);
    cheese[8].Position = CP_Vector_Set(3900, 480);
    cheese[9].Position = CP_Vector_Set(4300, 280);
    cheese[10].Position = CP_Vector_Set(4700, 280);
    cheese[11].Position = CP_Vector_Set(6700, 580);
    cheese[12].Position = CP_Vector_Set(7168, 480);
    cheese[13].Position = CP_Vector_Set(7550, 580);
    cheese[14].Position = CP_Vector_Set(7918, 680);
    cheese[15].Position = CP_Vector_Set(8300, 480);
    cheese[16].Position = CP_Vector_Set(8700, 480);
    cheese[17].Position = CP_Vector_Set(9100, 580);
    cheese[18].Position = CP_Vector_Set(4500, 180);
    cheese[19].Position = CP_Vector_Set(5300, 380);
    cheese[20].Position = CP_Vector_Set(9600, 700);

    //bad cheese spawn pos
    cheese[21].Position = CP_Vector_Set(2880, 690);
    cheese[22].Position = CP_Vector_Set(4900, 380);
    cheese[23].Position = CP_Vector_Set(5750, 700);
    cheese[24].Position = CP_Vector_Set(7750, 680);
    cheese[25].Position = CP_Vector_Set(8900, 580);
    cheese[26].Position = CP_Vector_Set(9600, 700);
}
