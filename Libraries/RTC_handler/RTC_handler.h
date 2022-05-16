/*
RTC_handler.h - library for getting real time from real time module
Created by JHU SBD-DL22, 10/07/2021
*/

#ifndef RTC_handler_h
#define RTC_handler_h

#include "Energia.h"
#include <ds3231.h>


class RTC_handler
{
   public:
      RTC_handler();
      // original versions
      int64_t get_unix_time();
      unsigned int get_datetime(char* str, unsigned int str_size);

      // optimized versions
      void get_time_s(struct ts *t);
      unsigned int get_datetime_s(char* str, unsigned int str_size, struct ts &t);
};
#endif
