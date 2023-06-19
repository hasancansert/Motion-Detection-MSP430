# Motion Detection with MSP430 - A Visualization of Object Movement

[![Project Video](https://img.youtube.com/vi/OB8uu2KnHwE/0.jpg)](https://www.youtube.com/watch?v=OB8uu2KnHwE)

Welcome to the **Motion Detection with MSP430** project! This project seeks to transform the unseen and often ignored physical motions into captivating visual experiences through the power of microcontrollers and the magic of IoT.

## Overview

At its core, this project is a sophisticated, encrypted IoT system designed to detect and visualize object movement. Utilizing the MSP430 microcontrollers and the MPU6050 sensor, it captures position data and transforms it into a comprehensible, appealing 3D visualization. 

The system is comprised of three distinct components:

1. **Sensor Node**: The heartbeat of the system, this node features an accelerometer and gyroscope module (MPU6050) that interfaces with the MSP430 via I2C. It not only captures motion but also performs the encryption before transmitting the data wirelessly using the NRF24 module via SPI.

2. **Decryption Node**: As the guardian of data, it receives the encrypted motion data, processes it through a decryption algorithm, and forwards it to the next node.

3. **UART Message Conversion Node**: The final cog in the machine, it receives the decrypted sensor data and transforms it into a UART message format for visualization on the PC side.

The PC, serving as the stage for the dance of the object, displays the 3D visual representation of the object and its movements, guided by the sensor data. We leveraged the Processing IDE for this visualization, programming in Java.

## Motivation & Aim

In an era of constant digitization, we saw a unique opportunity to merge the physical and digital worlds. We envisioned an immersive system where motion, usually an ephemeral and intangible phenomenon, can be transformed into a visual spectacle - a harmonious ballet of pixels.

The main aim of this project is not only to demonstrate a proof of concept for wireless transmission and visualization of object motion data but also to showcase how encrypted IoT systems can be designed using low-power microcontrollers such as the MSP430.

## Key Concepts

Here are the key concepts and technologies applied in this project:

- **Wireless Sensor Networks**: NRF24 modules are used to establish wireless communication between the different MSP430 MCUs.

- **Encryption/Decryption**: Essential for ensuring data integrity and privacy in any IoT system. The encryption and decryption algorithms run on separate nodes, enhancing security.

- **UART Communication**: The method by which the final MSP430 MCU communicates with the PC to visualize the sensor data.

- **3D Visualization**: Using Java on the Processing IDE, we're able to take the sensor data and bring it to life on the PC screen.

This project is as much about the journey as it is about the final product. We invite you to delve into the code, learn from it, contribute to it, and most importantly - enjoy the mesmerizing dance of object movement brought to life!



