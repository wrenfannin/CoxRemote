#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();
// const int ledPin =  12;      // the number of the LED pin
// int ledState = LOW;                   // ledState used to set the LED

// // Generally, you should use "unsigned long" for variables that hold time
// // The value will quickly become too large for an int to store

 unsigned long previousMillis = 0;     // will store last time LED was updated

 const long interval = 1000;           // interval at which to blink (milliseconds)

// void setup() {

//   pinMode(ledPin, OUTPUT);
// }

// void loop() {
//   // check to see if it's time to blink the LED; that is, if the difference
//   // between the current time and last time you blinked the LED is bigger than
//   // the interval at which you want to blink the LED.
//   unsigned long currentMillis = millis();

//   if (currentMillis - previousMillis >= interval) {
//     // save the last time you blinked the LED
//     previousMillis = currentMillis;

//     // if the LED is off turn it on and vice-versa:
//     if (ledState == LOW) {
//       ledState = HIGH;
//     } else {
//       ledState = LOW;
//     }

//     // set the LED with the ledState of the variable:
//     digitalWrite(ledPin, ledState);
//   }
// }
#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 28 bytes
  { 255,2,0,0,0,21,0,16,31,1,1,0,23,31,12,12,134,31,0,1,
  0,23,45,12,12,36,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop) 

void setup(){
  tft.init();
  RemoteXY_Init (); 
  tft.fillScreen(TFT_RED);
}


void loop() {
  RemoteXY_Handler (); 
  unsigned long currentMillis = millis();

  if (RemoteXY.button_1 == 1) {

  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    tft.drawString("Text One",10,120,4);
  }
  }

  if (RemoteXY.button_2 == 1) {

  tft.fillScreen(TFT_ORANGE);
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    tft.setTextColor(TFT_BLUE,TFT_GREEN);
    tft.drawString("Text Two",10,10,4);
  }
  }
}