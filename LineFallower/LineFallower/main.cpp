/*
 * LineFallower.cpp
 *
 * Created: 12/17/2024 7:17:24 PM
 * Author : alexg
 */ 

#include "main.h"

int main(void)
{
    ADC_init();
    motorsInit();
    while (1) 
    {   
        //TEST
        if(ADC_read(MID_SENSOR) > IR_SENSOR_THRESHOLD)
        {
            motorTimerDisable();
            _delay_ms(100);
        }
		else
		{
			motorTimerEnable();
		}
    }
}

void motorsInit(void)
{
    // Configure Timer/Counter3 for correct phase mode, 255 match value, 256 prescaler, and output pins
    TCCR3A = (1 << WGM30) | (1 << COM3A1) | (1 << COM3B1); // Phase Correct PWM, 8-bit
    TCCR3B = (1 << CS32); // Prescaler 256
    LEFT_FORWARD_COMP_VALUE = 64; // Match value for Timer/Counter3
    RIGHT_FORWARD_COMP_VALUE = 64; // Match value for Timer/Counter3

    // Set output pins for Timer/Counter3
    DDRE |= (1 << PE3) | (1 << PE4); // Set PE3 and PE4 as output for Timer/Counter3
    
    //setam pini pentru motor ca iesire cu Valorile initiale 0
    //Initializam pini pentru motor
    DDRA |= (1 << DDA0) | (1 << DDA1) | (1 << DDA2) | (1 << DDA3);

    //setam in 0 pini pentru motor
    STOP_MOTORS();
    motorTimerDisable();
}

void motorTimerDisable(void)
{
    // Disable Timer/Counter3
    TCCR3B &= ~((1 << CS32) | (1 << CS31) | (1 << CS30));
}

void motorTimerEnable(void)
{
    // Enable Timer/Counter3
    TCCR3B |= (1 << CS32);
}