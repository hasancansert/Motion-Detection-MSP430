/*
 * I2C.h
 *
 *  Created on: 24 Ara 2022
 *      Author: Barış
 */


#ifndef I2C_H_
#define I2C_H_

#include <msp430.h>
#include <stdint.h>

typedef enum {
    false,
    true
}bool;

void msp430_init();
void i2c_init();
bool i2c_write_byte(uint8_t byte);
bool i2c_read_addr8_data8(uint8_t addr, uint8_t *data);
bool i2c_write_addr8_data8(uint8_t addr, uint8_t data);



#endif /* I2C_H_ */
