/*
RTC_handler.h - library for getting real time from real time module
Created by JHU SBD-DL22, 10/07/2021
*/

#ifndef RTC_handler_h
#define RTC_handler_h

#include "Energia.h"

class RTC_handler
{
   public:
      RTC_handler();
      uint32_t get_unix_time();
      char* get_time_stamp();
    
};
#endif
