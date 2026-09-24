# Blinking LED

## Overview

A basic ESP32 Arduino project that demonstrates GPIO output control by blinking an LED at regular intervals.

## Hardware

- ESP32
- LED
- 220Ω resistor

## Software

- Arduino
- Wokwi

## GPIO Used

GPIO 2

## Working

```text
ESP32
  The LED is turned ON for 1 second and OFF for 1 second repeatedly.

Arduino Functions Used
pinMode()
digitalWrite()
delay()
What I Learned
GPIO output configuration
Digital HIGH and LOW
Basic Arduino program structure
setup() and loop()│
GPIO 2
  │
220Ω Resistor
  │
 LED
  │
 GND
