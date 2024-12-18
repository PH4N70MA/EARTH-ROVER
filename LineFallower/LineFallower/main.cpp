/*
 * LineFallower.cpp
 *
 * Created: 12/17/2024 7:17:24 PM
 * Author : alexg
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    DDRE |= (1 << DDE4) | (1 << DDE5) | (1 << DDE3);
    DDRG |= (1 << DDG5);
    PORTE &= ~(1 << PORTE4) | ~(1 << PORTE5) | ~(1 << PORTE3);
    PORTG &= ~(1 << PORTG5);
    while (1) 
    {
    }
}

