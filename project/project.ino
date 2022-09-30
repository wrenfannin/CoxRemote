// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 94 bytes
  { 255,4,0,0,0,87,0,16,31,1,1,0,3,9,20,20,93,31,70,108,
  97,115,104,32,98,117,105,108,116,32,105,110,32,76,69,68,32,112,105,110,
  0,1,0,39,8,20,20,36,31,101,109,112,116,121,86,97,114,51,0,1,
  0,5,63,20,20,133,31,101,109,112,116,121,86,97,114,49,0,1,0,39,
  61,20,20,6,31,101,109,112,116,121,86,97,114,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t flashLED; // =1 if button pressed, else =0 
  uint8_t emptyVar3; // =1 if button pressed, else =0 
  uint8_t emptyVar1; // =1 if button pressed, else =0 
  uint8_t emptyVar; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_FLASHLED 0


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_FLASHLED, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_FLASHLED, (RemoteXY.flashLED==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}