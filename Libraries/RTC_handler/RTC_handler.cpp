/*
RTC_handler.cpp - Library for getting real time from RTC module
Created by JHU SBD-DL22, 10/07/2021
*/

//TODO: add explanation of what libraries are for
#include "Energia.h"
#include "RTC_handler.h"
#include <Wire.h>
#include <config.h>
#include <ds3231.h>

#ifndef CONFIG_UNIXTIME
  #define CONFIG_UNIXTIME
#endif

struct ts t;
static char timevars[6];

RTC_handler::RTC_handler()
{
  Wire.begin();
}

// Returns unix time
uint32_t RTC_handler::get_unix_time()
{
  DS3231_get(&t);
  //get_unixtime(t);
  // return t.mday;
  return t.unixtime;
}
char* RTC_handler::get_time_stamp()
{
  DS3231_get(&t);
  //get_unixtime(t);
  // return t.mday;
  //uint8_t TimeDate[7]= {t.mday, t.mon, t.year, t.hour, t.min, t.sec}
  char time_stamp_temp[20] = {(char)t.mon,'/',(char)t.mday,'/',(char)t.year,' ',(char)t.hour,':',(char)t.min,':',(char)t.sec};
  char(*time_stamp) = {"0"};
  time_stamp= time_stamp_temp;
  return time_stamp;
}
