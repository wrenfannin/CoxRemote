#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <StopWatch.h>
#include <RemoteXY.h>
#define REMOTEXY_BLUETOOTH_NAME "Cox Remote"

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 89 bytes
  { 255,4,0,0,0,82,0,16,31,1,1,3,3,20,28,28,133,31,83,116,
  97,114,116,32,69,120,101,114,99,105,115,101,0,1,3,31,20,28,28,36,
  31,83,116,111,112,32,69,120,101,114,99,105,115,101,0,1,3,3,48,28,
  28,205,31,82,97,116,101,32,85,112,0,1,3,31,48,28,28,93,31,82,
  97,116,101,32,68,111,119,110,0 };

struct {

    // input variables
  uint8_t startExercise; // =1 if button pressed, else =0 
  uint8_t stopExercise; // =1 if button pressed, else =0 
  uint8_t rateUp; // =1 if button pressed, else =0 
  uint8_t rateDown; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

//////////////////////////////////////////////////////////////////////////
StopWatch sw;
TFT_eSPI tft = TFT_eSPI();


unsigned long previousMillis = 0;     // will store last time LED was updated

const long interval = 1000;  

void setup() 
{
  RemoteXY_Init (); 
  tft.init();
  tft.fillScreen(toInt(203,135,71)); // lea orange
  tft.setRotation(1);

  
}

void loop(){ 
//tft.drawString("Start Exercise!",50,50,4);
  unsigned long currentMillis=millis();
tft.fillScreen(toInt(203,135,71));
  RemoteXY_Handler ();
  if(currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;
  if (RemoteXY.startExercise ==1){
      if (runIf == true){
      tft.fillScreen(toInt(203,135,71));
      tft.drawString("Start Exercise!",50,50,4);
      sw.start();
      tft.drawFloat(sw.elapsed(),50,10,4);
      
    }
  }
  
  }
 // if (RemoteXY.stopExercise ==1)
}




int32_t toInt(int r,int g,int b) {
			
			return (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3));
      
	}


