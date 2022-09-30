/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
// this code runs the ESP8266 as a WiFi access point

// RemoteXY configurate  
#pragma pack(push, 1) // GUI configuration
uint8_t RemoteXY_CONF[] =   // 41 bytes
  { 255,1,0,0,0,34,0,16,31,1,1,0,9,22,45,45,2,31,70,108,
  97,115,104,32,98,117,105,108,116,32,105,110,32,76,69,68,32,112,105,110,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t flashLED; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_FLASHLED 0
// this is the default LED pin on an ESP8266 

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_FLASHLED, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_FLASHLED, (RemoteXY.flashLED==0)?LOW:HIGH); // flashes LED on press of the button
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
