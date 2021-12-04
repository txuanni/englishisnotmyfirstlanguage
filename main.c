/*!
@file main.c
@author Teo Xuan Ni (t.xuanni@digipen.edu)
        David Tan Wei Jie (tan.d@digipen.edu)
        Qairul Shazriz Bin Shamsul (qairulshazriz.b@digipen.edu)
@course GAM
@section AM Section
@brief This file contains code for running the entire game
*//*______________________________________________________________*/

#include <stdio.h>
#include <stdbool.h>
#include "cprocessing.h"

/*!
@brief Initialise the game
@param void
@return void
*//*______________________________________________________________*/
void game_init(void);

/*!
@brief Update the game
@param void
@return void
*//*______________________________________________________________*/
void game_update(void);

/*!
@brief Exit the game
@param void
@return void
*//*______________________________________________________________*/
void game_exit(void);

/*!
@brief run the entire game
@param void
@return int
*//*______________________________________________________________*/
int main(void)
{
    CP_Engine_SetNextGameState(game_init, game_update, game_exit);
    CP_Engine_Run();
    return 0;
}
