#include "SPI.h"
#include "Jaffl.h"
#include "TF_handler.h"
#include "Energia.h"

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#define LOG(m, f) Serial.print(m); Serial.print(": "); Serial.println(f);delay(10)
#else
#define LOG(m, f) f
#endif

//  FR_OK = 0,        /* (0) Succeeded */
//  FR_DISK_ERR,      /* (1) A hard error occurred in the low level disk I/O layer */
//  FR_INT_ERR,       /* (2) Assertion failed */
//  FR_NOT_READY,     /* (3) The physical drive cannot work */
//  FR_NO_FILE,       /* (4) Could not find the file */
//  FR_NO_PATH,       /* (5) Could not find the path */
//  FR_INVALID_NAME,    /* (6) The path name format is invalid */
//  FR_DENIED,        /* (7) Access denied due to prohibited access or directory full */
//  FR_EXIST,       /* (8) Access denied due to prohibited access */
//  FR_INVALID_OBJECT,    /* (9) The file/directory object is invalid */
//  FR_WRITE_PROTECTED,   /* (10) The physical drive is write protected */
//  FR_INVALID_DRIVE,   /* (11) The logical drive number is invalid */
//  FR_NOT_ENABLED,     /* (12) The volume has no work area */
//  FR_NO_FILESYSTEM,   /* (13) There is no valid FAT volume */
//  FR_MKFS_ABORTED,    /* (14) The f_mkfs() aborted due to any parameter error */
//  FR_TIMEOUT,       /* (15) Could not get a grant to access the volume within defined period */
//  FR_LOCKED,        /* (16) The operation is rejected according to the file sharing policy */
//  FR_NOT_ENOUGH_CORE,   /* (17) LFN working buffer could not be allocated */
//  FR_TOO_MANY_OPEN_FILES, /* (18) Number of open files > _FS_SHARE */
//  FR_INVALID_PARAMETER  /* (19) Given parameter is invalid */

TF_handler::TF_handler(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin; //cs pin

}


int TF_handler::begin(FIL &fp)
{
  Jaffl.begin(_pin);

  LOG("open_code", Jaffl.open(&fp,"DATA.TXT", FA_WRITE | FA_OPEN_ALWAYS));
  if(f_size(&fp)== 0)
  {
    char temp [121];
    snprintf(temp,120,"STATE\tDURATION(S)\tTIME1(mm/dd/yy)(HH:mm:ss)\tTIME2(mm/dd/yy)(HH:mm:ss)\n");
    Jaffl.printf(&fp,temp);
    Jaffl.sync(&fp);
    
  }

 // LOG("lseek_code", Jaffl.lseek(&fp, f_size(&fp)));
 Jaffl.lseek(&fp, f_size(&fp));
}
int TF_handler::store_data(FIL &fp,char* unix_time)
{

  LOG("print code1", Jaffl.printf(&fp,unix_time));

  LOG("sync code", Jaffl.sync(&fp));

}
