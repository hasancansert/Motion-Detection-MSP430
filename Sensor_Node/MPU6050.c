/*
 * MPU6050.c
 *
 *  Created on: 24 Ara 2022
 *      Author: Barış
 */

#include "MPU6050.h"


float get_temp(void)
{
    uint8_t reg_data;
    int16_t reg_data16;
    float temp_C;
    i2c_read_addr8_data8(0x41, &reg_data);
    reg_data16 = reg_data << 8;
    i2c_read_addr8_data8(0x42, &reg_data);
    reg_data16 |= reg_data;
    temp_C = reg_data16 / 340 + 36.53;
    return temp_C;
}

void mpu_init(void)
{
    i2c_write_addr8_data8(0x6B,0x80);       // reset mpu
    __delay_cycles(100000);
    i2c_write_addr8_data8(0x6B,0x00);       // wake up mpu

    i2c_write_addr8_data8(0x68,0x07);       // reset signal paths
    __delay_cycles(100000);
    i2c_write_addr8_data8(0x6A,0x00);       // set i2c mode and disable fifo
    i2c_write_addr8_data8(0x6B,0x00);       // set clock source Internal 8MHz oscillator
    i2c_write_addr8_data8(0x19,0x07);       // set clock divider as 8
    i2c_write_addr8_data8(0x1A,0x00);       // set DLP 260Hz
    i2c_write_addr8_data8(0x1B,0x00);       // set Gyroscope Config 250 d/s
    i2c_write_addr8_data8(0x1C,0x00);       // set Accelerometer Config 2g
    i2c_write_addr8_data8(0x1B,0x00);       // set Gyroscope Config 250 d/s
}
