/*
RTC_handler.cpp - Library for getting real time from RTC module
Created by JHU SBD-DL22, 10/07/2021
*/

//TODO: add explanation of what libraries are for
#include "Energia.h"
#include "RTC_handler.h"
#include <Wire.h>
#include <config.h>


#ifndef CONFIG_UNIXTIME
  #define CONFIG_UNIXTIME
#endif

struct ts t;

RTC_handler::RTC_handler()
{
  Wire.begin();
}

// Returns unix time
int64_t RTC_handler::get_unix_time()
{
  DS3231_get(&t);
  return t.unixtime;
}

unsigned int RTC_handler::get_datetime(char* str, unsigned int str_size)
{
  DS3231_get(&t);
  return snprintf(str, str_size,"%02d/%02d/%04d-%02d:%02d:%02d",t.mon, t.mday, t.year, t.hour, t.min, t.sec);
}

// Returns time
void RTC_handler::get_time_s(struct ts *t)
{
  DS3231_get(t);
}

unsigned int RTC_handler::get_datetime_s(char* str, unsigned int str_size, struct ts &t)
{
  return snprintf(str, str_size,"%02d/%02d/%04d-%02d:%02d:%02d",t.mon, t.mday, t.year, t.hour, t.min, t.sec);
}

