/*!
@file controls.h
@author Teo Xuan Ni (t.xuanni@digipen.edu)
@course GAM
@section AM Section
@brief This file contains declarations for controls.c
*//*______________________________________________________________*/
#include "cprocessing.h"

/*!
@brief Initialise position of the buttons
@param void
@return void
*//*______________________________________________________________*/
void controls_init();

/*!
@brief Render the control buttons
@param void
@return void
*//*______________________________________________________________*/
void drawControlButtons();

struct Buttons
{
    CP_Vector Position;
    CP_Vector Size;
    CP_Vector Buffer;
    CP_Vector TextPosition;
    CP_Vector TextSize;
    CP_Vector KeyButtonSize;
}; struct Buttons button[10];