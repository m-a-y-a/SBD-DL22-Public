/*
  Voltage_handler.cpp - Library for reading voltage from voltage sensor.
  Created by JHU SBD-DL22, 09/30/2021.
*/

#include "Energia.h"
#include "Voltage_handler.h"

int volt = 0;
int vOut = 0;
int vIn = 0;

Voltage_handler::Voltage_handler(int pin)
{
  pinMode(13, INPUT);
  _pin = pin;
}

uint32_t  Voltage_handler::get_voltage()
{
  volt = analogRead(13);                        //read the input voltage
  vOut = ((volt * 3.3)) / 4095.0;
  vIn = vOut / (7500.0 / (7500.0 + 30000.0));
  uint32_t voltage = map(volt, 0, 629, 0, 4);                                     //wait half a second (~2Hz)
  return volt;
}