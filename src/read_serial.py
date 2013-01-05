#!/usr/bin/python

# Test to read any serial value send from Arduino

device = '/dev/ttyACM3'

import serial

arduino = serial.Serial(device, 9600)
while 1:
    print arduino.readline()

