# Wi-Fi Controlled LED

## Overview

A simple ESP32 project developed using Arduino programming and Wokwi simulation.

The ESP32 connects to Wi-Fi and hosts a simple web server. The LED connected to GPIO 2 can be controlled using ON and OFF buttons from the web interface.

## Hardware

- ESP32
- LED
- 220Ω resistor

## Software

- Arduino
- Wokwi
- ESP32 Arduino Core

## Circuit

```text
ESP32 GPIO 2
     |
   220Ω
     |
    LED
     |
    GND


---
