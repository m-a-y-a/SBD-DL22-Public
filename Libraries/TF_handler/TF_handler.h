/*
  Voltage_handler.h - Library for reading voltage from voltage sensor.
  Created by JHU SBD-DL22, 10/07/2021.
*/
#ifndef TF_handler_h
#define TF_handler_h
#include "SPI.h"
#include "Jaffl.h"
#include "Energia.h"

class TF_handler
{
  public:
   
    //FIL fp;
    TF_handler(int pin);
    //void store_data(DataEntry datum);
    int begin(FIL &fp);
    int store_data(FIL &fp,char* unix_time);
   
  private:
    int _pin;
    char* unix_time;
    char* voltage;
    
    
};

#endif