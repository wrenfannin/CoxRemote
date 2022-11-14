/***
 *       _____             _____                          _        
 *      / ____|           |  __ \                        | |       
 *     | |      ___ __  __| |__) | ___  _ __ ___    ___  | |_  ___ 
 *     | |     / _ \\ \/ /|  _  / / _ \| '_ ` _ \  / _ \ | __|/ _ \
 *     | |____| (_) |>  < | | \ \|  __/| | | | | || (_) || |_|  __/
 *      \_____|\___//_/\_\|_|  \_\\___||_| |_| |_| \___/  \__|\___|
 *                                                                 
 *                                                                 
 */

#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#include <TFT_eSPI.h>
#include "Free_Fonts.h"
#include <RemoteXY.h>
#include <SPI.h>
#include <Chrono.h>
#define REMOTEXY_BLUETOOTH_NAME "CoxRemote"
#include <StopWatch.h>
TFT_eSPI tft = TFT_eSPI();
Chrono sw;
StopWatch MySW;
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 118 bytes
  { 255,6,0,0,0,111,0,16,31,1,1,0,2,5,19,19,37,24,83,104,
  111,119,32,116,101,120,116,0,1,0,35,5,19,19,78,24,83,104,111,119,
  32,84,101,120,116,0,1,0,2,32,20,20,136,24,83,104,111,119,32,84,
  101,120,116,0,1,0,34,32,21,21,233,24,83,104,111,119,32,84,101,120,
  116,0,1,0,4,62,20,20,193,24,83,104,111,119,32,84,101,120,116,0,
  1,0,35,62,21,21,124,24,83,104,111,119,32,84,101,120,116,0 };
  
struct {

  uint8_t button_0; // =1 if button pressed, else =0 
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t button_4; // =1 if button pressed, else =0 
  uint8_t button_5; // =1 if button pressed, else =0 

  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)
bool runIf = true;
unsigned long stopTime;
unsigned long currentTime;
const unsigned long period = 5;
void delayIsh(){
  stopTime = millis();
  if (currentTime - stopTime >= period){
    tft.drawNumber(MySW.elapsed(),20,0,4);
  }
 
}



void setup() 
{
  RemoteXY_Init (); 
  MySW.setResolution(StopWatch::SECONDS); 
  tft.init();
  tft.fillScreen(TFT_RED);
  tft.setFreeFont(&FreeSansBoldOblique24pt7b);
  MySW.start();
 // sw.start();
}
void printTime(){
  tft.drawFloat(MySW.elapsed(),10,50,4);
  delay(1);
}

void loop() 
{ 
currentTime = MySW.elapsed();
 // delay(0.5);
  RemoteXY_Handler ();
  delayIsh();
 // tft.fillScreen(TFT_RED);
 // MySW.reset();
 // MySW.start();
 // sw.resume();
  //tft.drawString("Text One",10,120,4);
  //tft.drawFloat(sw.elapsed(),10,80,4);
  //printTime();  
 // tft.drawFloat(MySW.elapsed(),10,50,4);
  if (RemoteXY.button_0 == 1){
  //  MySW.start();
   // sw.resume();
  //  tft.drawString("Text One",10,120,4);
 //   tft.drawChar(MySW.elapsed(),0,50,4);
  }
  if (RemoteXY.button_1 == 1){
    tft.drawString("Text Two",10,120,4);
  }
  if (RemoteXY.button_2 == 1){
    tft.drawString("Text Three",10,120,4);
  }
  if (RemoteXY.button_3 == 1){
    tft.drawString("Text Four",10,120,4);
  }
  if (RemoteXY.button_4 == 1){
    tft.drawString("Text Five",10,120,4);
  }    
  if (RemoteXY.button_5 == 1){
    tft.drawString("Text Six",10,120,4);
  }
}