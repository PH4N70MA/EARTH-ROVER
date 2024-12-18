/*
 * LineFallower.cpp
 *
 * Created: 12/17/2024 7:17:24 PM
 * Author : alexg
 */ 

#include "main.h"


int main(void)
{
    motorsPinsInit();
    while (1) 
    {
       
    }
}

void motorsPinsInit(void)
{
    //setam pini pentru motor ca iesire cu Valorile initiale 0
    //Initializam pini pentru motor
    DDRE |= (1 << DDE4) | (1 << DDE5) | (1 << DDE3);
    DDRG |= (1 << DDG5);
    //setam in 0 pini pentru motor
    STOP_MOTORS();
}