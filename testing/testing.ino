#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();



void setup() {
  tft.init();
  tft.fillScreen(TFT_RED);
  tft.drawString("12345",10,100,2);

}

void loop() {
  

}
