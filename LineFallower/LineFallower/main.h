/*
 * main.h
 *
 * Created: 12/18/2024 11:32:58 AM
 *  Author: alexg
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Define
#define LEFT_BACKWARD PORTG5
#define LEFT_FORWARD PORTE3
#define RIGHT_BACKWARD PORTE4
#define RIGHT_FORWARD PORTE5

//Macro
#define LEFT_MOTOR_FORWARD() PORTE |= (1 << LEFT_FORWARD); PORTG &= ~(1 << LEFT_BACKWARD)
#define LEFT_MOTOR_BACKWARD() PORTG |= (1 << LEFT_BACKWARD); PORTE &= ~(1 << LEFT_FORWARD)
#define RIGHT_MOTOR_FORWARD() PORTE |= (1 << RIGHT_FORWARD); PORTE &= ~(1 << RIGHT_BACKWARD)
#define RIGHT_MOTOR_BACKWARD() PORTE |= (1 << RIGHT_BACKWARD); PORTE &= ~(1 << RIGHT_FORWARD)
#define STOP_MOTORS() PORTE &= ~((1 << RIGHT_FORWARD) | (1 << RIGHT_BACKWARD) | (1 << LEFT_FORWARD)); PORTG &= ~(1 << LEFT_BACKWARD)

//Function prototype
void motorsPinsInit(void);


#endif /* MAIN_H_ */