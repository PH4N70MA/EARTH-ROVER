/*
 * IRADC.c
 *
 *  Author: alexg
 */ 


#ifndef AD8495_H_
#define AD8495_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    sensorOne,
    sensorTwo,
    sensorThree,
    sensorFour,
    sensorFive
} SensorPin;

void ADC_init(void);
uint16_t ADC_read(SensorPin channel);
float ADC_Filter(uint8_t precision, SensorPin channel);

#ifdef __cplusplus
}
#endif

#endif /* AD8495_H_ */