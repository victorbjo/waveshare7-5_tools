// GxEPD_MinimumExample by Jean-Marc Zingg

#include <GxEPD.h>
#include <images.h>
// select the display class to use, only one, copy from GxEPD_Example

#include <GxGDEW075Z08/GxGDEW075Z08.h>    // 7.5" b/w/r 800x480

#include GxEPD_BitmapExamples
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// constructor for AVR Arduino, copy from GxEPD_Example else
GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4

void setup()
{
  display.init();
  display.eraseDisplay();
  // comment out next line to have no or minimal Adafruit_GFX code
  display.drawPaged(drawHelloWorld); // version for AVR using paged drawing, works also on other processors
}

void drawHelloWorld()
{
  display.setTextColor(GxEPD_BLACK);
  display.print("Hello World!");
  display.setTextColor(GxEPD_RED);
  display.print("Hello Ulrich!");
  display.drawPixel(400,50,GxEPD_RED);
  display.drawPixel(400,51,GxEPD_RED);
  display.drawPixel(400,52,GxEPD_RED);
  display.drawPixel(400,53,GxEPD_RED);
  display.drawPixel(400,54,GxEPD_RED);
    display.drawPixel(401,50,GxEPD_RED);
  display.drawPixel(401,51,GxEPD_RED);
  display.drawPixel(401,52,GxEPD_RED);
  display.drawPixel(401,53,GxEPD_RED);
  display.drawPixel(401,54,GxEPD_RED);
  drawCornerTest(100, 100);
}

void loop() {};

void drawCornerTest(int x, int y)
{

  for (int i = 0; i < sizeof(image0)/sizeof(image0[0]); i++){
    for (int j = 0; j < sizeof(image0[0])/sizeof(image0[0][0]); j++){
      switch (image0[i][j]){
        case 1:
          display.drawPixel(i+y,j+x,GxEPD_BLACK);
          break;
        case 2:
          display.drawPixel(i+y,j+x,GxEPD_RED);
          break;
        default:
          display.drawPixel(i+y,j+x,GxEPD_WHITE);
          break;
      }
      }
  }
  display.update();
}
