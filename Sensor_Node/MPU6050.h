/*
 * MPU6050.h
 *
 *  Created on: 24 Ara 2022
 *      Author: Barýþ
 */

#ifndef MPU6050_H_
#define MPU6050_H_

#include <msp430.h>
#include <stdint.h>

void mpu_init(void);
float get_temp(void);


#endif /* MPU6050_H_ */
