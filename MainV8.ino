// THIS IS MAIN V_TEST
#include <TF_handler.h>
#include <RTC_handler.h>
#include "Jaffl.h"

// Options: ORIGINAL, OPTIMIZED
#define OPTIMIZED
//#define ORIGINAL
//Options : Duration printing on or off
//#define DURATION_RUNTIME_CLOSED
//#define DURATION_RUNTIME_OPEN
#if defined(DURATION_RUNTIME_OPEN)
unsigned long if_start_1 = micros();
#endif
FIL fp;
int64_t unixtime_start = 0;
int64_t unixtime_end = 0;
RTC_handler rtc_handler;                      //create rtc handler object
TF_handler tf_handler(P1_3);                  //create tf handerl object and assign to (P1.3)
int const voltage_pin = P1_5;
char datetime_start[20];
char datetime_end[20];
char data[120];
int64_t duration_data = 0 ;

#ifdef OPTIMIZED
struct ts tp;
#endif
void subroutine()
{
  tf_handler.begin(fp);

#if defined(ORIGINAL)
  unixtime_start = rtc_handler.get_unix_time();
  rtc_handler.get_datetime(datetime_start, 20);
#elif defined(OPTIMIZED)
  rtc_handler.get_time_s(&tp);
  unixtime_start = tp.unixtime;
  rtc_handler.get_datetime_s(datetime_start, 20, tp);
#endif

#if defined(DURATION_RUNTIME_OPEN)
  unsigned long if_end_1 = micros();
  char time_duration[128];
  unsigned long duration = -if_end_1 + if_start_1 ;
  snprintf(time_duration, 128, "open routine duration: %d us\n", duration );
  tf_handler.store_data(fp, time_duration);

#endif
}

void setup() {

  subroutine();// take the first time and timestamp 

}

void loop() {

#if defined(DURATION_RUNTIME_CLOSED)
  unsigned long if_start = micros();
#endif
  // *3 represents a constant that modifies the maximum voltage in which the if statement considers the tool to be on
  // 1241 is aproximetly 1V. This means that anything less than 3 V is considered off or in process to turn off 
  
  if (analogRead(voltage_pin) < 1241 * 3 || !digitalRead(voltage_pin) )
  {

#if defined(ORIGINAL)
    unixtime_end = rtc_handler.get_unix_time();
    rtc_handler.get_datetime(datetime_end, 20);
#elif defined(OPTIMIZED)
    rtc_handler.get_time_s(&tp);
    unixtime_end = tp.unixtime;
    rtc_handler.get_datetime_s(datetime_end, 20, tp);
#endif

    duration_data = unixtime_end - unixtime_start;

    if (duration_data < 2)
    {
      while (1)
      {
      } // waste cpu time until brownout
    }
    //"STATE  DURATION(S) TIME1(mm/dd/yy)(HH:mm:ss) TIME2(mm/dd/yy)(HH:mm:ss)";
    snprintf(data, 120, "ON\t%lld\t%s\t%s\n", duration_data, datetime_start, datetime_end);
    tf_handler.store_data(fp, data);

#if defined(DURATION_RUNTIME_CLOSED)
    unsigned long if_end = micros();
    char time_duration[128];
    int duration = (int)if_end - (int)if_start;

    snprintf(time_duration, 128, "Close routine duration: %d us\n", duration);
    tf_handler.store_data(fp, time_duration);
#endif

    if (digitalRead(voltage_pin))
    {
      subroutine(); // redo first time and timestamp 
    } 
    else
      while (1) // waste cpu time until brownout
      {
          Jaffl.close(&fp); 
      };

  }
}

//this removes MSP startup protocol and removes 2sec time
#ifdef __cplusplus
extern "C" {
#endif
void enableXtal() {
  // avoid startup delay
}
#ifdef __cplusplus
}
#endif
