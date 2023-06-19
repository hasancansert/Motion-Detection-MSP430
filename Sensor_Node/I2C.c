#include "I2C.h"

/*
 * I2C.c
 *
 *  Created on: 24 Ara 2022
 *      Author: Barýþ
 */

void msp430_init()
{
    WDTCTL = WDTPW | WDTHOLD; /* Stop watchdog timer */
    /* Configure the MCLK (and SMCLK) for 1 MHz using the Digitally controlled
     * oscillator (DCO) as source. */
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
}

void i2c_init()
{
    /* Pinmux P1.6 (SCL) and P1.7 (SDA) to I2C peripheral  */
    P1SEL |= BIT6 + BIT7;
    P1SEL2 |= BIT6 + BIT7;

    UCB0CTL1 |= UCSWRST; /* Enable SW reset */

    UCB0CTL0 = UCMST + UCSYNC + UCMODE_3; /* Single master, synchronous mode, I2C mode */
    UCB0CTL1 |= UCSSEL_2; /* SMCLK */
    UCB0BR0 = 80; /* SMCLK / 160 = ~100kHz */
    UCB0BR1 = 0;

    UCB0CTL1 &= ~UCSWRST; /* Clear SW */
    UCB0I2CSA = 0b1101000;
}

bool i2c_write_byte(uint8_t byte)
{
    bool success = false;

    UCB0CTL1 |= UCTXSTT + UCTR; /* Set up master as TX and send start condition */
    /* Note, when master is TX, we must write to TXBUF before waiting for UCTXSTT */
    UCB0TXBUF = byte; /* Fill the transmit buffer with the byte we want to send */

    while (UCB0CTL1 & UCTXSTT); /* Wait for start condition to be sent */
    success = !(UCB0STAT & UCNACKIFG);
    if (success) {
        while (!(IFG2 & UCB0TXIFG)); /* Wait for byte to be sent */
        success = !(UCB0STAT & UCNACKIFG);
    }

    UCB0CTL1 |= UCTXSTP; /* Send the stop condition */
    while (UCB0CTL1 & UCTXSTP); /* Wait for stop condition to be sent */
    success = !(UCB0STAT & UCNACKIFG);
    return success;
}

bool i2c_read_addr8_data8(uint8_t addr, uint8_t *data)
{
    bool success = false;

    UCB0CTL1 |= UCTXSTT + UCTR; /* Set up master as TX and send start condition */
    /* Note, when master is TX, we must write to TXBUF before waiting for UCTXSTT */
    UCB0TXBUF = addr;

    while (UCB0CTL1 & UCTXSTT); /* Wait for start condition to be sent */
    success = !(UCB0STAT & UCNACKIFG);
    if (success) {
        while (!(IFG2 & UCB0TXIFG)); /* Wait for byte to be sent */
        success = !(UCB0STAT & UCNACKIFG);
    }

    /* Address sent, now configure as receiver and get the value */
    if (success) {
        UCB0CTL1 &= ~UCTR; /* Set as a receiver */
        UCB0CTL1 |= UCTXSTT; /* Send (repeating) start condition (including address of slave) */
        while (UCB0CTL1 & UCTXSTT); /* Wait for start condition to be sent */
        success = !(UCB0STAT & UCNACKIFG);

        UCB0CTL1 |= UCTXSTP; /* Only receive one byte */
        while ((UCB0CTL1 & UCTXSTP));

        success &= !(UCB0STAT & UCNACKIFG);
        if (success) {
            while ((IFG2 & UCB0RXIFG) == 0); /* Wait for byte before reading the buffer */
            *data = UCB0RXBUF; /* RX interrupt is cleared automatically afterwards */
        }
    } else {
        /* We should always end with a stop condition */
        UCB0CTL1 |= UCTXSTP; /* Send the stop condition */
        while (UCB0CTL1 & UCTXSTP); /* Wait for stop condition to be sent */
    }

    return success;
}

bool i2c_write_addr8_data8(uint8_t addr, uint8_t data)
{
    bool success = false;

    UCB0CTL1 |= UCTXSTT + UCTR; /* Set up master as TX and send start condition */
    /* Note, when master is TX, we must write to TXBUF before waiting for UCTXSTT */
    UCB0TXBUF = addr; /* Send the address */

    while (UCB0CTL1 & UCTXSTT); /* Wait for start condition to be sent */
    success = !(UCB0STAT & UCNACKIFG);
    if (success) {
        while (!(IFG2 & UCB0TXIFG)); /* Wait for byte to be sent */
        success = !(UCB0STAT & UCNACKIFG);
    }

    if (success) {
        UCB0TXBUF = data; /* Send the value to write */
        while (!(IFG2 & UCB0TXIFG)); /* Wait for byte to be sent */
        success = !(UCB0STAT & UCNACKIFG);
    }
    UCB0CTL1 |= UCTXSTP; /* Send stop condition */
    while (UCB0CTL1 & UCTXSTP); /* Wait for stop condition to be sent */
    return success;
}

