# MPU6050-Wireless-Sensor-Node-MPS430G2553
This project aims to take position data from the MPU6050 sensor and transmit the data to another MSP430 MCU  wireless by using NRF24l01+.

We designed an encrypted IoT system to visualize object movement. The project includes 3 MSP430 microprocessors and one PC. Each MSP430 communicate with the other by using an NRF24 wireless sensor module and one of them communicates PC through the UART interface. 

The sensor node has an accelerometer and gyroscope module. This module communicates with MSP430 through the I2C interface. The encryption part also performs on this node. NRF24 provides wireless communication and it configures by using the SPI interface.

The decryption node performs the decryption algorithm and it also includes NRF24 wireless module.

The last node takes encrypted sensor information through NRF24 and converts the UART message format.

PC side provides 3D object and its movements according to sensor data. Processing IDE was used for visualization. It is programmed via Java language.

Project Video Link: https://www.youtube.com/watch?v=OB8uu2KnHwE






