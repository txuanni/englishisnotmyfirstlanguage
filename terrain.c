/*!
@file terrain.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
		Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code for setting the terrains positions
and size
*//*______________________________________________________________*/
#include "terrain.h"

/*!
@brief Initialise the terrain position, size and buffer
@param void
@return void
*//*______________________________________________________________*/
void terrain_init(void)
{
	terrain->Image = CP_Image_Load("./Assets/terrain.png");
	for (int i = 24; i < 27; i++)
	{
		terrain[i].isActive = 1;
	}

	//constant terrain
	terrain[0].Position = CP_Vector_Set(900, 650);
	terrain[0].Size = CP_Vector_Set(170, 70);
	terrain[0].Buffer = CP_Vector_Set(85, 35);

	terrain[1].Position = CP_Vector_Set(1200, 550);
	terrain[1].Size = CP_Vector_Set(170, 70);
	terrain[1].Buffer = CP_Vector_Set(85, 35);

	terrain[2].Position = CP_Vector_Set(1500, 450);
	terrain[2].Size = CP_Vector_Set(170, 70);
	terrain[2].Buffer = CP_Vector_Set(85, 35);

	terrain[3].Position = CP_Vector_Set(2700, 250);
	terrain[3].Size = CP_Vector_Set(170, 70);
	terrain[3].Buffer = CP_Vector_Set(85, 35);

	terrain[4].Position = CP_Vector_Set(3700, 650);
	terrain[4].Size = CP_Vector_Set(170, 70);
	terrain[4].Buffer = CP_Vector_Set(85, 35);

	terrain[5].Position = CP_Vector_Set(3900, 550);
	terrain[5].Size = CP_Vector_Set(170, 70);
	terrain[5].Buffer = CP_Vector_Set(85, 35);

	terrain[6].Position = CP_Vector_Set(4100, 450);
	terrain[6].Size = CP_Vector_Set(170, 70);
	terrain[6].Buffer = CP_Vector_Set(85, 35);

	terrain[7].Position = CP_Vector_Set(4300, 350);
	terrain[7].Size = CP_Vector_Set(170, 70);
	terrain[7].Buffer = CP_Vector_Set(85, 35);

	terrain[8].Position = CP_Vector_Set(4700, 350);
	terrain[8].Size = CP_Vector_Set(170, 70);
	terrain[8].Buffer = CP_Vector_Set(85, 35);

	terrain[9].Position = CP_Vector_Set(4900, 450);
	terrain[9].Size = CP_Vector_Set(170, 70);
	terrain[9].Buffer = CP_Vector_Set(85, 35);

	terrain[10].Position = CP_Vector_Set(5100, 550);
	terrain[10].Size = CP_Vector_Set(170, 70);
	terrain[10].Buffer = CP_Vector_Set(85, 35);

	terrain[11].Position = CP_Vector_Set(5500, 550);
	terrain[11].Size = CP_Vector_Set(170, 70);
	terrain[11].Buffer = CP_Vector_Set(85, 35);

	terrain[12].Position = CP_Vector_Set(6700, 650);
	terrain[12].Size = CP_Vector_Set(170, 70);
	terrain[12].Buffer = CP_Vector_Set(85, 35);

	terrain[13].Position = CP_Vector_Set(7000, 550);
	terrain[13].Size = CP_Vector_Set(170, 70);
	terrain[13].Buffer = CP_Vector_Set(85, 35);

	terrain[14].Position = CP_Vector_Set(7168, 550);
	terrain[14].Size = CP_Vector_Set(170, 70);
	terrain[14].Buffer = CP_Vector_Set(85, 35);

	terrain[15].Position = CP_Vector_Set(7336, 550);
	terrain[15].Size = CP_Vector_Set(170, 70);
	terrain[15].Buffer = CP_Vector_Set(85, 35);

	terrain[16].Position = CP_Vector_Set(7550, 650);
	terrain[16].Size = CP_Vector_Set(170, 70);
	terrain[16].Buffer = CP_Vector_Set(85, 35);

	terrain[17].Position = CP_Vector_Set(7750, 750);
	terrain[17].Size = CP_Vector_Set(170, 70);
	terrain[17].Buffer = CP_Vector_Set(85, 35);

	terrain[18].Position = CP_Vector_Set(7918, 750);
	terrain[18].Size = CP_Vector_Set(170, 70);
	terrain[18].Buffer = CP_Vector_Set(85, 35);

	terrain[19].Position = CP_Vector_Set(8086, 650);
	terrain[19].Size = CP_Vector_Set(170, 70);
	terrain[19].Buffer = CP_Vector_Set(85, 35);

	terrain[20].Position = CP_Vector_Set(8300, 550);
	terrain[20].Size = CP_Vector_Set(170, 70);
	terrain[20].Buffer = CP_Vector_Set(85, 35);

	terrain[21].Position = CP_Vector_Set(8700, 550);
	terrain[21].Size = CP_Vector_Set(170, 70);
	terrain[21].Buffer = CP_Vector_Set(85, 35);

	terrain[22].Position = CP_Vector_Set(8900, 650);
	terrain[22].Size = CP_Vector_Set(170, 70);
	terrain[22].Buffer = CP_Vector_Set(85, 35);

	terrain[23].Position = CP_Vector_Set(9100, 750);
	terrain[23].Size = CP_Vector_Set(170, 70);
	terrain[23].Buffer = CP_Vector_Set(85, 35);


	//Fake Terrain
	terrain[24].Position = CP_Vector_Set(4500, 250);
	terrain[24].Size = CP_Vector_Set(170, 70);
	terrain[24].Buffer = CP_Vector_Set(85, 35);

	//Fake Terrain
	terrain[25].Position = CP_Vector_Set(5300, 450);
	terrain[25].Size = CP_Vector_Set(170, 70);
	terrain[25].Buffer = CP_Vector_Set(85, 35);


	//Fake Terrain
	terrain[26].Position = CP_Vector_Set(8500, 460);
	terrain[26].Size = CP_Vector_Set(170, 70);
	terrain[26].Buffer = CP_Vector_Set(85, 35);
}
