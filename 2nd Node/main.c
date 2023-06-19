#include <msp430.h> 
#include "msprf24.h"
#include "nrf_userconfig.h"
#include "stdint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aes.h"

volatile unsigned int user;

uint8_t buf[32];
uint8_t addr[5];

void Clock_init(void);
void LED_init(void);
void configure_rx(int channel);
void configure_tx(int channel);

void set_channel(uint8_t rf_channel);
void LED_On(void);
void LED_Off(void);

void AES_128_ECB_encrypt(uint8_t *in);
void AES_128_ECB_decrypt(uint8_t *in);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	Clock_init();               // Adjust clock 8MHz
    configure_rx(120);          // configure rx
	LED_init();
	LPM4;                       // Wait interrupt at LPM4

	while(1)
    {
	    if (rf_irq & RF24_IRQ_FLAGGED)
	    {
	        rf_irq &= ~RF24_IRQ_FLAGGED;        // Clear RF interrupt flag
	        msprf24_get_irq_reason();
	    }

	    if (rf_irq & RF24_IRQ_RX || msprf24_rx_pending())
	    {
	        r_rx_payload(32, buf);
	        msprf24_irq_clear(RF24_IRQ_RX);

	        AES_128_ECB_decrypt(buf);           // Decrypte the received datas and store at buf[] array

	        user = buf[0];
	    }
	    else
	    {
	        user = 0xFF;
	    }

	    flush_rx();
	    flush_tx();
	    configure_tx(80);

       // __delay_cycles(10000);
        w_tx_payload(32, buf); // load payload with data
        msprf24_activate_tx();
        __bis_SR_register(LPM4_bits + GIE); // LPM with interrupts enabled

        if (rf_irq & RF24_IRQ_FLAGGED)  // TX Interrupt flag
        {
            msprf24_get_irq_reason();
            if (rf_irq & RF24_IRQ_TX)   // TX successful
            {
                LED_Off();                // Green LED off
            }
            if (rf_irq & RF24_IRQ_TXFAILED) // TX failed
            {
                LED_On();               // Green LED on
            }

            msprf24_irq_clear(rf_irq); // clear interrupt flag
        }

        flush_rx();
        flush_tx();

        configure_rx(120);          // configure rx

	    LPM4;


    }
}

void Clock_init(void)
{
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS_1;  // SMCLK = DCOCLK/2
    // SPI (USCI) uses SMCLK, prefer SMCLK < 10MHz (SPI speed limit for nRF24 = 10MHz)
}

void LED_init(void)
{
    P1DIR |= BIT0;      // Green LED output.
    P1OUT &= ~BIT0;
}

void LED_On(void)
{
    P1OUT |= BIT0;       // Green LED on
}

void LED_Off(void)
{
    P1OUT &= ~BIT0;     // Green LED off
}

void configure_rx(int channel)
{
    user = 0xFE;

    /* Initial values for nRF24L01+ library config variables */
    rf_crc = RF24_EN_CRC | RF24_CRCO; // CRC enabled, 16-bit
    rf_addr_width = 5;
    rf_speed_power = RF24_SPEED_1MBPS | RF24_POWER_0DBM;
    rf_channel = channel;

    msprf24_init();
    msprf24_set_pipe_packetsize(0, 32);
    msprf24_open_pipe(0, 1);  // Open pipe#0 with Enhanced ShockBurst

    // Set our RX address
    addr[0] = 0xDE;
    addr[1] = 0xAD;
    addr[2] = 0xBE;
    addr[3] = 0xEF;
    addr[4] = 0x00;
    w_rx_addr(0, addr);

    // Receive mode
    if (!(RF24_QUEUE_RXEMPTY & msprf24_queue_state()))
    {
        flush_rx();
    }
    msprf24_activate_rx();
}

void configure_tx(int channel)
{
    rf_channel = channel;

    msprf24_init();  // All RX pipes closed by default
    msprf24_set_pipe_packetsize(0, 32);
    msprf24_open_pipe(0, 1); // Open pipe#0 with Enhanced ShockBurst enabled for receiving Auto-ACKs

    // Transmit to 'rad01' (0x72 0x61 0x64 0x30 0x31)
    msprf24_standby();
    user = msprf24_current_state();
    addr[0] = 0xDE;
    addr[1] = 0xAD;
    addr[2] = 0xBE;
    addr[3] = 0xEF;
    addr[4] = 0x00;
    w_tx_addr(addr);
    w_rx_addr(0, addr); // Pipe 0 receives auto-ack's, autoacks are sent back to the TX addr so the PTX node
    // needs to listen to the TX addr on pipe#0 to receive them.

}

void AES_128_ECB_decrypt(uint8_t *in)        // Decrypt datas at in[] array and store at in[]
{
    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

    struct AES_ctx ctx;

    AES_init_ctx(&ctx, key);
    AES_ECB_decrypt(&ctx, in);
}

void AES_128_ECB_encrypt(uint8_t *in)        // Encrypt datas at in[] array and store at in[]
{
    struct AES_ctx ctx;

    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

    AES_init_ctx(&ctx, key);
    AES_ECB_encrypt(&ctx, in);
}
