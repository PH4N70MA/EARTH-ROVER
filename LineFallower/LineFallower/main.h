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
#include "Lib/IR_ADC/IRADC.h"

//Define
//Motor pins
#define LEFT_BACKWARD PORTA2
#define LEFT_FORWARD PORTA3
#define RIGHT_BACKWARD PORTA0
#define RIGHT_FORWARD PORTA1
//IR sensors pins
#define MID_SENSOR sensorFour
#define LEFT_NEAR_SENSOR sensorThree
#define LEFT_FAR_SENSOR sensorFive
#define RIGHT_NEAR_SENSOR sensorOne
#define RIGHT_FAR_SENSOR sensorTwo
//Values
#define IR_SENSOR_THRESHOLD 768


//Macro
#define LEFT_MOTOR_FORWARD() PORTA |= (1 << LEFT_FORWARD); PORTA &= ~(1 << LEFT_BACKWARD)
#define LEFT_MOTOR_BACKWARD() PORTA &= ~(1 << LEFT_FORWARD); PORTA |= (1 << LEFT_BACKWARD)
#define RIGHT_MOTOR_FORWARD() PORTA |= (1 << RIGHT_FORWARD); PORTA &= ~(1 << RIGHT_BACKWARD)
#define RIGHT_MOTOR_BACKWARD() PORTA |= (1 << RIGHT_BACKWARD); PORTA &= ~(1 << RIGHT_FORWARD)
#define STOP_MOTORS() PORTA &= ~((1 << RIGHT_FORWARD) | (1 << RIGHT_BACKWARD) | (1 << LEFT_FORWARD)| (1 << LEFT_BACKWARD))

//Function prototype
void motorsInit(void);


#endif /* MAIN_H_ */