/*
 * ultrasonic.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <stdint.h>

void Ultrasonic_Init(void);
uint32_t Ultrasonic_ReadDistance_cm(void); /* blocking read, returns distance in cm, 0 on timeout */
#endif

