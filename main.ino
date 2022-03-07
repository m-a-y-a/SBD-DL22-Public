// THIS IS MAIN V2
#include <Voltage_handler.h>
//#include <Current_handler.h>
#include <TF_handler.h>
#include <RTC_handler.h>
//#include "Jaffl.h"
FIL fp;

Voltage_handler voltage_sensor_handler(23);   //create voltage handler object and assign to pin 23
//Current_handler current_handler(24);
RTC_handler rtc_handler;                      //create rtc handler object
TF_handler tf_handler(P1_3);                  //create tf handerl object and assign to (P1.3)

void setup() {

  tf_handler.begin(fp);                       //
  Serial.begin(9600);                         //establish Serial comms (9600 baud rate)
  Serial.println("Succesful initialization."); 

  delay(200);                                 //wait 200ms
}

//returns true or false depending if the input voltage is greater than 3V
//currently always true because volt is set to 5V
inline bool enough_charge_p() {             
  //int volt = voltage_sensor_handler.get_voltage();
  int volt = 5;
  Serial.println(volt);
  return volt > 3;
}

//for debugging purposes
inline void log_data() {
  Serial.println("Logging!");
  char* unix_time = "1024\n"; //rtc_handler.get_unix_time();
  //int voltage   = voltage_sensor_handler.get_voltage();
  char* voltage = "5\n";

  Serial.println(unix_time);
  Serial.println(voltage);

//  tf_handler.store_data(fp, unix_time, voltage);
}

// 
inline void post_processing() {
  uint32_t unix_time;          //new time
  uint32_t unix_time2;       //reference time
  char *timestamp;
  char *timestamp2;
  if (voltage_sensor_handler.get_voltage() > 3.3)
  {
    unix_time = rtc_handler.get_unix_time();
    timestamp = rtc_handler.get_time_stamp();
  }
  else if (voltage_sensor_handler.get_voltage() == 0)
  {
    unix_time2 = rtc_handler.get_unix_time();
    int substraction = unix_time2 - unix_time;
    timestamp2 = rtc_handler.get_time_stamp();
    char temp[] = {'O', 'N', '\t', substraction, '\t', timestamp[0],timestamp[1],timestamp[2],timestamp[3],timestamp[4],timestamp[5]
    ,timestamp[6],timestamp[7],timestamp[8],timestamp[9],timestamp[10],timestamp[11],'\t'
    ,timestamp2[0],timestamp2[1],timestamp2[2],timestamp2[3],timestamp2[4],timestamp2[5],timestamp2[6],timestamp2[7],timestamp2[8],timestamp2[9],timestamp2[10],timestamp2[11] 
    ,'\t', '\n', '\0'};//char* temp = "STATE  DURATION(S) TIME1(mm/dd/yy)(HH:mm:ss) TIME2(mm/dd/yy)(HH:mm:ss)";
    char *output2;
    output2= temp;
    Serial.println(output2);
    tf_handler.store_data(fp,output2);
  }

}

void loop() {
  if (enough_charge_p())
    post_processing();
//  int time = millis();
//  Serial.println(time);
    
  delay(500);
}
