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
#define REMOTEXY_BLUETOOTH_NAME "CoxRemote"

TFT_eSPI tft = TFT_eSPI();

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

void setup() 
{
  RemoteXY_Init (); 
  tft.init();
  tft.fillScreen(TFT_RED);
  tft.setFreeFont(&FreeSansBoldOblique24pt7b);
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  tft.fillScreen(TFT_RED);
  if (RemoteXY.button_0 == 1){
    tft.drawString("Text One",10,120,4);
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