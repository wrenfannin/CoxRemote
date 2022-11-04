#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <RemoteXY.h>
#include "Free_Fonts.h"
// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 28 bytes
  { 255,1,0,0,0,21,0,16,31,1,1,0,9,26,40,40,37,149,83,104,
  111,119,32,116,101,120,116,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

TFT_eSPI tft = TFT_eSPI();

void setup() 
{
  RemoteXY_Init (); 
  tft.init();
  tft.fillScreen(TFT_RED);
  tft.setFreeFont(&FreeSansBoldOblique24pt7b);
  // TODO you setup code
  
}

void loop() 
{ 
 RemoteXY_Handler ();
  if (RemoteXY.button_1 == 1){
    tft.setTextColor(TFT_BLACK);
    tft.drawString("Text Here",10,120,4);
  }
  else{
    tft.fillScreen(TFT_RED); 
  } 

}