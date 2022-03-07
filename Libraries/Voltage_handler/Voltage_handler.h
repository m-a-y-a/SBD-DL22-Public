/*
  Voltage_handler.h - Library for reading voltage from voltage sensor.
  Created by JHU SBD-DL22, 09/30/2021.
*/
#ifndef Voltage_handler_h
#define Voltage_handler_h

#include "Energia.h"

class Voltage_handler
{
  public:
    Voltage_handler(int pin);
    uint32_t  get_voltage();
  private:
    int _pin;
};
#endif